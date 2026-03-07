#include <iostream>

#include "Solving_Metod.h"


Vector Solving_Metod::Best_Improvement::Hill_Climbing (const Backpack& quest, const Vector& start){
    Vector total;
    total = start;

    int total_cost = quest.Cost_Finction(total);

    bool flag = true;
    while (flag){
        int best_index = -1;
        int best_cost = total_cost;

        for(int i = 0; i < total.Dim(); i++){
            total[i] = !total[i];

            int new_cost = quest.Cost_Finction(total);
        
            if(new_cost > best_cost){
                best_index = i;
                best_cost = new_cost;
            }

            total[i] = !total[i];
        }

        if(best_index == -1)
            flag = false;
        else{
            total[best_index] = !total[best_index];
            total_cost = best_cost;
        }
    }

    return total;
}


Vector Solving_Metod::Best_Improvement::_2_Optimization (const TSP& quest, const Vector& start){
    Vector total;
    total = start;

    double total_cost = quest.Cost_Finction(total);

    bool flag = true;
    while (flag){
        std::vector<Vector> next;

        for(int i = 0; i < total.Dim() - 1; i++)
            for(int j = i + 2; j < total.Dim(); j++){
                Vector first = total.Slice(0, i);
                Vector second = total.Slice(i, j, true);
                Vector third = total.Slice(j, total.Dim());

                Vector new_total = first.Concatenation(second.Concatenation(third));
                next.push_back(new_total);
            }
                
        std::vector<double> next_cost(next.size());
        for(int i = 0; i < next.size(); i++)
            next_cost[i] = quest.Cost_Finction(next[i]);
        
        std::vector<double>::iterator min_it = std::min_element(next_cost.begin(), next_cost.end()); 
        size_t index = std::distance(next_cost.begin(), min_it);
        
        if(*min_it >= total_cost)
            flag = false;
        else{
            total = next[index];
            total_cost = quest.Cost_Finction(total);
        }
    }

    return total;
}

Vector Solving_Metod::Best_Improvement::_3_Optimization (const TSP& quest, const Vector& start){
    Vector total;
    total = start;

    double total_cost = quest.Cost_Finction(total);

    bool flag = true;
    while (flag){
        std::vector<Vector> next;

        for(int i = 0; i < total.Dim(); i++)
            for(int j = i + 2; j < total.Dim(); j++)
                for(int k = j + 2; k < total.Dim(); k++){
                    Vector first = total.Slice(0, i);
                    Vector second = total.Slice(i, j);
                    Vector third = total.Slice(j, k);
                    Vector fourth = total.Slice(k, total.Dim());

                    Vector second_inv = total.Slice(i, j, true);
                    Vector third_inv = total.Slice(i, k, true);


                    Vector new_total_1 = first.Concatenation(second_inv.Concatenation(third.Concatenation(fourth)));
                    Vector new_total_2 = first.Concatenation(second.Concatenation(third_inv.Concatenation(fourth)));
                    Vector new_total_3 = first.Concatenation(third.Concatenation(second.Concatenation(fourth)));
                    Vector new_total_4 = first.Concatenation(third_inv.Concatenation(second.Concatenation(fourth)));
                    Vector new_total_5 = first.Concatenation(third.Concatenation(second_inv.Concatenation(fourth)));

                    next.push_back(new_total_1);
                    next.push_back(new_total_2);
                    next.push_back(new_total_3);
                    next.push_back(new_total_4);
                    next.push_back(new_total_5);
                }
                
        std::vector<double> next_cost(next.size());
        for(int i = 0; i < next.size(); i++)
            next_cost[i] = quest.Cost_Finction(next[i]);
        
        std::vector<double>::iterator min_it = std::min_element(next_cost.begin(), next_cost.end()); 
        size_t index = std::distance(next_cost.begin(), min_it);
        
        if(*min_it >= total_cost)
            flag = false;
        else{
            total = next[index];
            total_cost = quest.Cost_Finction(total);
        }
    }

    return total;
}

Vector Solving_Metod::Best_Improvement::_2_3_Optimization(const TSP& quest, const Vector& start){
    Vector first = Solving_Metod::Best_Improvement::_2_Optimization(quest, start);

    Vector end = Solving_Metod::Best_Improvement::_3_Optimization(quest, first);

    return end;
}


Vector Solving_Metod::First_Improvement::_3_Optimization (const TSP& quest, const Vector& start){
    Vector total;
    total = start;

    double total_cost = quest.Cost_Finction(total);

    bool flag = true;
    while (flag){

        bool flag1 = true;
        for(int i = 0; (i < total.Dim()) && flag1; i++)
            for(int j = i + 2; (j < total.Dim()) && flag1; j++)
                for(int k = j + 2; (k < total.Dim()) && flag1; k++){
                    Vector first = total.Slice(0, i);
                    Vector second = total.Slice(i, j);
                    Vector third = total.Slice(j, k);
                    Vector fourth = total.Slice(k, total.Dim());

                    Vector second_inv = total.Slice(i, j, true);
                    Vector third_inv = total.Slice(i, k, true);

                    std::vector<Vector> mas_vec(5);
                    mas_vec[0] = first.Concatenation(second_inv.Concatenation(third.Concatenation(fourth)));
                    mas_vec[1] = first.Concatenation(second.Concatenation(third_inv.Concatenation(fourth)));
                    mas_vec[2] = first.Concatenation(third.Concatenation(second.Concatenation(fourth)));
                    mas_vec[3] = first.Concatenation(third_inv.Concatenation(second.Concatenation(fourth)));
                    mas_vec[4] = first.Concatenation(third.Concatenation(second_inv.Concatenation(fourth)));

                    std::vector<double> mas_cost(5);
                    mas_cost[0] = quest.Cost_Finction(mas_vec[0]);
                    mas_cost[1] = quest.Cost_Finction(mas_vec[1]);
                    mas_cost[2] = quest.Cost_Finction(mas_vec[2]);
                    mas_cost[3] = quest.Cost_Finction(mas_vec[3]);
                    mas_cost[4] = quest.Cost_Finction(mas_vec[4]);

                    double min_cost = mas_cost[0];
                    int q = 0;
                    for(int i = 1; i < 5; i++)
                        if(min_cost > mas_cost[i]){
                            min_cost = mas_cost[i];
                            q = i;
                        }
                    
                    if(min_cost < total_cost){
                        total = mas_vec[q];
                        total_cost = mas_cost[q];

                        flag1 = false;
                    }
                        
                }
        //std::cout << total_cost << std::endl;

        if(flag1)
            flag = false;
    }

    return total;
}



