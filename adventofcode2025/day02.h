#ifndef ADVENTOFCODE_DAY02_H
#define ADVENTOFCODE_DAY02_H

#ifndef UTILS_H
#include "utils2025.h"
#endif

inline long Solver::Solve_Day02_part1() {
    std::string pattern;
    long count = 0;

    while (std::getline(file, pattern, ',')) {
        std::string::size_type pos = pattern.find('-');
        std::pair<long, long> range  = std::make_pair(std::stol(pattern.substr(0, pos)), std::stol(pattern.substr(pos + 1, pattern.length())));

        std::cout << range.first << " " << range.second << std::endl; //debug

        long* p = &range.first;
        std::string s;
        while (*p <= range.second) {
            s = std::to_string(*p);
            if (s.length() % 2 == 0) {
                pos = s.length() / 2;

                if (s.substr(0, pos) == s.substr(pos, s.length())) {
                    count += std::stol(s);
                }

            }
            *p += 1;
        }
    }

    return count;
}

inline std::vector<int> findDivisorsOfNumber(size_t n) {
    std::vector<int> divisors;

    if (n < 2) {
        return divisors;
    }

    for (size_t i = 2; i <= (n / 2) + 1; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }

    divisors.push_back(n);

    return divisors;
}

inline long Solver::Solve_Day02_part2() {
    std::string pattern;
    long count = 0;

    while (std::getline(file, pattern, ',')) {
        std::string::size_type pos = pattern.find('-');
        std::pair<long, long> range  = std::make_pair(std::stol(pattern.substr(0, pos)), std::stol(pattern.substr(pos + 1, pattern.length())));

        std::cout << range.first << " " << range.second << std::endl; //debug

        long* p = &range.first;
        std::string st;
        std::vector<int> divisors;
        while (*p <= range.second) {
            st = std::to_string(*p);
            divisors = findDivisorsOfNumber(st.length());

            std::string st1 = "";
            std::string st2 = "";
            int len;
            bool valid = true;
            for (int divisor : divisors) {

                valid = true;

                len = st.length() / divisor;
                int strt = 0;
                st1 = st.substr(strt, strt + len);

                for (int i = 0; i < divisor - 1; i++) {
                    strt = strt + len;
                    st2 = st.substr(strt, len);

                    if (st2 == st1) {
                        valid = false;
                    } else {
                        valid = true;
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
            }

            if (!valid) {
                std::cout << "Invalid: "<< st << std::endl;
                count += std::stol(st);
            }
            *p += 1;
        }
    }

    return count;
}

#endif //ADVENTOFCODE_DAY02_H