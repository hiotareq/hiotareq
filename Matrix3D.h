#pragma once
#ifndef Matrix3D_h
#define Matrix3D_h

#include <iostream>
#include "Vector3D.h"

class Matrix3D {
public:
	friend Matrix3D operator*(const int a, const Matrix3D& m3);
	friend std::ostream& operator<<(std::ostream& os, const Matrix3D& m3);
	friend Vector3D operator*(const Vector3D& v3, const   Matrix3D& m3);

	Matrix3D();
	Matrix3D(double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8, double x9);
	~Matrix3D();

	double getValue(int i, int j) const; /* здесь нужно вводить строку и столбец, привычные человеку ,а не компьютеру*/
	void setValue(int i, int j, double value) /* здесь нужно вводить строку и столбец, привычные человеку ,а не компьютеру*/;
	double det();

	Matrix3D operator+(const Matrix3D& m3) const;
	Matrix3D operator-(const Matrix3D& m3) const;
	Matrix3D operator*(const Matrix3D& m3) const;
	Matrix3D operator*(const int a) const;
	Vector3D operator*(const Vector3D& v3) const;
private:
	double field[9];
};

Matrix3D operator*(const int a, const Matrix3D& m3);
std::ostream& operator<<(std::ostream& os, const Matrix3D& m3);
std::istream& operator >> (std::istream& is, Matrix3D& m3);
#endif // !Matrix3D_h