#include "shape.h"
class Rectangle :
	public Shape
{
private:
	point_t p1;
	point_t p2;
public:
	Rectangle(point_t p1, point_t p2);
	double getArea() override;
	rectangle_t getFrameRect() override;
	void move(point_t point) override;
	void move(double x, double y) override;
	void scale(double coef) override;
	std::string getName() override;
	Shape* copy() override;
};

