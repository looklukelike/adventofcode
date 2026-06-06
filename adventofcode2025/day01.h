#ifndef ADVENTOFCODE_DAY01_H
#define ADVENTOFCODE_DAY01_H

#ifndef UTILS_H
#include "utils2025.h"
#endif

inline int Solver::Solve_Day01_part1() {
    int zeros = 0;
    int pos = 50;
    std::string line;
    char direction;
    int command;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        iss >> token;

        direction = token[0];
        command = std::stoi(token.substr(1)) % 100;

        switch (direction) {
            case 'L':
                command = -command;
            case 'R':
                command = command * 1;
        }

        pos += command;

        if (pos < 0) {
            pos += 100;
        } else if (pos >= 100) {
            pos = pos % 100;
        }

        if (pos == 0) {
            zeros++;
        }
    }

    return zeros;
}

inline int Solver::Solve_Day01_part2() {
    int zeros = 0;
    int pos = 50;
    std::string line;
    char direction;
    int command;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        iss >> token;

        direction = token[0];
        command = std::stoi(token.substr(1)) % 100;
        zeros += std::stoi(token.substr(1)) / 100;

        switch (direction) {
            case 'L':
                command = -command;
            case 'R':
                command = command * 1;
        }

        pos += command;

        if (pos < 0) {
            if (pos - command != 0) {
                zeros++;
            }
            pos += 100;
        } else if (pos >= 100) {
            if (pos != 100) {
                zeros++;
            }
            pos = pos % 100;
        }

        if (pos == 0) {
            zeros++;
        }

    }

    return zeros;
}
#endif //ADVENTOFCODE_DAY01_H