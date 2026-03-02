#include <iostream>
#include "Task.h"


void Backpack::Print() const{
    std::cout << "Max_Volume: " << this -> Max_Volume << std::endl;
    std::cout << "Count_Items: " << this -> Count_Items << std::endl;

    for(int i = 0; i < this -> Count_Items; i++)
        std::cout << Items[0][i] << " " << Items[1][i] << std::endl;
    std::cout << std::endl;
}
bool Backpack::Input(std::ifstream input){
    if(!input.is_open())
        return false;
    
    if((Items[0]) && (Items[1])){
        delete[] Items[0];
        delete[] Items[1];

        Items[0] = nullptr;
        Items[1] = nullptr;
    }

    if(Items[0])
        delete[] Items[0];
    
    if(Items[1])
        delete[] Items[1];
    
    if(Items)
        delete[] Items;
    
    input >> this -> Count_Items >> this -> Max_Volume;

    Items = new int*[2];
    Items[0] = new int[this -> Count_Items];
    Items[1] = new int[this -> Count_Items];

    for(int i = 0; i < this -> Count_Items; i++)
        input >> Items[0][i] >> Items[1][i];
    
    return true;
}


Backpack::Backpack(std::istream& console){
    console >> this -> Count_Items >> this -> Max_Volume;

    Items = new int*[2];
    Items[0] = new int[this -> Count_Items];
    Items[1] = new int[this -> Count_Items];

    for(int i = 0; i < this -> Count_Items; i++)
        console >> Items[0][i] >> Items[1][i];
}
Backpack::Backpack(std::ifstream& file){
    file >> this -> Count_Items >> this -> Max_Volume;

    Items = new int*[2];
    Items[0] = new int[this -> Count_Items];
    Items[1] = new int[this -> Count_Items];

    for(int i = 0; i < this -> Count_Items; i++)
        file >> Items[0][i] >> Items[1][i];
}
int Backpack::Volume_Finction(Vector& items_vector) const{
    int w = 0;

    for(int i = 0; i < this -> Count_Items; i++)
        if(items_vector[i] != 0)
            w += this -> Items[1][i];
    
    return w;
}
int Backpack::Cost_Finction(Vector& items_vector) const{
    int cost = 0;
    int volume = 0;

    for(int i = 0; i < this -> Count_Items; i++)
        if(items_vector[i] != 0){
            cost += Items[0][i];
            volume += Items[1][i];
        }
    
    if(volume > Max_Volume)
        return -1;
    return cost;
}


Vector Backpack::Solve(Vector (&f)(const Backpack&, const Vector&), const Vector& start) const{
    Vector total = f(*this, start);
    

    std::cout << "Benefit: " << this -> Cost_Finction(total) << std::endl;
    std::cout << this -> Volume_Finction(total) << " of " << Max_Volume << " weights used" << std::endl;
    std::cout << "Vector_Things: ";
    total.Print();

    return total;
}
Vector Backpack::Solve(Vector (&f)(const Backpack&, const Vector&)) const{
    return this -> Solve(f, Vector(this -> Get_Count_Items()));
}
