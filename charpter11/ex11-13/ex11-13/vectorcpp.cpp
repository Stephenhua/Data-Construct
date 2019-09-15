#include<iostream>
#include<cmath>
#include"vector.h"
namespace VECTOR{
	using namespace std;
	const double Rad_to_ang = 45.0 / atan(1.0);
 
	Vector::Vector(){
		x = y = mag = ang = 0;
		mode = RECT;
	}

	Vector::~Vector()
	{

	}

	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang(){
		if (x == 0.0&&y == 0.0)
		{
			ang = 0.0;
		}
		else{
			ang = atan2(y, x);
		}
	}

	void Vector::set_x()
	{
		x = mag*cos(ang);
	}

	void Vector::set_y(){
		y = mag*sin(ang);
	}


	Vector::Vector(double n1, double n2, Mode from ){
		mode = from;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (mode == POL){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "Vector set to 0\n;";
			x = y = ang = mag = 0;
			mode = RECT;
		}

	}
	void Vector::reset(double n1, double n2, Mode from ){
		mode = from;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (mode == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else{
			cout << "Incorent 3rd argument to Vector()--";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}
	

	void Vector::polar_mode(){
		mode = POL;
	}
	void Vector::rect_mode(){
		mode = RECT;
	}

	Vector Vector::operator+(const Vector&b)const{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b)const{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator*(double b)const{
		return Vector(b*x, b*y);
	}
	Vector Vector::operator-()const{
		return Vector(-x, -y);

	}

	Vector operator*(double n, const Vector &a){
		return a*n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector &v){
		if (v.mode== Vector::RECT){
			os << "(x,y)=(" << v.x << "," << v.y << ")\n";
		}
		else if (v.mode == Vector::POL){
			os << "(m,a)=(" << v.mag << "," << v.ang << ")\n";
		}
		else{
			os << "Vector object mode is invalied;";
		}
		return os;

	}

}
