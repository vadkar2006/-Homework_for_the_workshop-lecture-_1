#include "Class.h"


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


Backpack::Backpack(std::ifstream& file){
    file >> this -> Count_Items >> this -> Max_Volume;

    Items = new int*[2];
    Items[0] = new int[this -> Count_Items];
    Items[1] = new int[this -> Count_Items];

    for(int i = 0; i < this -> Count_Items; i++)
        file >> Items[0][i] >> Items[1][i];
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








template <class Q>
Vector Solving<Q>::Gradient_Descent_Max(const Q& quest, const Vector& start){
    Vector total;
    total = start;

    int value_grad = quest.Cost_Finction(total);


    for(int i = 0; i < start.Dim(); i++){
        bool flag = true;

        while(flag){

            ++total[i];
            int value_grad_plus = quest.Cost_Finction(total);
            ----total[i];
            int value_grad_minus = quest.Cost_Finction(total);
            ++total[i];


            if((value_grad_minus < value_grad) && (value_grad < value_grad_plus))
                total[i]++;
            
            else if((value_grad_plus < value_grad) && (value_grad < value_grad_minus))
                total[i]--;
            
            else if((value_grad <= value_grad_plus) && (value_grad <= value_grad_minus) && (value_grad_plus < value_grad_minus))
                total[i]--;

            else if((value_grad <= value_grad_plus) && (value_grad <= value_grad_minus) && (value_grad_minus <= value_grad_plus))
                total[i]++;

            else if((value_grad_plus <= value_grad) && (value_grad_minus <= value_grad))
                flag = false;
            
            else flag = false;
            
            value_grad = quest.Cost_Finction(total);
        }
    }

    return total;
}

