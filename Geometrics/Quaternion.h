/*
 * Copyright 2014 by Jonas Schlagenhauf
 */

#ifndef _QUATERNION
#define _QUATERNION

#include <math.h>
#include "./Vec3.h"

// Quaternion class with common operation methods. Keep in mind that almost all
// methods require a normalized quaternion (unit quaternion) to operate on.
class Quaternion
{
 public:
  float w, x, y, z;
  // Standard constructor for the lazy
  Quaternion() { w = 1; x = 0; y = 0; z = 0; }
  // Direct initialization constructor
  Quaternion(float inW, float inX, float inY, float inZ) : w(inW), x(inX), y(inY), z(inZ) {}
  // Creates a quaternion based on the three euler angles
  Quaternion(float alpha, float beta, float gamma);
  // Creates a quaternion based on the angle around a rotation axis
  template <typename T>
  Quaternion(float angle, Vec3<T> const& axis);
  // Creates a quaternion which represents the rotation between two unit vectors
  template <typename T, typename U>
  Quaternion(Vec3<T> const& v1, Vec3<U> const& v2);

  // Quaternion multiplication. Results in an addition of the underlying
  // rotations
  Quaternion operator*(Quaternion const& rOp) const;
  // Quaternion addition
  Quaternion operator+(Quaternion const& rOP) const;

  // Normalizes the 4 elements
  void normalize();

  // Checks if the quaternion is normalized
  bool isNormalized() const;
  // Angle between this and another quaternion in 4D space (has nothing to do
  // with the rotation represented by the quaternions
  float angle(Quaternion const& toQuat) const;
  // Spherical linear interpolation to a destination quaternion.
  Quaternion slerp(Quaternion const& destQt, float t, float eps = 0.01) const;
  // Linear interpolation to a destination quaternion
  Quaternion lerp(Quaternion const& destQt, float t) const;
  // Packs everything in a byte array. Requires a preallocated byte array of
  // size 16
  void toByteArray(byte* bArray) const;
  // Return the rotation in degrees
  float rotAngleInDeg();
};

Quaternion::Quaternion(float alpha, float beta, float gamma)
{
  float ca = cos(alpha/2);
  float sa = sin(alpha/2);
  float cb = cos(beta/2);
  float sb = sin(beta/2);
  float cg = cos(gamma/2);
  float sg = sin(gamma/2);
  this->w = ca*cb*cg+sa*sb*sg;
  this->x = sa*cb*cg-ca*sb*sg;
  this->y = ca*sb*cg+sa*cb*sg;
  this->z = ca*cb*sg-sa*sb*cg;
}

template <typename T>
Quaternion::Quaternion(float angle, Vec3<T> const& axis)
{
  this->w = cos(angle/2);
  this->x = axis.x * sin(angle/2);
  this->y = axis.y * sin(angle/2);
  this->z = axis.z * sin(angle/2);
}

template <typename T, typename U>
Quaternion::Quaternion(Vec3<T> const& v1, Vec3<U> const& v2)
{
  this->w = sqrt(v1.norm2() * v2.norm2()) + v1.dot(v2);
  Vec3<U> axis = v1.cross(v2);
  this->x = axis.x;
  this->y = axis.y;
  this->z = axis.z;
}

Quaternion Quaternion::operator*(Quaternion const& rOp) const
{
  Quaternion retVal;
  retVal.w = w * rOp.w - x * rOp.x - y * rOp.y - z * rOp.z;
  retVal.x = w * rOp.x + x * rOp.w + y * rOp.z - z * rOp.y;
  retVal.y = w * rOp.y - x * rOp.z + y * rOp.w + z * rOp.x;
  retVal.z = w * rOp.z + x * rOp.y - y * rOp.x + z * rOp.w;
  return retVal;
}

Quaternion Quaternion::operator+(Quaternion const& rOp) const
{
  return Quaternion(w + rOp.w, x + rOp.x, y + rOp.y, z + rOp.z);
}

void Quaternion::normalize()
{
  float norm = sqrt(w*w + x*x + y*y + z*z);
  this->w /= norm;
  this->x /= norm;
  this->y /= norm;
  this->z /= norm;
}

bool Quaternion::isNormalized() const
{
  return w*w + x*x + y*y + z*z == 1;
}

float Quaternion::angle(Quaternion const& toQuat) const
{
  return acos(w*toQuat.w + x*toQuat.x + y*toQuat.y + z*toQuat.z);
}

Quaternion Quaternion::slerp(Quaternion const& destQt, float t, float eps) const
{
  if (t <= 0)
    return *this;
  if (t >= 1)
    return destQt;

  float fac = 1;
  float ang = this->angle(destQt);
  if (abs(ang) < eps)
  {
    return lerp(destQt, t);
  }
  else if (ang < 0)
  {
    ang = -ang;
    fac = -1;
  }

  float fromWgt = sin((1-t) * ang);
  float toWgt = sin(t * ang) * fac;
  float denom = sin(ang);

  Quaternion retVal(
      (this->w * fromWgt + destQt.w * toWgt) / denom,
      (this->x * fromWgt + destQt.x * toWgt) / denom,
      (this->y * fromWgt + destQt.y * toWgt) / denom,
      (this->z * fromWgt + destQt.z * toWgt) / denom);
  return retVal;
}

Quaternion Quaternion::lerp(Quaternion const& destQt, float t) const
{
  Quaternion retVal(
      this->w * (1-t) + destQt.w * t,
      this->x * (1-t) + destQt.x * t,
      this->y * (1-t) + destQt.y * t,
      this->z * (1-t) + destQt.z * t);
  return retVal;
}

void Quaternion::toByteArray(byte* bArray) const
{
  memcpy(bArray, &w, 4);
  memcpy(bArray+4, &x, 4);
  memcpy(bArray+8, &y, 4);
  memcpy(bArray+12, &z, 4);
}

float Quaternion::rotAngleInDeg()
{
  normalize();
  return 2*acos(w) * 180 / PI;
}

#endif  // _QUATERNION
