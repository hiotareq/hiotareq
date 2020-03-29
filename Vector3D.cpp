#include <iostream>
#include "Vector3D.h"

Vector3D:: Vector3D(double x, double y, double z) : x(x), y(y), z(z) {};
Vector3D:: Vector3D() : Vector3D(0, 0, 0) {};

Vector3D:: ~Vector3D() {};

double Vector3D:: getX() const {
	return x;
}
double Vector3D::getY() const {
	return y;
}
double Vector3D::getZ() const {
	return z;
}

void Vector3D::setX(double new_x) {
	x = new_x;
}
void Vector3D::setY(double new_y) {
	y = new_y;
}
void Vector3D::setZ(double new_z) {
	z = new_z;
}

Vector3D Vector3D:: operator+(const Vector3D& v3) const {
	double x1, x2, x3;
	x1 = this->x + v3.x;
	x2 = this->y + v3.y;
	x3 = this->z + v3.z;
	return Vector3D(x1, x2, x3);
}
Vector3D Vector3D:: operator-(const Vector3D& v3) const {
	double x1, x2, x3;
	x1 = this->x - v3.x;
	x2 = this->y - v3.y;
	x3 = this->z - v3.z;
	return Vector3D(x1, x2, x3);
}
Vector3D Vector3D:: operator*(const int a) const {
	double x1, x2, x3;
	x1 = x * a;
	x2 = y * a;
	x3 = z * a;
	return Vector3D(x1, x2, x3);
}
double Vector3D:: operator*(const Vector3D& v3) const {
	double res;
	res = x * v3.x + y * v3.y + z * v3.z;
	return res;
}
double Vector3D::scalar_product(const Vector3D& v3) const {
	return (x * v3.x + y * v3.y + z * v3.z);
}
std::istream& operator>>(std::istream& is, Vector3D& v3) {
	double x, y, z;
	is >> x >> y >> z;
	v3.setX(x);
	v3.setY(y);
	v3.setZ(z);
	return is;
}

Vector3D operator*(const int a, Vector3D& v3) {
	return Vector3D(v3.x * a, v3.y * a, v3.z * a);
}
std::ostream& operator<<(std::ostream& os, const Vector3D& v3) {
	os << "(" << v3.getX() << "; " << v3.getY() << "; " << v3.getZ() << ")";
	return os;
}