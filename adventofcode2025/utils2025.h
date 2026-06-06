#ifndef ADVENTOFCODE_UTILS2025_H
#define ADVENTOFCODE_UTILS2025_H

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

class Solver {
   protected:
    std::fstream file;
    std::string fileInput;

   public:
    Solver() {}

    Solver(const std::string& _fileInput) : fileInput(_fileInput) {
        this->file.open(_fileInput);

        std::cout << "Input file: " << _fileInput << std::endl;
    }

    virtual ~Solver() { this->file.close(); };

    void Print(std::string& str) { std::cout << str << std::endl; }

    int Solve_Day01_part1();
    int Solve_Day01_part2();

    long Solve_Day02_part1();
    long Solve_Day02_part2();
};

namespace utils {

}  // namespace utils

#endif //ADVENTOFCODE_UTILS2025_H