#pragma once

#include "Vector/Vector.h"  

template <class Q>
struct Solving{
    Vector Gradient_Descent_Max(const Q& quest, const Vector& start);

};


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


