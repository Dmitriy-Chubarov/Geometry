#ifndef SHAPE
#define SHAPE

#include <string>
#include <ostream>
#include "base-types.h"

class Shape
{
public:
	virtual double getArea() = 0;
	virtual rectangle_t getFrameRect() = 0;
	virtual void move(point_t point) = 0;
	virtual void move(double x, double y) = 0;
	virtual void scale(double coef) = 0;
	virtual std::string getName() = 0;
	virtual Shape* copy() = 0;
	friend std::ostream& operator<<(std::ostream& out, Shape* shape);
	bool operator<(Shape* shape);
};

#endif // !SHAPE