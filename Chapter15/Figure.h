#pragma once
class Figure
{
public:
    Figure() = default;
    Figure(double x, double y) :
        xSize(x), ySize(y) {}
    ~Figure();
protected:
    double xSize = 0.0, ySize = 0.0;
};

class Figure_2D :public Figure {
public:
    Figure_2D(double x, double y) :
        Figure(x, y) {}
    virtual double are() = 0;
    virtual double pcrimeter() = 0;
};

class Figure_3D :public Figure {
public:
    Figure_3D(double x, double y, double z) :
        Figure(x, y), zSize(z) {}
    virtual double cubage() = 0;
protected:
    double zSize = 0.0;
};

class Rectangle :public Figure_2D {
public:
    Rectangle(double x, double y) :
        Figure_2D(x, y) {}
    virtual double area() {
        return xSize * ySize;
    }
    virtual double perimeter() {
        return 2 * (xSize + ySize);
    }
};

class Circle :public Figure_2D {
public:
    Circle(double r) :
        Figure_2D(r,r) {}
    virtual double area() {
        return pi * xSize* ySize;
    }
    virtual double perimeter() {
        return 2 * pi* xSize;
    }
private:
    const double pi = 3.1415926;
};

class Sphere :public Figure_3D {
public:
    Sphere(double r) :
        Figure_3D(r, r, r) {}
    virtual double cubage() {
        return 4 * pi * xSize* ySize* zSize / 3;
    }
private:
    const double pi = 3.1415926;
};

class Cone :public Figure_3D {
public:
    Cone(double r, double h) :
        Figure_3D(r, r, h) {}
    virtual double cubage() {
        return pi * xSize* ySize* zSize / 3;
    }
private:
    const double pi = 3.1415926;
};
