
#include"country.h"

int power(int x, int y) {
   if (y == 0)
   return 1;
   else if (y%2 == 0)
   return power(x, y/2)*power(x, y/2);
   else
   return x*power(x, y/2)*power(x, y/2);
}

Country::Country(string Name){
    name = Name;
    city_counter = 0;
}


void Country::AddCity(string name, int x, int y){
    if (city_counter < 50){
        cities[city_counter] = *new City(name, x, y);
        city_counter ++;
    }
}

double Country::CityDistance(string city_one, string city_two){
    int *position_one;
    int *position_two;

    for (int a = 0; a < 50; a++){
        if (cities[a].GetName() == city_one){
            position_one = cities[a].GetPositions();
            for (int b = 0; b < 50; b++){
                if (cities[b].GetName() == city_two && cities[b].GetName() != city_one){
                    position_two = cities[b].GetPositions();
                    return pow(pow((position_one[0] - position_two[0]), 2) + pow((position_one[1] - position_two[1]), 2), 0.5);
                }
            }
        }
    }
    return 0;
};

double Country::FindClosestCity(string city_one){
    double closest_distance = 0;
    string closest_city_name = "";

    for (int a = 0; a < 50; a++){
        if (cities[a].GetName() == city_one){
            for (int b = 0; b < 50; b++){
                if (cities[b].GetName() != city_one){
                    if (CityDistance(city_one, cities[b].GetName()) < closest_distance){
                        closest_distance = CityDistance(city_one, cities[b].GetName());
                        closest_city_name = cities[b].GetName();
                    }
                    else if (closest_distance == 0){
                        closest_distance = CityDistance(city_one, cities[b].GetName());
                        closest_city_name = cities[b].GetName();
                    }
                }
            }
        }
    }
    cout << closest_city_name << endl;
    return closest_distance;
}

void Country::PrintCities(){
    for (int a = 0; a < 50; a++){
        if (cities[a].GetName() != ""){
            cout << cities[a].GetName() << endl;
        }
    }
}