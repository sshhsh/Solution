//
// Created by cebiao zhu on 2018/7/6.
//
#include <iostream>

long pow10(long a) {
    long r = 1;
    while (a--) {
        r *= 10;
    }
    return r;
}


int findNthDigit(int n) {
    long m = 9, i = 1;
    while (n > m * i) {
        n -= m * i;
        m *= 10;
        ++i;
    }
    long t = (n % i == 0) ? (n / i) : (n / i + 1);
    long index_of_ith_number = m / 9 - 1 + t;
    long index_in_the_number = n % i;
    if (index_in_the_number == 0)
        index_in_the_number = i;

    int res = (int) ((index_of_ith_number / (pow10(i - index_in_the_number))) % 10);
    return res;
}


int main400() {
    std::cout << findNthDigit(100000000);
    return 0;
}
