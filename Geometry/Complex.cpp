#include "Complex.h"

Complex::Complex(int size, Shape** shapes) : size(size)
{
	this->shapes = new Shape * [size];
	for (size_t i = 0; i < size; i++)
		this->shapes[i] = shapes[i]->copy();
}

double Complex::getArea()
{
	double sum;
	for (size_t i = 0; i < size; i++)
		sum += shapes[i]->getArea();
	return sum;
}

rectangle_t Complex::getFrameRect()
{
	// TODO: Реализовать
	return rectangle_t();
}

void Complex::move(point_t point)
{
	for (size_t i = 0; i < size; i++)
		shapes[i]->move(point);
}

void Complex::move(double x, double y)
{
	for (size_t i = 0; i < size; i++)
		shapes[i]->move(x, y);
}

void Complex::scale(double coef)
{
	// TODO: Реализовать
}

std::string Complex::getName()
{
	return "COMPLEX";
}

Shape* Complex::copy()
{
	return new Complex(size, shapes);
}
