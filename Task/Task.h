#pragma once

#include <fstream>
#include "Vector/Vector.h"



class Task;
class Backpack;



class Task{
public:
    virtual int Cost_Finction(Vector& items_vector) const = 0;
    virtual bool Input(std::ifstream input) = 0;
    virtual Vector Solve(Vector (&f)(const Backpack&, const Vector&), const Vector& start) const = 0;

    virtual ~Task(){};
};


class Backpack: public Task{
    long Max_Volume = 0;
    long Count_Items = 0;

    int** Items = nullptr;
public:
    Backpack(){}
    Backpack(std::istream& console);
    Backpack(std::ifstream& file);

    int Get_Max_Volume() const {return Max_Volume;};
    int Get_Count_Items() const {return Count_Items;};

    int Cost_Finction(Vector& items_vector) const;
    int Volume_Finction(Vector& items_vector) const;
    bool Input(std::ifstream input);

    Vector Solve(Vector (&f)(const Backpack&, const Vector&)) const;
    Vector Solve(Vector (&f)(const Backpack&, const Vector&), const Vector& start) const;

    void Print() const;
    ~Backpack(){delete[] Items[0]; delete[] Items[1]; delete[] Items;}
};




