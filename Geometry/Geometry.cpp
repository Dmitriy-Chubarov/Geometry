#include <iostream>
#include <fstream>
#include <sstream>
#include "shape.h"
#include "Rectangle.h"

void Sort(Shape** shapes, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (shapes[j]->getArea() > shapes[j + 1]->getArea()) 
			{
				std::swap(shapes[j], shapes[j + 1]);
			}
		}
	}
}

int LoadFile(Shape**& shapes, std::string fileName)
{
	int size = 0;
	std::ifstream in(fileName);
	std::string line, figure;
	while (!in.eof())
	{
		std::getline(in, line);
		std::stringstream ss(line);
		ss >> figure;
		if (figure == "RECTANGLE")
		{
			point_t p1, p2;
			ss >> p1.x >> p1.y >> p2.x >> p2.y;
			Shape* r = new Rectangle(p1, p2);
			std::cout << r;

			shapes = new Shape*[1];
			shapes[0] = r->copy();
			size++;
		}
	}

	return size;
}

int main()
{
	Shape** shapes = nullptr;
	int size;
	LoadFile(shapes, "shapes.txt");
	return 0;
}