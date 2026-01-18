#include <math.h>

#include "common.h"

#include "tmb/types.h"

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulVec__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulVec4x4__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulTransVec__FPA3_A3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulTransVecOld__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulTransVec4x4__FPA3_fP8_fvectorT1);

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatricesToRotAxis__FP8_fvectorPA3_fT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatrixToRotAxis__FP8_fvectorPA3_f);

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

// This was likely originally intended to be vectorized or turned into a
// fast `memcpy()`, since it's identical to `mathfCopyMatrixNotAligned()`.
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

void mathfUnitMatrixAsm(FMATRIX result);
INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfUnitMatrixAsm__FPA3_f);

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDist2__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDist3__FP8_fvectorT0);

float mathfDist2Squared(FVECTOR* lhs, FVECTOR* rhs)
{
    float dx = rhs->x - lhs->x;
    float dy = rhs->y - lhs->y;

    return (dx * dx) + (dy * dy);
}

float mathfDist3Squared(FVECTOR* lhs, FVECTOR* rhs)
{
    float dx = rhs->x - lhs->x;
    float dy = rhs->y - lhs->y;
    float dz = rhs->z - lhs->z;

    return (dx * dx) + (dy * dy) + (dz * dz);
}

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfManhatDist__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfManhatDist2D__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRPHFromMatrix__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotationFromPointToPoint__FP8_fvectorT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotationFromVector__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfHeadingFromPointToPoint__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfHeadingFromVector__FP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfPitchFromPointToPoint__FP8_fvectorT0);

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfOrthonormalize__FPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfOrthonormalizeOverTime__FPA3_fPi);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRandInit__Fi);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRandf__Fff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRand__Fii);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRandVector__FP8_fvectorf);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfTransform3dTo2d__FiP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatrixFromCsAndPlane__FPA3_fP3_csP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotAxisToQuaternion__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfAxisAngleToQuaternion__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalizeQuaternion__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalizeQuaternionFromW__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfConcatQuaternions__FP8_fvectorT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDeConcatQuaternions__FP8_fvectorT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfQuaternionToMatrix4x4__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatrixToQuaternion__FP8_fvectorPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfUnitizeQuaternion__FP8_fvectorT0f);
