#ifndef TEST_CAR_H
#define TEST_CAR_H

#include <cassert>
#include <iostream>

inline void testCar()
{
    Car defaultCar;
    assert(defaultCar.getMake() == "");
    assert(defaultCar.getModel() == "");
    assert(defaultCar.getYear() == 0);
    assert(defaultCar.getColor() == "");

    Car specificCar("Toyota", "Camry", 2020, "White");
    assert(specificCar.getMake() == "Toyota");
    assert(specificCar.getModel() == "Camry");
    assert(specificCar.getYear() == 2020);
    assert(specificCar.getColor() == "White");

    specificCar.setMake("Honda");
    specificCar.setModel("Civic");
    specificCar.setYear(2021);
    specificCar.setColor("Blue");
    assert(specificCar.getMake() == "Honda");
    assert(specificCar.getModel() == "Civic");
    assert(specificCar.getYear() == 2021);
    assert(specificCar.getColor() == "Blue");

    std::cout << "All Car tests passed!\n";
}

#endif