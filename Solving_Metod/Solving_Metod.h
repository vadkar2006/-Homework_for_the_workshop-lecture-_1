#pragma once

#include <vector>
#include <algorithm>

#include "Vector/Vector.h"
#include "Task/Task.h" 

namespace Solving_Metod{

    namespace Best_Improvement{
        Vector Hill_Climbing(const Backpack& quest, const Vector& start);


        Vector _2_Optimization (const TSP& quest, const Vector& start);
        Vector _3_Optimization (const TSP& quest, const Vector& start);

        Vector _2_3_Optimization (const TSP& quest, const Vector& start);
    }

    namespace First_Improvement{
        Vector _3_Optimization (const TSP& quest, const Vector& start);
    }
}