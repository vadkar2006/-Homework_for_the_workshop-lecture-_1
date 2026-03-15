#include <iostream>
#include <thread>
#include <random>

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
        bool best = false;
        double best_cost = total_cost;
        Vector best_total;

        for(int i = 0; i < total.Dim() - 1; i++)
            for(int j = i + 2; j < total.Dim(); j++){
                Vector first = total.Slice(0, i);
                Vector second = total.Slice(i, j, true);
                Vector third = total.Slice(j, total.Dim());

                Vector new_total = first.Concatenation(second.Concatenation(third));
                double new_cost = quest.Cost_Finction(new_total);

                if(new_cost < best_cost){
                    best = true;
                    best_cost = new_cost;
                    best_total = new_total;
                }
            }
        
        if(!best)
            flag = false;
        else{
            total = best_total;
            total_cost = best_cost;
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
        bool best = false;
        double best_cost = total_cost;
        Vector best_total;

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

                    double new_cost_1 = quest.Cost_Finction(new_total_1);
                    double new_cost_2 = quest.Cost_Finction(new_total_2);
                    double new_cost_3 = quest.Cost_Finction(new_total_3);
                    double new_cost_4 = quest.Cost_Finction(new_total_4);
                    double new_cost_5 = quest.Cost_Finction(new_total_5);

                    if(new_cost_1 < best_cost){
                        best = true;
                        best_cost = new_cost_1;
                        best_total = new_total_1;
                    }
                    if(new_cost_2 < best_cost){
                        best = true;
                        best_cost = new_cost_2;
                        best_total = new_total_2;
                    }
                    if(new_cost_3 < best_cost){
                        best = true;
                        best_cost = new_cost_3;
                        best_total = new_total_3;
                    }
                    if(new_cost_4 < best_cost){
                        best = true;
                        best_cost = new_cost_4;
                        best_total = new_total_4;
                    }
                    if(new_cost_5 < best_cost){
                        best = true;
                        best_cost = new_cost_5;
                        best_total = new_total_5;
                    }
                }
        
        if(!best)
            flag = false;
        else{
            total = best_total;
            total_cost = best_cost;
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




Vector Solving_Metod::Parallel_Random_Start::Hill_Climbing(const Backpack& quest, const Vector& start){
    std::vector<Vector> starts (Solving_Metod::Count_Parallel_Stream, Vector(quest.Get_Count_Items()));
    std::vector<Vector> ans (Solving_Metod::Count_Parallel_Stream);
    std::vector<int> costs (Solving_Metod::Count_Parallel_Stream);

    starts[0] = start;

    double min_vol_count = double(quest.Get_Max_Volume()) / double(quest.Y(quest.Max_Volume_Item_Index()));
    double max_vol_count = double(quest.Get_Max_Volume()) / double(quest.Y(quest.Min_Volume_Item_Index()));

    long sum = 0;
    for(int i = 0; i < quest.Get_Count_Items(); i++)
        sum += quest.Y(i);
    
    double average_count = double(quest.Get_Max_Volume()) / (sum / double(quest.Get_Count_Items()));

    double percent_min = min_vol_count / quest.Get_Count_Items() * 100;
    double percent_ave = average_count / quest.Get_Count_Items() * 100;
    double percent_max = max_vol_count / quest.Get_Count_Items() * 100;

    if(percent_max > 100)
        percent_max = 100;


    std::normal_distribution<> Norm(percent_ave, percent_ave/3);
    std::random_device rd;
    std::mt19937 gen(rd());


    for(int i = 1; i < Solving_Metod::Count_Parallel_Stream; i++){
        double perc = Norm(gen);
        starts[i].Random_Binary(perc);
    }


    auto rand_start = [] (const Backpack& quest, const Vector& start, Vector& total, int& cost){
        total = Solving_Metod::Best_Improvement::Hill_Climbing(quest, start);
        cost = quest.Cost_Finction(total);
    };

    std::vector<std::thread> threads;

    for(int i = 0; i < Solving_Metod::Count_Parallel_Stream; i++)
        threads.emplace_back(rand_start, std::ref(quest), std::ref(starts[i]), std::ref(ans[i]), std::ref(costs[i]));
    
    for(int i = 0; i < Solving_Metod::Count_Parallel_Stream; i++)
        threads[i].join();
    
    int max_i = 0;
    for(int i = 0; i < Solving_Metod::Count_Parallel_Stream; i++)
        if(costs[max_i] < costs[i])
            max_i = i;
    
    return ans[max_i];
}