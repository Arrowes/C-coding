#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual void Print() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double Area() const override {
        return M_PI * radius * radius;
    }
    
    void Print() const override {
        cout << "Circle with radius " << radius << endl;
    }
};

class Triangle : public Shape {
private: 
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    double Area() const override {
        return 0.5 * base * height;
    }
    
    void Print() const override {
        cout << "Triangle with base " << base << " and height " << height << endl;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Triangle(4, 3);
    
    for (int i = 0; i < 2; i++) {
        shapes[i]->Print();
        std::cout << "Area: " << shapes[i]->Area() << std::endl;
        delete shapes[i];
    }
    
    return 0;
}
