#include<iostream>
#include<ostream>
#include<istream>
using namespace std;
class complex {
private:
	int a, b;
public:
	complex(int _a, int _b) : a(_a), b(_b) {//member initialize list

	}
	complex() {
		//empty constructor
	}
	complex& operator+(const complex& c) {
		complex temp;
		temp.a = this->a + c.a;
		temp.b = this->b + c.b;
		return temp;
	}
	complex& operator-(const complex& c) {
		complex temp;
		temp.a = this->a - c.a;
		temp.b = this->b - c.b;
		return temp;
	}
	void operator=(const complex& c) {
		this->a = c.a;
		this->b = c.b;
	}
	complex& operator+(const int& x) {
		complex temp;
		temp.a = this->a + x;
		temp.b = this->b;
		return temp;
	}
	void operator+=(const int& x) {
		this->a += x;
	}
	complex& operator*(const complex& c) {
		complex temp;
		temp.a = (this->a * c.a) - (this->b * c.b);
		temp.b = (this->a * c.b) + (c.a * this->b);
		return temp;
	}
	friend istream& operator>>(istream& in,complex& c) {//input overloaded
		in >> c.a >> c.b;
		return in;
	}
	friend ostream& operator<<(ostream& out, const complex& c) {//output overloaded
		if (c.b > 0) {
			out << c.a << "+" << c.b << "i";
		}
		else {
			out << c.a << c.b << "i";
		}
		return out;
	}
	~complex() {

	}
};
int main() {
	complex a(2, 3);
	complex b(5, 2);
	complex c = a + b;
	complex d = a - b;
	complex e = a * b;
	complex x = b + 12;
	complex y = a + b;
	y += 2;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << x << endl;
	cout << y << endl;
	cout << "nhap so phuc[a] [b]:";
	complex com;
	cin >> com;
	cout << "so phuc vua nhap:" << com << endl;
}