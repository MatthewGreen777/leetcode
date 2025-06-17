/*
leetcode problem #50: Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
*/

#include <iostream>

double myPow(double x, int n) {
    long long num = n;
    if (num == 0) {
        return 1.0;
    }

    if (num < 0) {
        x = 1.0 / x;
        num = -num; 
    }

    double val = myPow(x, num / 2);
    if (num % 2 == 0) {
        return val * val;
    } else {
        return val * val * x;
    }

    return val;
}