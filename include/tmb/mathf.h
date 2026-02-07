#ifndef _TMB_MATHF_H_
#define _TMB_MATHF_H_

#include "tmb/hier.h"
#include "tmb/types.h"

// -----------------------------------------------------------
// Basic Vector Operations
// -----------------------------------------------------------

void mathfAddVector(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs);
void mathfSubVector(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs);
void mathfScaleVector(FVECTOR* result, FVECTOR* vec, float scalar);
void mathfCopyVector(FVECTOR* result, FVECTOR* src);
void mathfSetFVector(FVECTOR* result, float x, float y, float z);
void mathfSetFVector(FVECTOR* result, float x, float y, float z, float w);
void mathfCrossProduct(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs);
float mathfDotProduct(FVECTOR* lhs, FVECTOR* rhs);
float mathfNormalize(FVECTOR* result, FVECTOR* vec);
float mathfPlaneTest(Plane* plane, FVECTOR* dir);

// -----------------------------------------------------------
// Distance Algorithms
// -----------------------------------------------------------

float mathfDist2(FVECTOR* origin, FVECTOR* dst);
float mathfDist3(FVECTOR* origin, FVECTOR* dst);
float mathfDist2Squared(FVECTOR* origin, FVECTOR* dst);
float mathfDist3Squared(FVECTOR* origin, FVECTOR* dst);
float mathfManhatDist(FVECTOR* origin, FVECTOR* dst);
float mathfManhatDist2D(FVECTOR* origin, FVECTOR* dst);

// -----------------------------------------------------------
// Vector Rotation
// -----------------------------------------------------------

void mathfHPtoVector(FVECTOR* result, float head, float pitch);
void mathfRPHFromMatrix(FMATRIX mat, FVECTOR* result);
void mathfRotationFromVector(FVECTOR* result, FVECTOR* vec);
float mathfHeadingFromVector(FVECTOR* vec);
float mathfPitchFromVector(FVECTOR* vec);
void mathfRotationFromPointToPoint(FVECTOR* result, FVECTOR* p1, FVECTOR* p2);
float mathfHeadingFromPointToPoint(FVECTOR* p1, FVECTOR* p2);
float mathfPitchFromPointToPoint(FVECTOR* p1, FVECTOR* p2);

// -----------------------------------------------------------
// Basic Matrix Operations
// -----------------------------------------------------------

void mathfCopyMatrix(FMATRIX result, FMATRIX mat);
void mathfCopyMatrixNotAligned(FMATRIX result, FMATRIX mat);
void mathfCopyMatrixNoTrans(FMATRIX result, FMATRIX mat);
void mathfUnitMatrix(FMATRIX result);
void mathfUnitMatrixAsm(FMATRIX result);
void mathfAddMatrix3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs);
void mathfAddMatrixTP3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs);
void mathfScaleMatrix3x3(FMATRIX result, FMATRIX mat, float scalar);
void mathfNormalizeColumns(FMATRIX mat);
void mathfTransposeMatrix(FMATRIX result, FMATRIX mat);

// -----------------------------------------------------------
// (Matrix * Vector) Multiplication
// -----------------------------------------------------------

void mathfMulVec(FMATRIX mat, FVECTOR* vec, FVECTOR* result);
void mathfMulVec4x4(FMATRIX mat, FVECTOR* vec, FVECTOR* result);
void mathfMulTransVec(FMATRIX* mat, FVECTOR* vec, FVECTOR* result);
void mathfMulTransVec4x4(FMATRIX* mat, FVECTOR* vec, FVECTOR* result);

// -----------------------------------------------------------
// (Matrix * Matrix) Multiplication
// -----------------------------------------------------------

void mathfMulMatrix(FMATRIX result, FMATRIX lhs, FMATRIX rhs);
void mathfMulMatrixTP(FMATRIX result, FMATRIX lhs, FMATRIX rhs);
void mathfMulMatrix3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs);
void mathfMulMatrixTP3x3(FMATRIX result, FMATRIX lhs, FMATRIX rhs);

// -----------------------------------------------------------
// Rotation Matrices
// -----------------------------------------------------------

void mathfRotMatrixH(FMATRIX result, float head);
void mathfRotMatrixPH(FMATRIX result, FVECTOR* angle);
void mathfRotMatrixRPH(FMATRIX result, FVECTOR* angle);
void mathfRotMatrixPRH(FMATRIX result, FVECTOR* angle);
void mathfRotMatrixRPHNoTrans(FMATRIX result, FVECTOR* angle);

// -----------------------------------------------------------
// Matrix Conversions and Transformations
// -----------------------------------------------------------

void mathfRotAxisToMatrix(FMATRIX result, FVECTOR* r);
void mathfMatricesToRotAxis(FVECTOR* result, FMATRIX mat1, FMATRIX mat2);
void mathfMatrixFromNormal(FMATRIX result, FVECTOR* normal);
void mathfMatrixFromCsAndPlane(FMATRIX result, CS* cs, FVECTOR* plane);
void mathfTransform3dTo2d(int view, FVECTOR* vec, FVECTOR* result);

// -----------------------------------------------------------
// Orthonormalization
// -----------------------------------------------------------

void mathfOrthonormalize(FMATRIX mat);
void mathfOrthonormalizeOverTime(FMATRIX mat, int* time);

// -----------------------------------------------------------
// Random Number Generation
// -----------------------------------------------------------

void mathfRandInit(int seed);
float mathfRandf(float lower, float upper);
int mathfRand(int lower, int upper);
void mathfRandVector(FVECTOR* result, float unk);

// -----------------------------------------------------------
// Quaternions
// -----------------------------------------------------------

void mathfMatrixToQuaternion(FVECTOR* result, FMATRIX mat);
void mathfRotAxisToQuaternion(FVECTOR* result, FVECTOR* axis);
void mathfAxisAngleToQuaternion(FVECTOR* result, FVECTOR* axis);
void mathfQuaternionToMatrix4x4(FMATRIX result, FVECTOR* quat);
void mathfUnitizeQuaternion(FVECTOR* result, FVECTOR* quat, float mag);
void mathfNormalizeQuaternion(FVECTOR* result, FVECTOR* quat);
void mathfNormalizeQuaternionFromW(FVECTOR* result, FVECTOR* quat);
void mathfConcatQuaternions(FVECTOR* result, FVECTOR* lhs, FVECTOR* rhs);
void mathfDeConcatQuaternions(FVECTOR* result, FVECTOR* q1, FVECTOR* q2);

// -----------------------------------------------------------
// Misc. Operations
// -----------------------------------------------------------

void mathfViewScreenMatrix(FMATRIX screen, FMATRIX clip, FMATRIX fov, float vp_dist, float x_aspect,
    float y_aspect, float center_x, float center_y, float unk_min1, float unk_max1, float near,
    float far, float screen_width, float screen_height);
void mathfDumpMatrix(FMATRIX mat);

#endif // _TMB_MATHF_H_
