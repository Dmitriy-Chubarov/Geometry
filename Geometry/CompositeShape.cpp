#include "CompositeShape.h"

CompositeShape::CompositeShape(int size, Shape** shapes) : size(size)
{
	this->shapes = new Shape * [size];
	for (size_t i = 0; i < size; i++)
		this->shapes[i] = shapes[i]->copy();
}

double CompositeShape::getArea()
{
	double sum = 0.0;
	for (size_t i = 0; i < size; i++)
	{
		sum += shapes[i]->getArea();
	}
	return sum;
}

rectangle_t CompositeShape::getFrameRect()
{
	point_t p1 = { this->shapes[0]->getFrameRect().pos.x - this->shapes[0]->getFrameRect().width / 2,
		this->shapes[0]->getFrameRect().pos.y - this->shapes[0]->getFrameRect().height / 2 };
	point_t p2 = { this->shapes[0]->getFrameRect().pos.x + this->shapes[0]->getFrameRect().width / 2,
		this->shapes[0]->getFrameRect().pos.y + this->shapes[0]->getFrameRect().height / 2 };
	for (size_t i = 0; i < this->size; i++)
	{
		if (shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2 < p1.x)
			p1.x = shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2;
		if	(shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2 < p1.y)
			p1.y = shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2;

		if (shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2 > p2.x)
			p2.x = shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2;
		if (shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2 > p2.y)
			p2.y = shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
	}
	return { { (p2.x + p1.x) / 2, (p2.y + p1.y) / 2},
				abs(p1.x - p2.x), abs(p1.y - p2.y) };
}

void CompositeShape::move(point_t point)
{
	for (size_t i = 0; i < size; i++)
	{
		shapes[i]->move(point);
	}
}

void CompositeShape::move(double x, double y)
{
	for (size_t i = 0; i < size; i++)
	{
		shapes[i]->move(x, y);
	}
}

void CompositeShape::scale(double coef)
{
	for (size_t i = 0; i < size; i++)
	{
		shapes[i]->scale(coef);
	}
	
}

std::string CompositeShape::getName()
{
	return "COMPLEX";
}

Shape* CompositeShape::copy()
{
	return new CompositeShape(size, shapes);
}
