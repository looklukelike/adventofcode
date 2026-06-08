#ifndef ADVENTOFCODE_DAY04_H
#define ADVENTOFCODE_DAY04_H

#ifndef UTILS_H
#include "utils2025.h"
#endif

struct Matrix {
    unsigned int dimX, dimY;
    std::vector<char> m;

    Matrix (unsigned int l, unsigned int h) {
        dimX = l;
        dimY = h;
        m.resize(dimY * dimX);
    }

    char& operator()(unsigned int x, unsigned int y) {
        if (x >= dimX || y>= dimY)
            throw std::out_of_range("matrix indices out of range");
        return m[dimY * y + x];
    }

    void print() {
        for (size_t y = 0; y < dimY; y++) {
            for (size_t x = 0; x < dimX; x++) {
                std::cout << m[dimY * y + x];
            }
            std::cout << std::endl;
        }
    }
    ~Matrix () {};

};

inline int Solver::Solve_Day04_part1() {
    std::string line;
    int width = 0, height = 0;

    while (std::getline(file, line)) {
        if (width == 0) {
            for (char c : line) {
                ++width;
            }
        }
        ++height;
    }

    file.clear();
    file.seekg(0);

    Matrix m = Matrix(width, height);

    int x = 0, y = 0;
    while (std::getline(file, line)) {
        for (x = 0; x < line.length(); ++x) {
            m(x, y) = line[x];
        }
        ++y;
    }

    m.print();

    int count = 0;
    int rolls = 0;
    int _x, _y;
    std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            if (m(x, y) == '@') {
                rolls = 0;
                for (int d = 0; d < directions.size(); ++d) {
                    _x = x + directions[d].first;
                    _y = y + directions[d].second;
                    if (0 <= _x && _x < width && 0 <= _y && _y < height) {
                        if (m(_x, _y) == '@') {
                            rolls++;
                        }
                    }
                }

                if (rolls < 4) {
                    count++;
                }
            }
        }
    }

    return count;
}

inline int Solver::Solve_Day04_part2() {
    std::string line;
    int width = 0, height = 0;

    while (std::getline(file, line)) {
        if (width == 0) {
            for (char c : line) {
                ++width;
            }
        }
        ++height;
    }

    file.clear();
    file.seekg(0);

    Matrix m = Matrix(width, height);

    int x = 0, y = 0;
    while (std::getline(file, line)) {
        for (x = 0; x < line.length(); ++x) {
            m(x, y) = line[x];
        }
        ++y;
    }

    m.print();

    int totalRolls = 0;
    std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    std::vector<std::pair<int,int>> toRemove;
    while (true) {
        int count = 0;
        int rolls = 0;
        int _x, _y;

        for (y = 0; y < height; ++y) {
            for (x = 0; x < width; ++x) {
                if (m(x, y) == '@') {
                    rolls = 0;
                    for (int d = 0; d < directions.size(); ++d) {
                        _x = x + directions[d].first;
                        _y = y + directions[d].second;
                        if (0 <= _x && _x < width && 0 <= _y && _y < height) {
                            if (m(_x, _y) == '@') {
                                rolls++;
                            }
                        }
                    }

                    if (rolls < 4) {
                        toRemove.push_back({x, y});
                        count++;
                    }
                }
            }
        }

        for (auto& p : toRemove) {
            m(p.first, p.second) = '.';
        }


        if (count == 0) {
            break;
        }

        totalRolls += count;
    }

    return totalRolls;
}

#endif //ADVENTOFCODE_DAY04_H