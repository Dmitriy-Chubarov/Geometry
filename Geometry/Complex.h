#include "shape.h"
class Complex :
	public Shape
{
private:
	Shape** shapes;
	int size;
public:
	Complex(int size, Shape** shapes);
	double getArea() override;
	rectangle_t getFrameRect() override;
	void move(point_t point) override;
	void move(double x, double y) override;
	void scale(double coef) override;
	std::string getName() override;
	Shape* copy() override;
};

