#include<iostream>
#include<string>
#include"country.h"
#include"city.h"

Country country = *new Country("Chile");

int main(){

    country.AddCity("Santiago", 10, 10);
    country.AddCity("Iquique", 12, 8);
    country.AddCity("Los Andes", 1, 1);
    country.AddCity("Rancagua", 3, 8);
    country.PrintCities();
    cout << country.FindClosestCity("Santiago") << endl;
    cout << country.FindClosestCity("Rancagua") << endl;
    cout << country.CityDistance("Santiago", "Iquique") << endl;
    cout << country.CityDistance("Santiago", "Los Andes") << endl;

    return 0;
}