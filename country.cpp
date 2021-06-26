
#include"country.h"

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

void Country::FindPath(){

};

void Country::EraseNetwork(){
    for (int a = 0; a < 50; a++){
        if (cities[a].GetName() != ""){
            cities[a].EraseConections();
        }
    }
}

void Country::CreateNodes(){
    string city_one;
    string city_two;

    string *conections;

    for (int a = 0;  a < 50; a++){
        if (cities[a].GetName() != ""){
            city_one = cities[a].GetName();
            for (int b = 0; b < 50; b++){
                if (cities[b].GetName() != ""){
                    city_two = cities[b].GetName();

                    conections = cities[b].GetConections();

                    for (int c = 0; c < 10; c++){
                        if (conections[c] == city_one && city_one != city_two){
                            cities[a].AddNode(city_two);
                        }
                    }
                }
            }
        }
        cities[a].AddNode(cities[a].GetConections()[0]);
    }
}

void Country::BuildNetwork(){
    EraseNetwork();
    double closest_distance = 0;
    double second_closest = 0;
    double distance = 0;
    string closest_city_name = "";
    string second_closest_name = "";
    string city_one;
    string city_two;
    string* city_conections;
    bool flag = true;

    for (int a = 0; a < 50; a++){
        if (cities[a].GetName() != ""){
            city_one = cities[a].GetName();

            for (int b = 0; b < 50; b++){
                if (cities[b].GetName() != ""){
                    city_two = cities[b].GetName();
                    distance = CityDistance(city_one, city_two);

                    if (distance < closest_distance && city_one != city_two){
                        closest_distance = distance;
                        closest_city_name = city_two;
                    }
                    else if (closest_distance == 0 && city_one != city_two){
                        closest_distance = distance;
                        closest_city_name = city_two;
                    }
                }
            }

            for (int b = 0; b < 50; b++){
                if (cities[b].GetName() != ""){
                    city_two = cities[b].GetName();
                    distance = CityDistance(city_one, city_two);

                    if (closest_city_name != city_two){
                        if (distance < second_closest && city_one != city_two){
                            second_closest = distance;
                            second_closest_name = city_two;
                        }
                        else if (second_closest == 0 && city_one != city_two){
                            second_closest = distance;
                            second_closest_name = city_two;
                        }
                    }
                }
            }

            for (int b = 0; b < 50; b++){
                city_conections = cities[b].GetConections();

                for (long unsigned int c = 0; c < city_conections->length(); c++){
                    if ((city_conections[c] == city_one || city_conections[c] == closest_city_name) && city_conections[c] != ""){
                        flag = false;
                    }
                }
            }

            if (flag == false){
                cities[a].ConectCity(second_closest_name);
            }
            else{
                cities[a].ConectCity(closest_city_name);
            }
            
            closest_distance = 0;
            second_closest = 0;
            closest_city_name = "";
            second_closest_name = "";
            flag = true;
        }
    }

    CreateNodes();
}

void Country::PrintCities(){
    string* city_conections;
    for (int a = 0; a < 50; a++){
        if (cities[a].GetName() != ""){
            cout << cities[a].GetName() << endl;
            cout << "Nodes:" << endl;

            city_conections = cities[a].GetNodes();
            for (long unsigned int b = 0; b < city_conections->length(); b++){
                if (city_conections[b] != ""){
                    cout << city_conections[b] << endl;
                }
            }

            cout << endl;
        }
    }
}