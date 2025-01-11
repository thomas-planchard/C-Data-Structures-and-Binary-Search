#include "Car.h"


class Parking : public Car
{

    public:
        vector<Car*> cars;
        Parking();
        ~Parking();
        void parkCar(Car* car);
        void removeCar(Car* car);
        void displayCars();
        void sortCars(vector<Car>* car, int start, int end);
        void searchCar(string make, string model, int year, string color);

    private:
        void merge(vector <Car>* car, int start, int mid, int end);

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


void Parking::displayCars()
{
    for (int i = 0; i < cars.size(); i++)
    {
        cars[i]->display();
    }
}


void Parking::sortCars(vector<Car>* cars, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;
        sortCars(cars, start, mid);
        sortCars(cars, mid + 1, end);
        merge(cars, start, mid, end);
    }
    else return;
}

void Parking::merge(vector<Car>* cars, int start, int mid, int end)
{
    int sizeLeft = mid - start + 1;
    int sizeRight = end - mid;
    vector<Car> left(sizeLeft);
    vector<Car> right(sizeRight);
    for (int i = 0; i < sizeLeft; i++)
    { 
        left[i] = (*cars)[start + i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
        right[i] = (*cars)[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < sizeLeft && j < sizeRight)
    {
        if (left[i].getYear() <= right[j].getYear())
        {
            (*cars)[k] = left[i];
            i++;
        }
        else
        {
            (*cars)[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < sizeLeft)
    {
        (*cars)[k] = left[i];
        i++;
        k++;
    }
    while (j < sizeRight)
    {
        (*cars)[k] = right[j];
        j++;
        k++;
    }
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