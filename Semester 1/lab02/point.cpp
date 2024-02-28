#include <iostream>

using namespace std;

class Point
{
	public:
		Point();
		Point(double x, double y);
		void print() const;
	private:
		double x;
		double y;
};

Point::Point()
{
	x = 0;
	y = 0;
}//Point

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}//Point

void Point::print() const
{
	cout << "(" << x << ", " << y << ")" << endl;
}//print

int main()
{
	Point* ptr_point = NULL;
	ptr_point = new Point(1, 2);

	ptr_point->print();

	if (ptr_point)
	{
		delete ptr_point;
		ptr_point = NULL;
	}

	return 0;
}//main
