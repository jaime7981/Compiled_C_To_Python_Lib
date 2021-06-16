#ifndef _CITY
#define _CITY

#include<iostream>
#include<string>

using namespace std;

class City{
private:
    string name;
    string conections[10];
    int position[2];
    
public:
    City();
    City(string, int, int);

    string GetName();
    int * GetPositions();
};

#endif