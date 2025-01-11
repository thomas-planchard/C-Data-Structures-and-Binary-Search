#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Car
{
    public:
        string make;
        string model;
        int year;
        string color;
        Car();
        Car(string make, string model, int year, string color);
        ~Car();
        void setMake(string make);
        void setModel(string model);
        void setYear(int year);
        void setColor(string color);
        void setCar(string make, string model, int year, string color);
        string getMake();
        string getModel();
        int getYear();
        string getColor();
        void display();
};

Car::Car()
{
    make = "";
    model = "";
    year = 0;
    color = "";
}  

Car::Car(string make, string model, int year, string color)
{
    this->make = make;
    this->model = model;
    this->year = year;
    this->color = color;
}

Car::~Car()
{
    cout << "This car has an engine problem and no longer works." << endl;
}

void Car::setMake(string make)
{
    this->make = make;
}

void Car::setModel(string model)
{
    this->model = model;
}

void Car::setYear(int year)
{
    this->year = year;
}


void Car::setColor(string color)
{
    this->color = color;
}

void Car::setCar(string make, string model, int year, string color)
{
    this->make = make;
    this->model = model;
    this->year = year;
    this->color = color;
}

string Car::getMake()
{
    return make;
}

string Car::getModel()
{
    return model;
}

int Car::getYear()
{
    return year;
}

string Car::getColor()
{
    return color;
}

void Car::display()
{
    cout << "Make: " << make ;
    cout << ", Model: " << model;
    cout << ", Year: " << year;
    cout << ", Color: " << color << endl;
}
