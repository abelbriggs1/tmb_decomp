#include "common.h"

#include "tmb/types.h"

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulVec__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulVec4x4__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulTransVec__FPA3_A3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulTransVecOld__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulTransVec4x4__FPA3_fP8_fvectorT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulMatrix__FPA3_fT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulMatrixTP__FPA3_fT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulMatrix3x3__FPA3_fT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMulMatrixTP3x3__FPA3_fT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfAddMatrix3x3__FPA3_fT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfAddMatrixTP3x3__FPA3_fT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfScaleMatrix3x3__FPA3_fT0f);

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfTransposeMatrix__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfInverseMatrix__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotAxisToMatrix__FPA3_fP8_fvector);

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfCopyMatrixNotAligned__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfCopyMatrix__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfCopyMatrixNoTrans__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfUnitMatrix__FPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfUnitMatrixAsm__FPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotMatrixH__FPA3_ff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotMatrixPH__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotMatrixRPH__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotMatrixPRH__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotMatrixRPHNoTrans__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfHPtoVector__FP8_fvectorff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfViewScreenMatrix__FPA3_fT0T0fffffffffff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDumpMatrix__FPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDist2__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDist3__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDist2Squared__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDist3Squared__FP8_fvectorT0);

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
