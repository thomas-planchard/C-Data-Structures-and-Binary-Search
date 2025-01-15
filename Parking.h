// This file contains the declaration of the Parking class and its member functions.
// The Parking class manages a collection of cars and provides methods to park, remove, search, display, and sort cars.
#include "BST.hpp"
#include "Car.h"

class Parking : public Car
{

    public:
        vector<Car*> cars;
        Parking();
        ~Parking();
        void parkCar(Car* car);
        void removeCar(Car* car);
        vector<Car*> getCars();
        void displayCars();
        void searchCar(string make, string model, int year, string color);
        void sortCarsByYear();
};


Parking::Parking()
{
    cout << "The parking lot is now open." << endl;
}

Parking::~Parking()
{
    cout << "The parking lot is now empty." << endl;
}

void Parking::parkCar(Car* car)
{
    cars.push_back(car);
}

void Parking::removeCar(Car* car)
{
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i] == car)
        {
            cars.erase(cars.begin() + i);
            break;
        }
    }
}

vector<Car*> Parking::getCars()
{
    return cars;

}


void Parking::displayCars()
{
    for (int i = 0; i < cars.size(); i++)
    {
        cars[i]->display();
    }
}


void Parking::sortCarsByYear()
{
    cout << "Sorting cars by year using BinaryTree..." << endl;

    BinaryTree tree;
    Node* root = NULL;

    // Insert car years into the BST
    for (Car* car : cars)
    {
        root = tree.insertNode(root, car->year);
    }

    vector<int> sortedYears;
    tree.inOrderStorage(root, sortedYears);

    vector<Car*> sortedCars;
    for (int year : sortedYears)
    {
        for (Car* car : cars)
        {
            if (car->year == year)
            {
                sortedCars.push_back(car);
                break;
            }
        }
    }

    cars = sortedCars;
    displayCars();
}


void Parking::searchCar(string make, string model, int year, string color)
{
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i]->getMake() == make && cars[i]->getModel() == model && cars[i]->getYear() == year && cars[i]->getColor() == color)
        {
            cars[i]->display();
            break;
        }
    }
}