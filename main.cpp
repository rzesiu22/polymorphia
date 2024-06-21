#include <iostream>
#include <cmath> // Dla stałej M_PI

// Abstrakcyjna klasa Figure
class Figure {
public:
    // Czysta wirtualna metoda area()
    virtual double area() const = 0;

    // Czysta wirtualna metoda show()
    virtual void show() const = 0;

    // Wirtualny destruktor
    virtual ~Figure() = default;
};

// Klasa Circle dziedzicząca po Figure
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementacja metody area()
    double area() const override {
        return M_PI * radius * radius;
    }

    // Implementacja metody show()
    void show() const override {
        std::cout << "Circle with radius: " << radius << " and area: " << area() << std::endl;
    }
};

// Klasa Rectangle dziedzicząca po Figure
class Rectangle : public Figure {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementacja metody area()
    double area() const override {
        return width * height;
    }

    // Implementacja metody show()
    void show() const override {
        std::cout << "Rectangle with width: " << width << ", height: " << height << " and area: " << area()
                  << std::endl;
    }
};


class Square : public Figure {
private:
    double length;

public:
    Square(double l): length(l){}

    double area() const override{
        return length*length;
    }
    void show() const override {
        std::cout <<" Square with length " << length << " and area: " << area()
                  <<std::endl;
    }

};


int main() {
    // Tablica wskaźników na obiekty klasy Figure
    Figure *figures[6];

    // Tworzenie obiektów i przypisywanie wskaźników do tablicy
    figures[0] = new Circle(5.0);
    figures[1] = new Rectangle(4.0, 6.0);
    figures[2] = new Square(3.0);
    figures[3] = new Circle(3.0);
    figures[4] = new Rectangle(2.5, 5.5);
    figures[5] = new Square(5);


    // Iteracja przez tablicę i wyświetlanie informacji o obiektach
    for (int i = 0; i < 6; ++i) {
        figures[i]->show();
    }

    // Zwolnienie pamięci
    for (int i = 0; i < 6; ++i) {
        delete figures[i];
    }

    return 0;
}