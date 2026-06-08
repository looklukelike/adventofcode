#include "adventofcode2025/day04.h"

int main() {
    std::cout << "Using C++ version " << __cplusplus << std::endl;
    std::string INPUTFILE = std::filesystem::path(__FILE__).parent_path().generic_string() + "/input.txt";

    Solver solver(INPUTFILE);
    long solution = solver.Solve_Day04_part2();
    std::cout << "The Solution is: " << solution << std::endl;

    return 0;
}