#include "common.h"

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfCrossProduct__FP8_fvectorT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfDotProduct__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfPlaneTest__FP6_planeP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalize__FP8_fvectorT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfNormalizeColumns__FPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfTransposeMatrix__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfInverseMatrix__FPA3_fT0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfRotAxisToMatrix__FPA3_fP8_fvector);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatricesToRotAxis__FP8_fvectorPA3_fT1);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfMatrixToRotAxis__FP8_fvectorPA3_f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfAddVector__FP8_fvectorT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfSubVector__FP8_fvectorT0T0);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfScaleVector__FP8_fvectorT0f);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfCopyVector__FP8_fvectorT0);

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

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfSetFVector__FP8_fvectorfff);

INCLUDE_ASM("asm/nonmatchings/tmb/mathf", mathfSetFVector__FP8_fvectorffff);

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
