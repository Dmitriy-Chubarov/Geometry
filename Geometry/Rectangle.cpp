#include "Rectangle.h"

Rectangle::Rectangle(point_t p1, point_t p2) : p1(p1), p2(p2)
{
}

double Rectangle::getArea()
{
	return abs(p1.x - p2.x) * abs(p1.y - p2.y);
}

rectangle_t Rectangle::getFrameRect()
{
	return { { (p2.x + p1.x) / 2, (p2.y + p1.y) / 2},
				abs(p1.x - p2.x), abs(p1.y - p2.y) };
}

void Rectangle::move(point_t point)
{
	p1.x += point.x - ((p2.x + p1.x) / 2);
	p1.y += point.y - ((p2.y + p1.y) / 2);
}

void Rectangle::move(double x, double y)
{
	p1.x += x;
	p2.x += x;
	p1.y += y;
	p2.y += y;
}

void Rectangle::scale(double coef)
{

	// TODO: Реализовать
}

std::string Rectangle::getName()
{
	return "RECTANGLE";
}

Shape* Rectangle::copy()
{
	return new Rectangle(p1, p2);
}
