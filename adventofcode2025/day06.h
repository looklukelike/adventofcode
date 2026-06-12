#ifndef ADVENTOFCODE_DAY06_H
#define ADVENTOFCODE_DAY06_H

#ifndef UTILS_H
#include "utils2025.h"
#endif

inline long Solver::Solve_Day06_part1() {
    std::string line;
    std::istringstream iss;

    std::vector<char> operators;
    std::vector<std::vector<int>> m;

    while (std::getline(file, line)) {
        iss = std::istringstream(line);
        std::vector<int> lineValues;
        int val;
        while (iss >> val) {
            lineValues.push_back(val);
        }
        if (!lineValues.empty()) {
            m.push_back(lineValues);
        }
    }

    char c;
    iss = std::istringstream(line);
    while (iss >> c) {
        operators.push_back(c);
    }

    long total = 0;
    for (size_t i = 0; i < operators.size(); i++) {
        char operation = operators[i];
        long lineRes = operation == '+' ? 0 : 1;
        for (auto & j : m) {
           if (operation == '+') {
               lineRes += j[i];
           } else {
               lineRes *= j[i];
           }
        }
        total += lineRes;
    }

    return total;
}

inline std::string removeSpaces(std::string input)
{
    std::erase(input,' ');
    return input;
}

inline long Solver::Solve_Day06_part2() {
    std::string line;
    std::unordered_map<size_t, std::string> map;
    std::vector<char> operators;

    while (std::getline(file, line)) {
        std::istringstream iss({line.begin(),line.end()});
        char c;
        while (iss.get(c)) {
            if (c == '+' || c == '*') {
                operators.push_back(c);
                continue;
            }
            map[iss.tellg()] += c;
        }
    }

    long totalSum = 0;
    std::vector<int> values;
    for (auto & it : map) {
        it.second = removeSpaces(it.second);
        if (it.second.empty()) {
            char operation = operators.back();
            operators.pop_back();

            long total = 0;
            if (operation == '+') {
                total = 0;
                for (int val : values) {
                    total += val;
                }
            } else if (operation == '*') {
                total = 1;
                for (int val : values) {
                    total *= val;
                }
            }
            totalSum += total;
            values.clear();
        } else {
            int value = std::stoi(it.second);
            values.push_back(value);
        }
    }

    // Register and calculate the last group of operations
    if (!values.empty()) {
        char operation = operators.back();
        operators.pop_back();

        long total = (operation == '+') ? 0 : 1;
        for (int val : values) {
            if (operation == '+') total += val;
            else total *= val;
        }
        totalSum += total;
    }

    return totalSum;
}


#endif //ADVENTOFCODE_DAY06_H