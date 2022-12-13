#include "shape.h"

std::ostream& operator<<(std::ostream& out, Shape* shape)
{
    out << shape->getName() << " " << shape->getArea() << " " << shape->getFrameRect().pos.x - shape->getFrameRect().width / 2
        << " " << shape->getFrameRect().pos.y - shape->getFrameRect().height / 2
        << " " << shape->getFrameRect().pos.x + shape->getFrameRect().width / 2
        << " " << shape->getFrameRect().pos.y + shape->getFrameRect().height / 2;
    return out;
}

bool Shape::operator<(Shape* shape)
{
    return this->getArea() > shape->getArea();
}
