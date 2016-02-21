/*
    Erstellt: 20.02.2016
    Autor: fh
*/

#include <cmath>

float *vecf(float start, float step, unsigned int count);
unsigned int *veci(unsigned int start, unsigned int count);

class Vec3
{
public:
  float x, y, z;
  Vec3();
  Vec3(float x1, float x2, float x3);
  Vec3 operator*(Vec3 B);
};

class Vec4
{
public:
  float x, y, z, w;
  Vec4();
  Vec4(float x1, float x2, float x3, float x4);
};

class Matrix4
{
public:
  float m11, m12, m13, m14;
  float m21, m22, m23, m24;
  float m31, m32, m33, m34;
  float m41, m42, m43, m44;
  
public:
  Matrix4();
  void zeroMatrix();
  void identity();
  void scale(float s);
  void scale(float x, float y, float z);
  void translate(float x, float y, float z);
  Matrix4 getTrans(float x, float y, float z);
  void rotateX(float phi);
  void rotateY(float phi);
  void rotateZ(float phi);
  Matrix4 getRotX(float phi);
  Matrix4 getRotY(float phi);
  Matrix4 getRotZ(float phi);
  Vec3 getXAxis();
  Vec3 getYAxis();
  Vec3 getZAxis();
  Matrix4 operator*(Matrix4 R);
  void setFrustum(float r, float t, float n, float f);
};
