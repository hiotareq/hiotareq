#include "Matrix3D.h"

Matrix3D::Matrix3D(double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8, double x9) {
	field[0] = x1;
	field[1] = x2;
	field[2] = x3;
	field[3] = x4;
	field[4] = x5;
	field[5] = x6;
	field[6] = x7;
	field[7] = x8;
	field[8] = x9;
}
Matrix3D::Matrix3D() {
	for (int i = 0; i < 9; i++) this->field[i] = 0;
}
Matrix3D:: ~Matrix3D() {};

double Matrix3D:: getValue(int i, int j) const {
	return field[(i - 1) * 3 + j - 1];
}
void Matrix3D::setValue(int i, int j, double value) {
	field[(i - 1) * 3 + j - 1] = value;
}
double Matrix3D::det() {
	double det;
	det = (field[0] * (field[4] * field[8] - field[5] * field[7]) - field[1] * (field[3] * field[8] - field[5] * field[6]) + field[2] * (field[3] * field[7] - field[4] * field[6]));
	return det;
}

Matrix3D Matrix3D:: operator+(const Matrix3D& m3) const {
	double terra[9];
	for (int i = 0; i < 9; i++)
	{
		terra[i] = field[i] + m3.field[i];
	}
	return Matrix3D(terra[0], terra[1], terra[2], terra[3], terra[4], terra[5], terra[6], terra[7], terra[8]);
}
Matrix3D Matrix3D:: operator-(const Matrix3D& m3) const {
	double terra[9];
	for (int i = 0; i < 9; i++)
	{
		terra[i] = field[i] - m3.field[i];
	}
	return Matrix3D(terra[0], terra[1], terra[2], terra[3], terra[4], terra[5], terra[6], terra[7], terra[8]);
}
Matrix3D Matrix3D::  operator*(const Matrix3D& m3) const {
	double terra[9];
	terra[0] = field[0] * m3.field[0] + field[1] * m3.field[3] + field[2] * m3.field[6];
	terra[1] = field[0] * m3.field[1] + field[1] * m3.field[4] + field[2] * m3.field[7];
	terra[2] = field[0] * m3.field[2] + field[1] * m3.field[5] + field[2] * m3.field[8];
	terra[3] = field[3] * m3.field[0] + field[4] * m3.field[3] + field[5] * m3.field[6];
	terra[4] = field[3] * m3.field[1] + field[4] * m3.field[4] + field[5] * m3.field[7];
	terra[5] = field[3] * m3.field[2] + field[4] * m3.field[5] + field[5] * m3.field[8];
	terra[6] = field[6] * m3.field[0] + field[7] * m3.field[3] + field[8] * m3.field[6];
	terra[7] = field[6] * m3.field[1] + field[7] * m3.field[4] + field[8] * m3.field[7];
	terra[8] = field[6] * m3.field[2] + field[7] * m3.field[5] + field[8] * m3.field[8];
	return Matrix3D(terra[0], terra[1], terra[2], terra[3], terra[4], terra[5], terra[6], terra[7], terra[8]);
}
Matrix3D Matrix3D:: operator*(const int a) const {
	return Matrix3D((field[0]) * a, (field[1]) * a, (field[2]) * a, (field[3]) * a, (field[4]) * a, (field[5]) * a, (field[6]) * a, (field[7]) * a, (field[8]) * a);
}
Vector3D Matrix3D:: operator*(const Vector3D& v3) const {
	double x1, x2, x3;
	x1 = v3.getX() * field[0] + v3.getY() * field[1] + v3.getZ() * field[2];
	x2 = v3.getX() * field[3] + v3.getY() * field[4] + v3.getZ() * field[5];
	x3 = v3.getX() * field[6] + v3.getY() * field[7] + v3.getZ() * field[8];
	return Vector3D(x1, x2, x3);
}

Matrix3D operator*(const int a, const Matrix3D& m3) {
	return Matrix3D((m3.field[0]) * a, (m3.field[1]) * a, (m3.field[2]) * a, (m3.field[3]) * a, (m3.field[4]) * a, (m3.field[5]) * a, (m3.field[6]) * a, (m3.field[7]) * a, (m3.field[8]) * a);
}

std::ostream& operator<<(std::ostream& os, const Matrix3D& m3) {
	os << "(" << m3.field[0] << " " << m3.field[1] << " " << m3.field[2] << " " << m3.field[3] << " " << m3.field[4] << " " << m3.field[5] << " " << m3.field[6] << " " << m3.field[7] << " " << m3.field[8] << ")";
	return os;
}

std::istream& operator >> (std::istream& is, Matrix3D& m3) {
	double x1, x2, x3, x4, x5, x6, x7, x8, x9;
	is >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8 >> x9;
	m3.setValue(1, 1, x1);
	m3.setValue(1, 2, x2);
	m3.setValue(1, 3, x3);
	m3.setValue(2, 1, x4);
	m3.setValue(2, 2, x5);
	m3.setValue(2, 3, x6);
	m3.setValue(3, 1, x7);
	m3.setValue(3, 2, x8);
	m3.setValue(3, 3, x9);
	return is;
}