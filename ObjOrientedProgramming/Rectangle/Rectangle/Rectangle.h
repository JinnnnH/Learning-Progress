#ifndef RECTANGLE_H
#define RECTANGLE_H

/*
-----------------------------------
Rectangle
-----------------------------------
- width: double
- length: double
-----------------------------------
+ setWidth(w: double): void
+ setLength(l: double): void
+ getWidth(): double
+ getLength(): double
+ getArea(): double
-----------------------------------
*/

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

#endif