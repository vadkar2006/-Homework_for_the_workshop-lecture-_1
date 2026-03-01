#include <iostream>
#include "Vector.h"

Vector::Vector(int n, int q){
    if (n > 0){
        len = n;

        vector = new int[len];
        for(int i = 0; i < len; i++)
            vector[i] = q;
    }
}
Vector::Vector(int len1, int* vec){
    if ((len1 > 0) && vec){
        len = len1;
        vector = vec;
    }
}
Vector::Vector(Vector&& vec) noexcept {
    len = vec.len;
    vector = vec.vector;
    vec.vector = nullptr;
}
Vector::Vector(const Vector& vec){
    if ((vec.len > 0) && vec.vector)
        len = vec.len;

    for(int i = 0; i < len; i++)
        vector[i] = vec.vector[i];
}


void Vector::Print(){
    std::cout << "Lenght: " << this -> Len() << std::endl;
    for(int i = 0; i < this -> Len(); i++)
        std::cout << this -> vector[i];
    std::cout << std::endl;
}

int& Vector::operator[] (int i){
    return vector[i];
}
const int& Vector::operator[] (int i) const{
    return vector[i];
}


bool Vector::operator = (const Vector& vec){
    if(this == &vec)
        return false;
    
    if(vector)
        delete[] vector;

    len = vec.len;
    vector = new int[len];
    for(int i = 0; i < len; i++)
        vector[i] = vec.vector[i];
    
    return true;
}
