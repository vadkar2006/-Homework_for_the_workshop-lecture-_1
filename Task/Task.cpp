#include <iostream>
#include <cmath>

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
    
    if(Items){
        if(Items[0])
            delete[] Items[0];
        
        if(Items[1])
            delete[] Items[1];
        
        delete[] Items;
    }
    
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

int Backpack::Volume_Finction(const Vector& items_vector) const{
    int w = 0;

    for(int i = 0; i < this -> Count_Items; i++)
        if(items_vector[i] != 0)
            w += this -> Items[1][i];
    
    return w;
}
int Backpack::Cost_Finction(const Vector& items_vector) const{
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


Backpack::~Backpack(){
    if(!Items)
        return;
    
    if(Items[0])
        delete[] Items[0];
    
    if(Items[1])
        delete[] Items[1];
    
    delete[] Items;
}





void TSP::Print() const{
    std::cout << "Count_Point: " << this -> Count_Point << std::endl;

    for(int i = 0; i < this -> Count_Point; i++)
        std::cout << Coordinates[0][i] << " " << Coordinates[1][i] << std::endl;
    std::cout << std::endl;
}
bool TSP::Input(std::ifstream input){
    if(!input.is_open())
        return false;
    
    if(Coordinates){
        if(Coordinates[0])
            delete[] Coordinates[0];
        
        if(Coordinates[1])
            delete[] Coordinates[1];
        
        delete[] Coordinates;
    }
    
    input >> this -> Count_Point;

    Coordinates = new int*[2];
    Coordinates[0] = new int[this -> Count_Point];
    Coordinates[1] = new int[this -> Count_Point];

    for(int i = 0; i < this -> Count_Point; i++)
        input >> Coordinates[0][i] >> Coordinates[1][i];
    
    return true;
}


TSP::TSP(std::istream& console){
    console >> this -> Count_Point;

    Coordinates = new int*[2];
    Coordinates[0] = new int[this -> Count_Point];
    Coordinates[1] = new int[this -> Count_Point];

    for(int i = 0; i < this -> Count_Point; i++)
        console >> Coordinates[0][i] >> Coordinates[1][i];
}
TSP::TSP(std::ifstream& file){
    file >> this -> Count_Point;

    Coordinates = new int*[2];
    Coordinates[0] = new int[this -> Count_Point];
    Coordinates[1] = new int[this -> Count_Point];

    for(int i = 0; i < this -> Count_Point; i++)
        file >> Coordinates[0][i] >> Coordinates[1][i];
}


double TSP::Cost_Finction(const Vector& coord_vector) const{
    double lin = 0;

    for(int i = 0; i < coord_vector.Dim() - 1; i++){
        double x = (Coordinates[0][coord_vector[i]] - Coordinates[0][coord_vector[i+1]]);
        double y = (Coordinates[1][coord_vector[i]] - Coordinates[1][coord_vector[i+1]]);
        
        lin += std::sqrt(x*x + y*y);
    }
    int k = coord_vector.Dim() - 1;
    double x = (Coordinates[0][coord_vector[k]] - Coordinates[0][coord_vector[0]]);
    double y = (Coordinates[1][coord_vector[k]] - Coordinates[1][coord_vector[0]]);
    
    lin += std::sqrt(x*x + y*y);

    return lin;
}


Vector TSP::Solve(Vector (&f)(const TSP&, const Vector&), const Vector& start) const{
    Vector total = f(*this, start);
    

    std::cout << "Length: " << this -> Cost_Finction(total) << std::endl;
    std::cout << "Vector_Things: ";
    total.Print();

    return total;
}
Vector TSP::Solve(Vector (&f)(const TSP&, const Vector&)) const{
    return this -> Solve(f, Vector(this -> Get_Count_Point(), "range"));
}


TSP::~TSP(){
    if(!Coordinates)
        return;
    
    if(Coordinates[0])
        delete[] Coordinates[0];
    
    if(Coordinates[1])
        delete[] Coordinates[1];
    
    delete[] Coordinates;
}
