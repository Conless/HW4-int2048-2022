/*
Time: 2021-10-20
Test: add & minus (unsigned)
std Time: 0.13s
Time Limit: 1.00s
*/

#include "int2048/int2048.h"

sjtu::int2048 a, b;
std::string s1, s2;

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> s1 >> s2;
        a.read(s1); b.read(s2);
        minus(a, b).print(); puts("");
        a.minus(b).print(); puts("");
        (add(a, b)).minus(a.add(b).minus(a).add(b)).print(); puts("");
    }
}