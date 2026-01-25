#include <math.h>

#include "common.h"

#include "tmb/types.h"
#include "tmb/view.h"

void mathfMulVec(FMATRIX mat, FVECTOR* vec, FVECTOR* result)
{
    asm volatile(
        // Load the matrix rows as vectors.
        "lqc2           $vf11, 0x00(%1)         \n\t" // $vf11 = (FVECTOR*) mat[0]
        "lqc2           $vf15, 0x00(%2)         \n\t" // $vf15 = vec
        "lqc2           $vf12, 0x10(%1)         \n\t" // $vf12 = (FVECTOR*) mat[1]
        "lqc2           $vf13, 0x20(%1)         \n\t" // $vf13 = (FVECTOR*) mat[2]

        // Transpose the matrix for the multiply operation.
        // $vf11 = { mat[0].x, mat[1].x, mat[2].x }
        // $vf12 = { mat[0].y, mat[1].y, mat[2].y }
        // $vf13 = { mat[0].z, mat[1].z, mat[2].z }
        "vmove.xyzw     $vf16, $vf11            \n\t" // $vf16 = (FVECTOR*) mat[0]
        "vaddx.z        $vf11, $vf0, $vf13x     \n\t" // $vf11.z = mat[2].x
        "vmove.xyzw     $vf17, $vf12            \n\t" // $vf16 = (FVECTOR*) mat[1]
        "vaddy.z        $vf12, $vf0, $vf13y     \n\t" // $vf12.z = mat[2].y
        "vaddz.x        $vf13, $vf0, $vf16z     \n\t" // $vf13.x = mat[0].z
        "vnop                                   \n\t"
        "vaddx.y        $vf11, $vf0, $vf17x     \n\t" // $vf11.y = mat[1].x
        "vaddy.x        $vf12, $vf0, $vf16y     \n\t" // $vf12.x = mat[0].y
        "vaddz.y        $vf13, $vf0, $vf17z     \n\t" // $vf13.y = mat[1].z
        "vnop                                   \n\t"

        // Perform the matrix multiply.
        // ACC    =       { mat[0].x * vec.x, mat[1].x * vec.x, mat[2].x * vec.x }
        "vmulax.xyz     ACC, $vf11, $vf15x      \n\t"
        // ACC    = ACC + { mat[0].y * vec.y, mat[1].y * vec.y, mat[2].y * vec.y }
        "vmadday.xyz    ACC, $vf12, $vf15y      \n\t"
        // result = ACC + { mat[0].z * vec.z, mat[1].z * vec.z, mat[2].z * vec.z }
        "vmaddz.xyz     $vf16, $vf13, $vf15z    \n\t"
        "sqc2           $vf16, 0x00(%0)         \n\t"

        : "+r"(result)
        : "r"(mat), "r"(vec));
}

void mathfMulVec4x4(FMATRIX mat, FVECTOR* vec, FVECTOR* result)
{
    asm volatile(
        // Load the matrix rows as vectors.
        "lqc2           $vf11, 0x00(%1)         \n\t" // $vf11 = (FVECTOR*) mat[0]
        "lqc2           $vf15, 0x00(%2)         \n\t" // $vf15 = vec
        "lqc2           $vf12, 0x10(%1)         \n\t" // $vf12 = (FVECTOR*) mat[1]
        "lqc2           $vf13, 0x20(%1)         \n\t" // $vf13 = (FVECTOR*) mat[2]
        "lqc2           $vf14, 0x30(%1)         \n\t" // $vf14 = (FVECTOR*) mat[3]

        // Perform all of the multiply ops for each field of the result vector.
        "vmul.xyz       $vf11, $vf11, $vf15     \n\t" // $vf11 = mat[0].xyz * vec.xyz
        "vmul.xyz       $vf12, $vf12, $vf15     \n\t" // $vf12 = mat[1].xyz * vec.xyz
        "vmul.xyz       $vf13, $vf13, $vf15     \n\t" // $vf13 = mat[2].xyz * vec.xyz
        "vmul.xyz       $vf14, $vf14, $vf15     \n\t" // $vf14 = mat[3].xyz * vec.xyz

        // Perform horizontal adds across each vector in order to sum up
        // all of the terms for each field.
        "vaddw.z        $vf11, $vf11, $vf11w    \n\t" // $vf11.z = $vf11.z + $vf11.w
        "vaddx.w        $vf12, $vf12, $vf12x    \n\t" // $vf12.w = $vf12.w + $vf12.x
        "vaddy.x        $vf13, $vf13, $vf13y    \n\t" // $vf13.x = $vf13.x + $vf13.y
        "vaddz.y        $vf14, $vf14, $vf14z    \n\t" // $vf14.y = $vf14.y + $vf14.z

        "vaddz.y        $vf11, $vf11, $vf11z    \n\t" // $vf11.y = $vf11.y + $vf11.z + $vf11.w
        "vaddw.z        $vf12, $vf12, $vf12w    \n\t" // $vf12.z = $vf12.z + $vf12.w + $vf12.x
        "vaddx.w        $vf13, $vf13, $vf13x    \n\t" // $vf13.w = $vf13.w + $vf13.x + $vf13.y
        "vaddy.x        $vf14, $vf14, $vf14y    \n\t" // $vf14.x = $vf14.x + $vf14.y + $vf14.z

        // Finish up the horizontal adds and store them such that
        // `result.x = $vf11.x + $vf11.y + $vf11.z + $vf11.w`,
        // `result.y = $vf12.x + $vf12.y + $vf12.z + $vf12.w`,
        // and so on.
        "vaddy.x        $vf16, $vf11, $vf11y    \n\t"
        "vaddz.y        $vf16, $vf12, $vf12z    \n\t"
        "vaddw.z        $vf16, $vf13, $vf13w    \n\t"
        "vaddx.w        $vf16, $vf14, $vf14x    \n\t"
        "sqc2           $vf16, 0x00(%0)         \n\t"

        : "+r"(result)
        : "r"(mat), "r"(vec));
}

void mathfMulTransVec(FMATRIX* mat, FVECTOR* vec, FVECTOR* result)
{
    asm volatile(
        // Load the matrix rows as vectors. Keep in mind we're using the matrix
        // transpose, so we treat the matrix rows as if they are the columns of
        // the matrix instead.
        "lqc2           $vf11, 0x00(%1)         \n\t" // $vf11 = (FVECTOR*) mat[0]
        "lqc2           $vf15, 0x00(%2)         \n\t" // $vf15 = vec
        "lqc2           $vf12, 0x10(%1)         \n\t" // $vf12 = (FVECTOR*) mat[1]
        "lqc2           $vf13, 0x20(%1)         \n\t" // $vf13 = (FVECTOR*) mat[2]

        // Multiply and add accordingly.
        "vmulax.xyz     ACC, $vf11, $vf15x      \n\t" // $ACC.xyz = mat[0].xyz * vec.x
        "vmadday.xyz    ACC, $vf12, $vf15y      \n\t" // $ACC.xyz += mat[1].xyz * vec.y
        "vmaddz.xyz     $vf16, $vf13, $vf15z    \n\t" // $vf16.xyz = $ACC.xyz + (mat[2].xyz * vec.z)
        "sqc2           $vf16, 0x00(%0)         \n\t" // result = $vf16
        : "+r"(result)
        : "r"(mat), "r"(vec));
}

void mathfMulTransVecOld(FMATRIX* mat, FVECTOR* vec, FVECTOR* result)
{
    asm volatile(
        // Identical to `mathfMulTransVec()`;
        // see that function for documentation.
        "lqc2           $vf11, 0x00(%1)         \n\t"
        "lqc2           $vf15, 0x00(%2)         \n\t"
        "lqc2           $vf12, 0x10(%1)         \n\t"
        "lqc2           $vf13, 0x20(%1)         \n\t"
        "vmulax.xyz     ACC, $vf11, $vf15x      \n\t"
        "vmadday.xyz    ACC, $vf12, $vf15y      \n\t"
        "vmaddz.xyz     $vf16, $vf13, $vf15z    \n\t"
        "sqc2           $vf16, 0x00(%0)         \n\t"
        : "+r"(result)
        : "r"(mat), "r"(vec));
}

void mathfMulTransVec4x4(FMATRIX* mat, FVECTOR* vec, FVECTOR* result)
{
    asm volatile(
        // Load the matrix rows as vectors. Keep in mind we're using the matrix
        // transpose, so we treat the matrix rows as if they are the columns of
        // the matrix instead.
        "lqc2           $vf11, 0x00(%1)         \n\t" // $vf11 = (FVECTOR*) mat[0]
        "lqc2           $vf15, 0x00(%2)         \n\t" // $vf15 = vec
        "lqc2           $vf12, 0x10(%1)         \n\t" // $vf12 = (FVECTOR*) mat[1]
        "lqc2           $vf13, 0x20(%1)         \n\t" // $vf13 = (FVECTOR*) mat[2]
        "lqc2           $vf14, 0x30(%1)         \n\t" // $vf14 = (FVECTOR*) mat[4]

        // Multiply and add accordingly.
        "vmulax.xyzw    ACC, $vf11, $vf15x      \n\t" // $ACC.xyzw =  mat[0].xyzw * vec.x
        "vmadday.xyzw   ACC, $vf12, $vf15y      \n\t" // $ACC.xyzw += mat[1].xyzw * vec.y
        "vmaddaz.xyzw   ACC, $vf13, $vf15z      \n\t" // $ACC.xyzw += mat[2].xyzw * vec.z
        "vmaddw.xyzw    $vf16, $vf14, $vf0w     \n\t"
        // result = $ACC.xyzw + (mat[3].xyzw * vec.w)
        "sqc2           $vf16, 0x00(%0)         \n\t"
        : "+r"(result)
        : "r"(mat), "r"(vec));
}

void mathfMulMatrix(FMATRIX result, FMATRIX lhs, FMATRIX rhs)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y][x] = (lhs[y][0] * rhs[0][x]) + (lhs[y][1] * rhs[1][x])
                + (lhs[y][2] * rhs[2][x]) + (lhs[y][3] * rhs[3][x]);
        }
    }
}

void mathfMulMatrixTP(FMATRIX result, FMATRIX lhs, FMATRIX rhs)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y][x] = (lhs[y][0] * rhs[x][0]) + (lhs[y][1] * rhs[x][1])
                + (lhs[y][2] * rhs[x][2]) + (lhs[y][3] * rhs[x][3]);
        }
    }
}

void mathfMulMatrix3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs)
{
    int y;

    for (y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            result[y][x]
                = (lhs[y][0] * rhs[0][x]) + (lhs[y][1] * rhs[1][x]) + (lhs[y][2] * rhs[2][x]);
        }
    }

    for (y = 0; y < 4; y++) {
        result[y][3] = lhs[y][3];
        result[3][y] = lhs[3][y];
    }
}

void mathfMulMatrixTP3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs)
{
    int y;

    for (y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            result[y][x]
                = (lhs[y][0] * rhs[x][0]) + (lhs[y][1] * rhs[x][1]) + (lhs[y][2] * rhs[x][2]);
        }
    }

    for (y = 0; y < 4; y++) {
        result[y][3] = lhs[y][3];
        result[3][y] = lhs[3][y];
    }
}

void mathfAddMatrix3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs)
{
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            result[y][x] = lhs[y][x] + rhs[y][x];
        }
    }
}

void mathfAddMatrixTP3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs)
{
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            result[y][x] = lhs[y][x] + rhs[x][y];
        }
    }
}

void mathfScaleMatrix3x3(FMATRIX result, FMATRIX mat, float scalar)
{
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            result[y][x] = mat[y][x] * scalar;
        }
    }
}

void mathfCrossProduct(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs)
{
    result->x = lhs->y * rhs->z - lhs->z * rhs->y;
    result->y = lhs->z * rhs->x - lhs->x * rhs->z;
    result->z = lhs->x * rhs->y - lhs->y * rhs->x;
}

float mathfDotProduct(FVECTOR* lhs, FVECTOR* rhs)
{
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z);
}

float mathfPlaneTest(Plane* plane, FVECTOR* dir)
{
    return ((plane->norm.x * dir->x) + (plane->norm.y * dir->y) + (plane->norm.z * dir->z))
        - plane->d;
}

void mathfNormalize(FVECTOR* result, FVECTOR* vec);
INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalize__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalizeColumns__FPA3_f);

void mathfTransposeMatrix(FMATRIX result, FMATRIX mat)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y][x] = mat[x][y];
        }
    }
}

// This function is unused in the NTSC binary, and the algorithm doesn't seem
// to be correct.
void mathfInverseMatrix(FMATRIX result, FMATRIX mat)
{
    for (int i = 0; i < 2; i++) {
        float column_dot
            = (mat[0][i] * mat[0][i]) + (mat[1][i] * mat[1][i]) + (mat[2][i] * mat[2][i]);

        result[i][0] = mat[0][i] / column_dot;
        result[i][1] = mat[1][i] / column_dot;
        result[i][2] = mat[2][i] / column_dot;
        result[i][3]
            = -((mat[0][3] * mat[0][i]) + (mat[1][3] * mat[1][i]) + (mat[2][3] * mat[2][i]))
            / column_dot;
    }

    float tmp = 0.0f;
    result[3][3] = 1.0f;
    result[3][2] = tmp;
    result[3][1] = tmp;
    result[3][0] = tmp;
}

// Given an arbitrary normalized axis `r = (x, y, z)`, generate a rotation matrix
// which will rotate any vector by `r->w` radians across that axis.
void mathfRotAxisToMatrix(FMATRIX result, FVECTOR* r)
{
    float sin_w = sinf(r->w);
    float cos_w = cosf(r->w);

    float one_m_cosine = 1.0f - cos_w;
    float x_term = one_m_cosine * r->x; // (1 - cos(w)) * x
    float y_term = one_m_cosine * r->y; // (1 - cos(w)) * y
    float z_term = one_m_cosine * r->z; // (1 - cos(w)) * z

    // This seems to be derived from "Graphics Gems" (edited by Andrew Glassner)
    // pg. 474. It's presented by Ronald Goldman as the following formula:
    //
    //     `R(r, w) = (cos(w) * I) + tensorproduct( 1 - cos(w) * r, r) + (sin(w) * r_cross)`
    //
    // where `I` is the identity matrix, `r` is the axis unit vector, `w` is the angle
    // of rotation around `r`, and `r_cross` is the vector `r` converted to the skew-symmetric
    // matrix:
    // ```
    // |  0    r.z  -r.y  |
    // | -r.z  0     r.x  |
    // |  r.y -r.x   0    |
    // ```
    result[0][0] = (x_term * r->x) + cos_w;
    result[0][1] = (x_term * r->y) + (r->z * sin_w);
    result[0][2] = (x_term * r->z) - (r->y * sin_w);

    result[1][0] = (y_term * r->x) - (r->z * sin_w);
    result[1][1] = (y_term * r->y) + cos_w;
    result[1][2] = (y_term * r->z) + (r->x * sin_w);

    result[2][0] = (z_term * r->x) + (r->y * sin_w);
    result[2][1] = (z_term * r->y) - (r->x * sin_w);
    result[2][2] = (z_term * r->z) + cos_w;

    // Clean up to ensure the rotation matrix is 3x3.
    result[3][0] = 0.0f;
    result[0][3] = 0.0f;
    result[1][3] = 0.0f;
    result[2][3] = 0.0f;
    result[3][2] = 0.0f;
    result[3][1] = 0.0f;
    result[3][3] = 1.0f;
}

void mathfMatricesToRotAxis(FVECTOR* result, FMATRIX mat1, FMATRIX mat2);
INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatricesToRotAxis__FP8_fvectorPA3_fT1);

void mathfUnitMatrix(FMATRIX result);
void mathfMatrixToRotAxis(FVECTOR* result, FMATRIX mat)
{
    FMATRIX unit;

    mathfUnitMatrix(unit);
    mathfMatricesToRotAxis(result, unit, mat);
}

void mathfAddVector(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs)
{
    result->x = lhs->x + rhs->x;
    result->y = lhs->y + rhs->y;
    result->z = lhs->z + rhs->z;
}

void mathfSubVector(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs)
{
    result->x = lhs->x - rhs->x;
    result->y = lhs->y - rhs->y;
    result->z = lhs->z - rhs->z;
}

void mathfScaleVector(FVECTOR* result, FVECTOR* vec, float scalar)
{
    result->x = vec->x * scalar;
    result->y = vec->y * scalar;
    result->z = vec->z * scalar;
}

void mathfCopyVector(FVECTOR* result, FVECTOR* src)
{
    result->x = src->x;
    result->y = src->y;
    result->z = src->z;
}

void mathfCopyMatrixNotAligned(FMATRIX result, FMATRIX mat)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y][x] = mat[y][x];
        }
    }
}

// Identical to `mathfCopyMatrixNotAligned()`.
// This was likely originally intended to be vectorized or turned into a
// fast `memcpy()`.
void mathfCopyMatrix(FMATRIX result, FMATRIX mat)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y][x] = mat[y][x];
        }
    }
}

// Copies only the 3x3 top-left corner of the matrix.
void mathfCopyMatrixNoTrans(FMATRIX result, FMATRIX mat)
{
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            result[y][x] = mat[y][x];
        }
    }
}

void mathfUnitMatrix(FMATRIX result)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y][x] = y == x ? 1.0f : 0.0f;
        }
    }
}

void mathfUnitMatrixAsm(FMATRIX result)
{
    asm volatile(
        // Start with the unit vector.
        "qmfc2.i        $2, $vf0               \n\t" // $v0 = { 0.0f, 0.0f, 0.0f, 1.0f }

        // Rotate it to the right (bitwise) by one 32-bit word.
        // Keep in mind that a vector is stored in bits as:
        //   { x = 0:31, y = 32:63, z = 64:95, w = 96:127 }
        // So rotating to the right by 1 swizzles `xyzw` -> `yzwx`.
        "vmr32.xyzw     $vf11, $vf0            \n\t"
        "qmfc2.i        $3, $vf11              \n\t" // $v1 = { 0.0f, 0.0f, 1.0f, 0.0f }

        // Keep rotating the same vector to give us the unix matrix pieces.
        "prot3w         $4, $3                 \n\t" // $a0 = { 0.0f, 1.0f, 0.0f, 0.0f }
        "prot3w         $5, $4                 \n\t" // $a1 = { 1.0f, 0.0f, 0.0f, 0.0f }

        // Store the unit matrix.
        "sq             $2, 0x30(%0)           \n\t" // result[3] = { 0.0f, 0.0f, 0.0f, 1.0f }
        "sq             $3, 0x20(%0)           \n\t" // result[2] = { 0.0f, 0.0f, 1.0f, 0.0f }
        "sq             $4, 0x10(%0)           \n\t" // result[1] = { 0.0f, 1.0f, 0.0f, 0.0f }
        "sq             $5, 0x00(%0)           \n\t" // result[0] = { 1.0f, 0.0f, 0.0f, 0.0f }
        : "+r"(result)
        :
        // $6 ($a2) isn't used at all, but clobbering it is required to match.
        // Incog might have used it when first writing the code, then optimized
        // so that it was no longer necessary.
        : "$2", "$3", "$4", "$5", "$6", "memory");
}

// TODO: Come back and comment on these once we know how TMB orients vectors
// in world space. Also make sure the variable names are actually correct.
void mathfRotMatrixH(FMATRIX result, float head)
{
    mathfUnitMatrixAsm(result);

    float sin_head = sinf(head);
    float cos_head = cosf(head);

    result[0][0] = cos_head;
    result[0][1] = -sin_head;
    result[1][0] = sin_head;
    result[1][1] = cos_head;
}

void mathfRotMatrixPH(FMATRIX result, FVECTOR* angle)
{
    mathfUnitMatrixAsm(result);

    float sin_head = sinf(angle->z);
    float cos_head = cosf(angle->z);
    float sin_pitch = sinf(angle->x);
    float cos_pitch = cosf(angle->x);

    result[0][0] = cos_head;
    result[0][1] = -sin_head;

    result[1][0] = cos_pitch * sin_head;
    result[1][1] = cos_pitch * cos_head;
    result[1][2] = sin_pitch;

    result[2][0] = -(sin_pitch * sin_head);
    result[2][1] = -(sin_pitch * cos_head);
    result[2][2] = cos_pitch;
}

void mathfRotMatrixRPH(FMATRIX result, FVECTOR* angle)
{
    float sin_head = sinf(angle->z);
    float cos_head = cosf(angle->z);
    float sin_roll = sinf(angle->x);
    float cos_roll = cosf(angle->x);
    float sin_pitch = sinf(angle->y);
    float cos_pitch = cosf(angle->y);

    result[0][0] = cos_pitch * cos_head + sin_pitch * sin_roll * sin_head;
    result[0][1] = -cos_pitch * sin_head + sin_pitch * sin_roll * cos_head;
    result[0][2] = -sin_pitch * cos_roll;

    result[1][0] = cos_roll * sin_head;
    result[1][1] = cos_roll * cos_head;
    result[1][2] = sin_roll;

    result[2][0] = sin_pitch * cos_head - cos_pitch * sin_roll * sin_head;
    result[2][1] = -sin_pitch * sin_head - cos_pitch * sin_roll * cos_head;
    result[2][2] = cos_pitch * cos_roll;

    for (int i = 0; i < 4; i++) {
        result[i][3] = 0.0f;
        result[3][i] = 0.0f;
    }
    result[3][3] = 1.0f;
}

void mathfRotMatrixPRH(FMATRIX result, FVECTOR* angle)
{
    float sin_head = sinf(angle->z);
    float cos_head = cosf(angle->z);
    float sin_pitch = sinf(angle->x);
    float cos_pitch = cosf(angle->x);
    float sin_roll = sinf(angle->y);
    float cos_roll = cosf(angle->y);

    result[0][0] = cos_roll * cos_head;
    result[0][1] = -cos_roll * sin_head;
    result[0][2] = sin_roll;

    result[1][0] = sin_pitch * sin_roll * cos_head + cos_pitch * sin_head;
    result[1][1] = -sin_pitch * sin_roll * sin_head + cos_pitch * cos_head;
    result[1][2] = -sin_pitch * cos_roll;

    result[2][0] = -cos_pitch * sin_roll * cos_head + sin_pitch * sin_head;
    result[2][1] = cos_pitch * sin_roll * sin_head + sin_pitch * cos_head;
    result[2][2] = cos_pitch * cos_roll;

    for (int i = 0; i < 4; i++) {
        result[i][3] = 0.0f;
        result[3][i] = 0.0f;
    }
    result[3][3] = 1.0f;
}

// Creates a rotation matrix from the given angles without modifying row or column 4.
void mathfRotMatrixRPHNoTrans(FMATRIX result, FVECTOR* angle)
{
    float sin_head = sinf(angle->z);
    float cos_head = cosf(angle->z);
    float sin_roll = sinf(angle->x);
    float cos_roll = cosf(angle->x);
    float sin_pitch = sinf(angle->y);
    float cos_pitch = cosf(angle->y);

    result[0][0] = cos_pitch * cos_head + sin_pitch * sin_roll * sin_head;
    result[0][1] = -cos_pitch * sin_head + sin_pitch * sin_roll * cos_head;
    result[0][2] = -sin_pitch * cos_roll;

    result[1][0] = cos_roll * sin_head;
    result[1][1] = cos_roll * cos_head;
    result[1][2] = sin_roll;

    result[2][0] = sin_pitch * cos_head - cos_pitch * sin_roll * sin_head;
    result[2][1] = -sin_pitch * sin_head - cos_pitch * sin_roll * cos_head;
    result[2][2] = cos_pitch * cos_roll;
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfHPtoVector__FP8_fvectorff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfViewScreenMatrix__FPA3_fT0T0fffffffffff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDumpMatrix__FPA3_f);

float mathfDist2(FVECTOR* origin, FVECTOR* dst)
{
    if (dst == NULL) {
        // Assume `origin` is a ray.
        return sqrtf(origin->x * origin->x + origin->y * origin->y);
    }

    float dx = (dst->x - origin->x);
    float dy = (dst->y - origin->y);
    return sqrtf(dx * dx + dy * dy);
}

float mathfDist3(FVECTOR* origin, FVECTOR* dst)
{
    if (dst == NULL) {
        // Assume `origin` is a ray.
        return sqrtf(origin->x * origin->x + origin->y * origin->y + origin->z * origin->z);
    }

    float dx = (dst->x - origin->x);
    float dy = (dst->y - origin->y);
    float dz = (dst->z - origin->z);
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

float mathfDist2Squared(FVECTOR* origin, FVECTOR* dst)
{
    float dx = dst->x - origin->x;
    float dy = dst->y - origin->y;

    return (dx * dx) + (dy * dy);
}

float mathfDist3Squared(FVECTOR* origin, FVECTOR* dst)
{
    float dx = dst->x - origin->x;
    float dy = dst->y - origin->y;
    float dz = dst->z - origin->z;

    return (dx * dx) + (dy * dy) + (dz * dz);
}

float mathfManhatDist(FVECTOR* origin, FVECTOR* dst)
{
    float max, med, min;

    if (dst == NULL) {
        // Assume `origin` is a ray.
        max = fabsf(origin->x);
        med = fabsf(origin->y);
        min = fabsf(origin->z);
    } else {
        // Assume `origin` is a point.
        max = fabsf(dst->x - origin->x);
        med = fabsf(dst->y - origin->y);
        min = fabsf(dst->z - origin->z);
    }

    // The Manhattan distance method here is described by Jack Ritter as
    // `A Fast Approximation To 3D Euclidean Distance` on pg. 432 of "Graphics Gems"
    // (edited by Andrew Glassner).
    //
    // `dx, dy, dz` are sorted by their absolute quantity, then plugged into the formula:
    //    `max + ((11/32) * med) + ((1/4) * min)`
    // According to Ritter, this has an error of +-8% vs. the true Euclidean distance.
    float temp;
    if (max < med) {
        temp = max;
        max = med;
        med = temp;
    }
    if (max < min) {
        temp = max;
        max = min;
        min = temp;
    }
    if (med < min) {
        temp = med;
        med = min;
        min = temp;
    }
    return max + (med * 0.34375f) + (min * 0.25f);
}

float mathfManhatDist2D(FVECTOR* origin, FVECTOR* dst)
{
    float max, min;

    if (dst == NULL) {
        // Assume `origin` is a ray.
        max = fabsf(origin->x);
        min = fabsf(origin->y);
    } else {
        // Assume `origin` is a point.
        max = fabsf(dst->x - origin->x);
        min = fabsf(dst->y - origin->y);
    }

    // See `mathfManhatDist()` for more information about the algorithm here.
    // This is just a 2D simplification.
    float temp;
    if (max < min) {
        temp = max;
        max = min;
        min = temp;
    }
    return max + (min * 0.34375f);
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRPHFromMatrix__FPA3_fP8_fvector);

void mathfRotationFromVector(FVECTOR* result, FVECTOR* point);
void mathfRotationFromPointToPoint(FVECTOR* result, FVECTOR* p1, FVECTOR* p2)
{
    FVECTOR diff;

    mathfSubVector(&diff, p2, p1);
    mathfRotationFromVector(result, &diff);
}

void mathfRotationFromVector(FVECTOR* result, FVECTOR* vec)
{
    result->x = atan2f(vec->z, sqrtf(vec->x * vec->x + vec->y * vec->y));
    result->y = 0.0f;
    result->z = atan2f(vec->x, vec->y);
}

float mathfHeadingFromVector(FVECTOR* vec);
float mathfHeadingFromPointToPoint(FVECTOR* p1, FVECTOR* p2)
{
    FVECTOR diff;

    if (p2 != NULL) {
        mathfSubVector(&diff, p2, p1);
    } else {
        mathfCopyVector(&diff, p1);
    }

    return mathfHeadingFromVector(&diff);
}

float mathfHeadingFromVector(FVECTOR* vec)
{
    return atan2f(vec->x, vec->y);
}

float mathfPitchFromVector(FVECTOR* vec);
float mathfPitchFromPointToPoint(FVECTOR* p1, FVECTOR* p2)
{
    FVECTOR diff;

    mathfSubVector(&diff, p2, p1);
    return mathfPitchFromVector(&diff);
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfPitchFromVector__FP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatrixFromNormal__FPA3_fP8_fvector);

void mathfSetFVector(FVECTOR* result, float x, float y, float z)
{
    result->x = x;
    result->y = y;
    result->z = z;
}

void mathfSetFVector(FVECTOR* result, float x, float y, float z, float w)
{
    result->x = x;
    result->y = y;
    result->z = z;
    result->w = w;
}

void mathfOrthonormalize(FMATRIX mat)
{
    FVECTOR* r0 = (FVECTOR*)mat[0];
    FVECTOR* r1 = (FVECTOR*)mat[1];
    FVECTOR* r2 = (FVECTOR*)mat[2];

    mathfCrossProduct(r0, r1, r2);
    mathfNormalize(r0, r0);
    mathfCrossProduct(r1, r2, r0);
    mathfNormalize(r1, r1);
    mathfCrossProduct(r2, r0, r1);
    mathfNormalize(r2, r2);
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfOrthonormalizeOverTime__FPA3_fPi);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRandInit__Fi);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRandf__Fff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRand__Fii);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRandVector__FP8_fvectorf);

void mathfTransform3dTo2d(int view, FVECTOR* vec, FVECTOR* result)
{
    FVECTOR* trans = viewGetWeTrans(view);
    FMATRIX* screen_mat = viewGetWorldToScreenMat(view);

    if (vec == NULL || result == NULL) {
        return;
    }

    FVECTOR translated, transformed;
    translated.x = vec->x + trans->x;
    translated.y = vec->y + trans->y;
    translated.z = vec->z + trans->z;
    translated.w = 1.0f;

    mathfMulVec4x4(*screen_mat, &translated, &transformed);

    float mag = 1.0f / transformed.w;
    result->x = transformed.x * mag;
    result->y = transformed.y * mag;
    result->z = transformed.w;
    result->w = transformed.z * mag;
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatrixFromCsAndPlane__FPA3_fP3_csP8_fvector);

void mathfRotAxisToQuaternion(FVECTOR* result, FVECTOR* axis)
{
    float sine = sinf(axis->w * 0.5f);
    result->x = sine * axis->x;
    result->y = sine * axis->y;
    result->z = sine * axis->z;
    result->w = cosf(axis->w * 0.5f);
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfAxisAngleToQuaternion__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalizeQuaternion__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalizeQuaternionFromW__FP8_fvectorT0);

void mathfConcatQuaternions(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs)
{
    FVECTOR3 concat;

    concat.x = (rhs->w * lhs->x + rhs->x * lhs->w + rhs->y * lhs->z);
    concat.x -= (rhs->z * lhs->y);

    concat.y = (rhs->w * lhs->y + rhs->y * lhs->w + rhs->z * lhs->x);
    concat.y -= (rhs->x * lhs->z);

    concat.z = (rhs->w * lhs->z + rhs->z * lhs->w + rhs->x * lhs->y);
    concat.z -= (rhs->y * lhs->x);

    float concat_w = (rhs->w * lhs->w - rhs->x * lhs->x) - (rhs->y * lhs->y);
    concat_w -= (rhs->z * lhs->z);

    result->x = concat.x;
    result->y = concat.y;
    result->z = concat.z;
    result->w = concat_w;
}

void mathfQuaternionToMatrix4x4(FMATRIX result, FVECTOR* quat);

void mathfDeConcatQuaternions(FVECTOR* result, FVECTOR* q1, FVECTOR* q2)
{
    FMATRIX q1_mat, q2_mat;
    FVECTOR rot;

    mathfQuaternionToMatrix4x4(q1_mat, q1);
    mathfQuaternionToMatrix4x4(q2_mat, q2);
    mathfMatricesToRotAxis(&rot, q1_mat, q2_mat);
    mathfRotAxisToQuaternion(result, &rot);
}

void mathfQuaternionToMatrix4x4(FMATRIX result, FVECTOR* quat)
{
    float xx = quat->x * quat->x;
    float yy = quat->y * quat->y;
    float zz = quat->z * quat->z;

    float xy = quat->x * quat->y;
    float xz = quat->x * quat->z;
    float yz = quat->y * quat->z;
    float xw = quat->x * quat->w;
    float yw = quat->y * quat->w;
    float zw = quat->z * quat->w;

    result[0][0] = 1.0f - (2.0f * (yy + zz));
    result[0][1] = 2.0f * (xy + zw);
    result[0][2] = 2.0f * (xz - yw);

    result[1][0] = 2.0f * (xy - zw);
    result[1][1] = 1.0f - (2.0f * (xx + zz));
    result[1][2] = 2.0f * (yz + xw);

    result[2][0] = 2.0f * (xz + yw);
    result[2][1] = 2.0f * (yz - xw);
    result[2][2] = 1.0f - (2.0f * (xx + yy));

    result[0][3] = 0.0f;
    result[1][3] = 0.0f;
    result[2][3] = 0.0f;
    result[3][0] = 0.0f;
    result[3][1] = 0.0f;
    result[3][2] = 0.0f;
    result[3][3] = 1.0f;
}

void mathfMatrixToQuaternion(FVECTOR* result, FMATRIX mat)
{
    FVECTOR axis;

    mathfMatrixToRotAxis(&axis, mat);
    mathfRotAxisToQuaternion(result, &axis);
}

void mathfUnitizeQuaternion(FVECTOR* result, FVECTOR* quat, float mag)
{
    result->x = quat->x * mag;
    result->y = quat->y * mag;
    result->z = quat->z * mag;

    float norm
        = sqrtf(1.0f - (result->x * result->x + result->y * result->y + result->z * result->z));

    if (quat->w > 0.0f) {
        result->w = norm;
    } else {
        result->w = -norm;
    }
}
