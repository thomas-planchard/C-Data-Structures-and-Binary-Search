#include "Parking.h"


int main()
{

    cout << "Welcome to the parking lot!" << endl;
    Parking parking;
    Car* car1 = new Car("Toyota", "Camry", 2015, "Black");
    Car* car2 = new Car("Honda", "Civic", 2010, "White");
    Car* car3 = new Car("Ford", "Fusion", 2018, "Red");
    Car* car4 = new Car("Chevrolet", "Malibu", 2013, "Blue");
    Car* car5 = new Car("Nissan", "Altima", 2016, "Silver");
    parking.parkCar(car1);
    parking.parkCar(car2);
    parking.parkCar(car3);
    parking.parkCar(car4);
    parking.parkCar(car5);

    cout << "Cars in the parking lot:" << endl;
    parking.displayCars();


    int choice;
    while (true)
    {
        cout << "Select an action:" << endl;
        cout << "1. Park a car" << endl;
        cout << "2. Remove a car" << endl;
        cout << "3. Search for a car" << endl;
        cout << "4. Display cars" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string make;
            string model;
            int year;
            string color;
            cout << "Enter the make of the car: ";
            cin >> make;
            cout << "Enter the model of the car: ";
            cin >> model;
            cout << "Enter the year of the car: ";
            cin >> year;
            cout << "Enter the color of the car: ";
            cin >> color;
            Car* car = new Car(make, model, year, color);
            parking.parkCar(car);
            cout << "Car parked successfully." << endl;
        }
        else if (choice == 2)
        {
            string make;
            string model;
            int year;
            string color;
            cout << "Enter the make of the car: ";
            cin >> make;
            cout << "Enter the model of the car: ";
            cin >> model;
            cout << "Enter the year of the car: ";
            cin >> year;
            cout << "Enter the color of the car: ";
            cin >> color;
            Car* car = new Car(make, model, year, color);
            parking.removeCar(car);
            cout << "Car removed successfully." << endl;
        }
        else if (choice == 3)
        {
            string make;
            string model;
            int year;
            string color;
            cout << "Enter the make of the car: ";
            cin >> make;
            cout << "Enter the model of the car: ";
            cin >> model;
            cout << "Enter the year of the car: ";
            cin >> year;
            cout << "Enter the color of the car: ";
            cin >> color;
            parking.searchCar(make, model, year, color);
        }
        else if (choice == 4)
        {
            parking.displayCars();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice."
                    << endl;
        }
    }
    
    return 0;

}