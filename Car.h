// This file contains the declaration of the Car class and its member functions.
// The Car class represents a car with attributes such as make, model, year, and color.

#include <string>

using namespace std;

class Car
{
    public:
        string make;  // Make of the car
        string model; // Model of the car
        int year;     // Year of the car
        string color; // Color of the car

        // Constructor to initialize a car object
        Car();
        Car(string make, string model, int year, string color);
        ~Car();

        // Setter for the make attribute
        void setMake(string make);

        // Setter for the model attribute
        void setModel(string model);

        // Setter for the year attribute
        void setYear(int year);

        // Setter for the color attribute
        void setColor(string color);

        // Setter for all attributes
        void setCar(string make, string model, int year, string color);

        // Getter for the make attribute
        string getMake();

        // Getter for the model attribute
        string getModel();

        // Getter for the year attribute
        int getYear();

        // Getter for the color attribute
        string getColor();

        // Display the car's details
        void display();
};

// Constructor to initialize a car object
Car::Car()
{
    make = "";
    model = "";
    year = 0;
    color = "";
}  

// Constructor to initialize a car object with given attributes
Car::Car(string make, string model, int year, string color)
{
    this->make = make;
    this->model = model;
    this->year = year;
    this->color = color;
}

// Destructor
Car::~Car()
{}

// Setter for the make attribute
void Car::setMake(string make)
{
    this->make = make;
}

// Setter for the model attribute
void Car::setModel(string model)
{
    this->model = model;
}

// Setter for the year attribute
void Car::setYear(int year)
{
    this->year = year;
}

// Setter for the color attribute
void Car::setColor(string color)
{
    this->color = color;
}

// Setter for all attributes
void Car::setCar(string make, string model, int year, string color)
{
    this->make = make;
    this->model = model;
    this->year = year;
    this->color = color;
}

// Getter for the make attribute
string Car::getMake()
{
    return make;
}

// Getter for the model attribute
string Car::getModel()
{
    return model;
}

// Getter for the year attribute
int Car::getYear()
{
    return year;
}

// Getter for the color attribute
string Car::getColor()
{
    return color;
}

// Display the car's details
void Car::display()
{
    cout << "Make: " << make ;
    cout << ", Model: " << model;
    cout << ", Year: " << year;
    cout << ", Color: " << color << endl;
}
