#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double width;
    double length;

public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

// Function definitions

inline void Rectangle::setWidth(double w)
{
    width = w;
}

inline void Rectangle::setLength(double len)
{
    length = len;
}

inline double Rectangle::getWidth() const
{
    return width;
}

inline double Rectangle::getLength() const
{
    return length;
}

inline double Rectangle::getArea() const
{
    return width * length;
}

#endif