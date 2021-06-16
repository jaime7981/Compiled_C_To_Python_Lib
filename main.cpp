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
    country.AddCity("Pirque", 2, 4);
    country.AddCity("Pucon", 9, 5);
    country.BuildNetwork();
    country.PrintCities();

    return 0;
}