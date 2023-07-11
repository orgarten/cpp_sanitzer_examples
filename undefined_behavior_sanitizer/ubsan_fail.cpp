//
// Created by orell on 7/11/23.
//

#include <numeric>

int main() {
    // divide by zero

    int a = 6/0;
    float b = 6.0/0.0; // This is not detected unless "float divide by zero" is activated, only relevant in clang

    // unsigned integer overflow
    unsigned int c = std::numeric_limits<unsigned int>::max() + 1;

    // implicit conversion
    int e = std::numeric_limits<int>::max() + 6;

    // bounds
    int d[100];
    d[100] = 5;

    return 0;
}