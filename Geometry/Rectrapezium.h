#include "shape.h"
class Rectrapezium :
	public Shape
{
private:
	point_t p;
	double bottom;
	double top;
	double h;
public:
	Rectrapezium(point_t p, double bottom, double top, double h);
	double getArea() override;
	rectangle_t getFrameRect() override;
	void move(point_t point) override;
	void move(double x, double y) override;
	void scale(double coef) override;
	std::string getName() override;
	Shape* copy() override;
};

