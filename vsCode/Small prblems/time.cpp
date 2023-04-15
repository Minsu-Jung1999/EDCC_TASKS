#include <string>
#include <iostream>
class Circle
{
    private:
    double radius;
    const double PI  = 3.141592;
    public:
    Circle(double r)
    {
        radius = r;
    }
    double area()
    {
        return PI*radius*radius;
    }
    double circumference()
    {
        return 2*PI*radius;
    }
    double getRadius()
    {
        return radius;
    }
    std::string toString()
    {
        return std::to_string(radius);
    }
};