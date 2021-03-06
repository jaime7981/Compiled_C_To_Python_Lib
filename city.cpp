#include"city.h"

City::City(){
    
}

City::City(string Name, int pos_x, int pos_y){
    name = Name;
    position[0] = pos_x;
    position[1] = pos_y;
    conection_counter = 0;
    node_counter = 0;
}

string City::GetName(){
    return name;
}

int * City::GetPositions(){
    return position;
};

string * City::GetConections(){
    return conections;
}

string* City::GetNodes(){
    return nodes;
};

void City::EraseConections(){
    for (int a = 0; a < 10; a++){
        conections[a] = "";
        nodes[a] = "";
    }
    conection_counter = 0;
    node_counter = 0;
}

void City::ConectCity(string city_name){
    conections[conection_counter] = city_name;
    conection_counter ++;
};

void City::AddNode(string city_name){
    nodes[node_counter] = city_name;
    node_counter ++;
};