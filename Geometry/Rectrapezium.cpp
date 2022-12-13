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
	p.x = point.x - (bottom + top) / 4;
	p.y = point.y - h / 2;
}

void Rectrapezium::move(double x, double y)
{
	p.x += x;
	p.y += y;
}

void Rectrapezium::scale(double coef)
{
	p.x -= (coef - 1) * (bottom + top) / 4;
	p.y -= (coef - 1) * h / 2;
	h *= coef;
	bottom *= coef;
	top *= coef;
}

std::string Rectrapezium::getName()
{
	return "RECTRAPEZIUM";
}

Shape* Rectrapezium::copy()
{
	return new Rectrapezium(p, bottom, top, h);
}
