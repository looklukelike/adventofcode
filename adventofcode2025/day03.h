#ifndef ADVENTOFCODE_DAY03_H
#define ADVENTOFCODE_DAY03_H

#ifndef UTILS_H
#include "utils2025.h"
#endif

inline int Solver::Solve_Day03_part1() {
    std::string line;
    int sum = 0;

    while (std::getline(file, line)) {

        std::pair<int, int> digits = std::make_pair(0, 0);
        int digit = 0;
        for (int i = 0; i < line.size() - 1; i++) {
            digit = line[i] - '0';
            if (digit > digits.first) {
                digits.first = digit;
                digits.second = 0;
            } else if (digit > digits.second) {
                digits.second = digit;
            }
        }

        digit = line.at(line.length() - 1) - '0';
        if (digit > digits.second) digits.second = digit;

        line = std::to_string(digits.first) + std::to_string(digits.second);
        sum += std::stoi(line);
    }

    return sum;
}

inline long Solver::Solve_Day03_part2() {
    std::string line;
    long sum = 0;

    while (std::getline(file, line)) {
        std::string digits = "";
        size_t remaining = 12;
        size_t pos = 0;
        int best = 0;
        size_t bestIndex = 0;
        while (remaining > 0) {
            size_t windowEnd = line.length() - remaining;
            best = 0;
            bestIndex = pos;
            for (size_t i = pos; i <= windowEnd; i++) {
                if (line.at(i) - '0' > best) {
                    best = line.at(i) - '0';
                    bestIndex = i;
                }
            }

            digits += line.at(bestIndex);
            pos = bestIndex + 1;
            remaining--;
        }

        sum += std::stol(digits);
    }

    return sum;
}

#endif //ADVENTOFCODE_DAY03_H