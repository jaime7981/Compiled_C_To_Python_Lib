#include"city.h"

City::City(){
    
}

City::City(string Name, int pos_x, int pos_y){
    name = Name;
    position[0] = pos_x;
    position[1] = pos_y;
}

string City::GetName(){
    return name;
}

int * City::GetPositions(){
    return position;
};