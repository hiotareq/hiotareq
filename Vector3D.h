#ifndef Vector3D_h
#define Vector3D_h

class Vector3D {
private:
	double x;
	double y;
	double z;
public:
	friend Vector3D operator*(const int a, Vector3D& v3);
	Vector3D(double x, double y, double z);
	Vector3D();
	~Vector3D();
	double getX() const;
	double getY() const;
	double getZ() const;
	void setX(double new_y);
	void setY(double new_y);
	void setZ(double new_z);

	Vector3D operator+(const Vector3D& v3) const;
	Vector3D operator-(const Vector3D& v3) const;
	Vector3D operator*(const int a) const;
	double operator*(const Vector3D& v3) const;
	double scalar_product(const Vector3D& v3) const;
};
std::istream& operator>>(std::istream& is, Vector3D& v3);
Vector3D operator*(const int a, Vector3D& v3);
std::ostream& operator<<(std::ostream& os, const Vector3D& v3);
#endif 
