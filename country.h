#ifndef _COUNT
#define _COUNT

#include<iostream>
#include<string>
#include <cmath>
#include"city.h"

using namespace std;

class Country {
private:
    string name;
    int city_counter;
    City cities[50];
public:
    Country();
    Country(string);

    void AddCity(string, int, int);
    double CityDistance(string, string);
    void FindPath();
    void EraseNetwork();
    void CreateNodes();
    void BuildNetwork();
    void PrintCities();
};

#endif