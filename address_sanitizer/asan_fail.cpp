//
// Created by orell on 7/11/23.
//


int main()
{
    // stack buffer overflow
    int x[100];
    x[100] = 5; // Boom!
    return x[100];
}