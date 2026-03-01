#include <string>
#include "Class.cpp"


template <class Metod>
void Solve_Backpack_Problem(std::string input){
    std::string way("Data/data_1/");

    std::ifstream file(way + input);
    if(!file.is_open()){
        std::cout << "Not Open file " << input << " for way " << way << std::endl;
        return;
    }
    Metod solve;
    Backpack quest(file);

    int dim = quest.Get_Count_Items();

    int mas[] = {1, 0, 1, 0};
    Vector start(4, mas);

    Vector resh = solve.Gradient_Descent_Max(quest, start);

    resh.Print();
}