#ifndef _CITY
#define _CITY

#include<iostream>
#include<string>

using namespace std;

class City{
private:
    string name;
    string conections[10];
    string nodes[10];
    int conection_counter;
    int node_counter;
    int position[2];
    
public:
    City();
    City(string, int, int);

    string GetName();
    int* GetPositions();
    string* GetConections();
    string* GetNodes();
    void EraseConections();
    void ConectCity(string);
    void AddNode(string);
};

#endif