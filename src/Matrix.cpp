/*
    Erstellt: 20.02.2016
    Autor: fh
*/

#include <cstdlib>
#include "Matrix.hpp"

float *vecf(float start, float step, unsigned int count)
{
	unsigned int i;
	float *out = (float*)malloc(count*sizeof(float));
	
	for (i=0;i<count;i++) out[i] = start + i*step;

	return out;
}

unsigned int *veci(unsigned int start, unsigned int count)
{
	unsigned int i;
	unsigned int *out = (unsigned int*)malloc(count*sizeof(unsigned int));
	
	for (i=0;i<count;i++) out[i] = start + i;

	return out;
}

Vec3::Vec3()
{
  x=0.0f; y=0.0f; z=0.0f;
}


Vec3::Vec3(float x1, float x2, float x3)
{
  x=x1; y=x2; z=x3;
}

Vec3 Vec3::operator*(Vec3 B)
{
  float *a=(float*)this;
  float *b=(float*)&B;

  return Vec3(a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]);
}


Vec4::Vec4()
{
  x=1.0f; y=1.0f; z=1.0f; w=1.0f;
}


Vec4::Vec4(float x1, float x2, float x3, float x4)
{
  x=x1; y=x2; z=x3; w=x4;
}


Matrix4::Matrix4()
{
  identity();
}


void Matrix4::zeroMatrix()
{
  m11=0.0f; m12=0.0f; m13=0.0f; m14=0.0f;
  m21=0.0f; m22=0.0f; m23=0.0f; m24=0.0f;
  m31=0.0f; m32=0.0f; m33=0.0f; m34=0.0f;
  m41=0.0f; m42=0.0f; m43=0.0f; m44=0.0f;
}

void Matrix4::identity()
{
  zeroMatrix();
  m11 = 1.0f;
  m22 = 1.0f;
  m33 = 1.0f;
  m44 = 1.0f;	
}

void Matrix4::scale(float s)
{
  m11 *= s;
  m22 *= s;
  m33 *= s;
}


void Matrix4::scale(float x, float y, float z)
{
  m11 *= x;
  m22 *= y;
  m33 *= z;
}

void Matrix4::translate(float x, float y, float z)
{
  m14 += x;
  m24 += y;
  m34 += z;
}

Matrix4 Matrix4::getTrans(float x, float y, float z)
{
  Matrix4 T;
  T.m14 = x;
  T.m24 = y;
  T.m34 = z;
  return T;
}


void Matrix4::rotateX(float phi)
{
  Matrix4 X;
  Matrix4 R = *this;
  X.m22 = cos(phi);	X.m23 = sin(phi);
  X.m32 = -sin(phi);	X.m33 = cos(phi);
  *this = X*R;
}

void Matrix4::rotateY(float phi)
{
  Matrix4 Y;
  Matrix4 R = *this;
  Y.m11 = cos(phi);	Y.m13 = sin(phi);
  Y.m31 = -sin(phi);	Y.m33 = cos(phi);
  *this = Y*R;
}

void Matrix4::rotateZ(float phi)
{
  Matrix4 Z;
  Matrix4 R = *this;
  Z.m11 = cos(phi);	Z.m12 = sin(phi);
  Z.m21 = -sin(phi);	Z.m22 = cos(phi);
  *this = Z*R;
}

Matrix4 Matrix4::getRotX(float phi)
{
  Matrix4 X;
  X.m22 = cos(phi);	X.m23 = sin(phi);
  X.m32 = -sin(phi);	X.m33 = cos(phi);
  return X;
}

Matrix4 Matrix4::getRotY(float phi)
{
  Matrix4 Y;
  Y.m11 = cos(phi);	Y.m13 = sin(phi);
  Y.m31 = -sin(phi);	Y.m33 = cos(phi);
  return Y;
}

Matrix4 Matrix4::getRotZ(float phi)
{
  Matrix4 Z;
  Z.m11 = cos(phi);	Z.m12 = sin(phi);
  Z.m21 = -sin(phi);	Z.m22 = cos(phi);
  return Z;
}

Vec3 Matrix4::getXAxis()
{
	return Vec3(m11, m21, m31);
}

Vec3 Matrix4::getYAxis()
{
	return Vec3(m12, m22, m32);
}

Vec3 Matrix4::getZAxis()
{
	return Vec3(m13, m23, m33);
}

Matrix4 Matrix4::operator*(Matrix4 R)
{
  Matrix4 M;
  float *m = (float*)&M;
  float *r = (float*)&R;
  float *l = (float*)this;
  unsigned int i,j;
  
  for (j=0;j<4;j++)
	  for (i=0;i<4;i++)
		  m[4*j+i] = l[4*j]*r[i] + l[4*j+1]*r[i+4] + l[4*j+2]*r[i+8] + l[4*j+3]*r[i+12];

  return M;
}

void Matrix4::setFrustum(float r, float t, float n, float f)
{
	m11=n/r;	m12=0;		m13=0;			m14=0;
	m21=0;		m22=n/t;	m23=0;			m24=0;
	m31=0;		m32=0;		m33=-(f+n)/(f-n);	m34=-2*f*n/(f-n);
	m41=0;		m42=0;		m43=-1;			m44=0;
}
