#ifndef ADVENTOFCODE_DAY05_H
#define ADVENTOFCODE_DAY05_H

#ifndef UTILS_H
#include "utils2025.h"
#endif

inline int Solver::Solve_Day05_part1() {
    std::string line;

    std::vector<std::pair<long, long>> ranges;

    // Ranges
    while (std::getline(file, line) && !line.empty()) {
        int range_break = line.find_first_of('-');
        long min = std::stol(line.substr(0, range_break));
        long max = std::stol(line.substr(range_break + 1));
        ranges.push_back(std::make_pair(min, max));
    }

    // Algorithm
    int counter = 0;
    while (std::getline(file, line)) {
        long value = std::stol(line);
        for (auto range : ranges) {
            if (value >= range.first && value <= range.second) {
                counter++;
                break;
            }
        }
    }

    return counter;
}


bool isEqual(const std::pair<int, int>& element1, std::pair<int, int>& element2)
{
    return element1.first ==  element2.first & element1.second ==  element2.second;
}

inline long Solver::Solve_Day05_part2() {
    std::string line;

    std::vector<std::pair<long, long>> ranges;
    std::set<size_t> overlapping;

    while (std::getline(file, line) && !line.empty()) {
        int range_break = line.find_first_of('-');
        long min = std::stol(line.substr(0, range_break));
        long max = std::stol(line.substr(range_break + 1));

        size_t count = 0;
        for (auto range : ranges) {
            if (min >= range.first && min <= range.second || max >= range.first && max <= range.second || min <= range.first && max >= range.second) {
                overlapping.insert(count); // store overlapping ranges separately
            }
            count++;
        }

        // Calculate new min and max from the ranges that are overlapping
        if (overlapping.size() > 0) {
            for (size_t idx : overlapping) {
                min = std::min(ranges[idx].first, min);
                max = std::max(ranges[idx].second, max);
            }
        }
        ranges.push_back(std::make_pair(min, max));

        // Delete ranges that were overlapping after replacement is added
        for (std::set<size_t>::reverse_iterator riter = overlapping.rbegin(); riter != overlapping.rend(); ++riter) {
            ranges.erase(ranges.begin() + *riter);
        }

        overlapping.clear();
    }

    // Calculate sum of all possible ids within ranges
    long sum = 0;
    for (auto range : ranges) {
        sum += range.second - range.first + 1;
    }

    return sum;
}

#endif //ADVENTOFCODE_DAY05_H