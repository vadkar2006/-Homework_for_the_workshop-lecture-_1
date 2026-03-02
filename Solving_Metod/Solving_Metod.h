#pragma once

#include <vector>
#include <algorithm>

#include "Vector/Vector.h"
#include "Task/Task.h" 

namespace Solving_Metod{


    template <class Q>
    inline std::vector<Vector> Generate_Step_1(const Vector& center){return std::vector<Vector>();}

    template <>
    inline std::vector<Vector> Generate_Step_1<Backpack>(const Vector& center){
        std::vector<Vector> Set(center.Dim(), center);

        for(int i = 0; i < center.Dim(); i++)
            Set[i][i] = !Set[i][i];
        
        return Set;
    }




    template <class Q>
    Vector Hill_Climbing(const Q& quest, const Vector& start){
        Vector total;
        total = start;

        int total_cost = quest.Cost_Finction(total);

        bool flag = true;
        while (flag){
            std::vector<Vector> next = Generate_Step_1<Q>(total);
            
            std::vector<int> next_cost(total.Dim());
            for(int i = 0; i < total.Dim(); i++)
                next_cost[i] = quest.Cost_Finction(next[i]);
            
            std::vector<int>::iterator max_it = std::max_element(next_cost.begin(), next_cost.end()); 
            size_t index = std::distance(next_cost.begin(), max_it);
            
            if(*max_it <= total_cost)
                flag = false;
            else{
                total = next[index];
                total_cost = quest.Cost_Finction(total);
            }
        }

        return total;
    }














}