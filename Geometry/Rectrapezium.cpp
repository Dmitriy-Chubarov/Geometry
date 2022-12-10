#include "Rectrapezium.h"

Rectrapezium::Rectrapezium(point_t p, double bottom, double top, double h) :
	p(p), bottom(bottom), top(top), h(h)
{
}

double Rectrapezium::getArea()
{
	return (bottom - (bottom - top) / 2) * h;
}

rectangle_t Rectrapezium::getFrameRect()
{
	double maxSide = std::max(top, bottom);
	return { { p.x + maxSide / 2, p.y + h / 2}, maxSide, h };
}

void Rectrapezium::move(point_t point)
{
	// TODO: Реализовать
}

void Rectrapezium::move(double x, double y)
{
	p.x += x;
	p.y += y;
}

void Rectrapezium::scale(double coef)
{
	// TODO: Реализовать
}

std::string Rectrapezium::getName()
{
	return "RECTRAPEZIUM";
}

Shape* Rectrapezium::copy()
{
	return new Rectrapezium(p, bottom, top, h);
}
