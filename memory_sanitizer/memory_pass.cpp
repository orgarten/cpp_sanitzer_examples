//
// Created by orell on 7/11/23.
//

#include <iostream>

int main()
{
    int *ptr = new int[10];
    for (int i = 0; i <= 9; i++)
        ptr[i] = 0;

    if (ptr[4] == 5)
        return 1;

    return 0;
}