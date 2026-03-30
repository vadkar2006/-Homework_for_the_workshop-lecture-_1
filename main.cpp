#include <iostream>

#include "Vector/Vector.h"       
#include "Task/Task.h"
#include "Solving_Metod/Solving_Metod.h"  
#include "Test/Test.h"    





void Test_Data_Backpack(){
    
    std::cout << "Problem 1" << std::endl;
    Solve_Backpack_Problem("ks_4_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 2" << std::endl;
    Solve_Backpack_Problem("ks_19_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 3" << std::endl;
    Solve_Backpack_Problem("ks_30_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 4" << std::endl;
    Solve_Backpack_Problem("ks_40_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 5" << std::endl;
    Solve_Backpack_Problem("ks_45_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;



    std::cout << "Problem 6" << std::endl;
    Solve_Backpack_Problem("ks_50_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 7" << std::endl;
    Solve_Backpack_Problem("ks_50_1", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 8" << std::endl;
    Solve_Backpack_Problem("ks_60_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 9" << std::endl;
    Solve_Backpack_Problem("ks_100_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 10" << std::endl;
    Solve_Backpack_Problem("ks_100_1", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;



    std::cout << "Problem 11" << std::endl;
    Solve_Backpack_Problem("ks_100_2", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 12" << std::endl;
    Solve_Backpack_Problem("ks_200_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 13" << std::endl;
    Solve_Backpack_Problem("ks_200_1", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 14" << std::endl;
    Solve_Backpack_Problem("ks_300_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 15" << std::endl;
    Solve_Backpack_Problem("ks_400_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;



    std::cout << "Problem 16" << std::endl;
    Solve_Backpack_Problem("ks_500_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 17" << std::endl;
    Solve_Backpack_Problem("ks_1000_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;

    std::cout << "Problem 18" << std::endl;
    Solve_Backpack_Problem("ks_10000_0", Solving_Metod::Parallel_Random_Start::Hill_Climbing);
    std::cout << std::endl;
}



void Test_Data_TSP(){
    std::cout << "Problem 1" << std::endl;
    Solve_TSP_Problem("tsp_7_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_7_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 2" << std::endl;
    Solve_TSP_Problem("tsp_51_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_51_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 3" << std::endl;
    Solve_TSP_Problem("tsp_70_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_70_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 4" << std::endl;
    Solve_TSP_Problem("tsp_76_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_76_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 5" << std::endl;
    Solve_TSP_Problem("tsp_76_2", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_76_2", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;



    std::cout << "Problem 6" << std::endl;
    Solve_TSP_Problem("tsp_99_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_99_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 7" << std::endl;
    Solve_TSP_Problem("tsp_100_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_100_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 8" << std::endl;
    Solve_TSP_Problem("tsp_100_2", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_100_2", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 9" << std::endl;
    Solve_TSP_Problem("tsp_100_3", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_100_3", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 10" << std::endl;
    Solve_TSP_Problem("tsp_100_4", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_100_4", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;



    std::cout << "Problem 11" << std::endl;
    Solve_TSP_Problem("tsp_100_5", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_100_5", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 12" << std::endl;
    Solve_TSP_Problem("tsp_100_6", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_100_6", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 13" << std::endl;
    Solve_TSP_Problem("tsp_101_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_101_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 14" << std::endl;
    Solve_TSP_Problem("tsp_105_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_105_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 15" << std::endl;
    Solve_TSP_Problem("tsp_107_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_107_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;



    std::cout << "Problem 16" << std::endl;
    Solve_TSP_Problem("tsp_124_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_124_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 17" << std::endl;
    Solve_TSP_Problem("tsp_127_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_127_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 18" << std::endl;
    Solve_TSP_Problem("tsp_136_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_136_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 19" << std::endl;
    Solve_TSP_Problem("tsp_144_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_144_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;

    std::cout << "Problem 20" << std::endl;
    Solve_TSP_Problem("tsp_150_1", Solving_Metod::Best_Improvement::_2_Optimization);
    std::cout << std::endl;
    Solve_TSP_Problem("tsp_150_1", Solving_Metod::Parallel_Random_Start::_2_3_Optimization);
    std::cout << std::endl << std::endl;
}



int main(){
    Test_Data_Backpack();
    //Test_Data_TSP();


    /*
    std::ifstream file("../Data/data_1/ks_10000_0");
    Backpack back(file);

    Vector start(back.Get_Count_Items());
    start.Random_Binary(0.006);
    back.Solve(Solving_Metod::Best_Improvement::Hill_Climbing, start);*/
    
    return 0;
}

