#include "../include/BigInteger/int2048.h"

using sjtu::int2048;
using std::cin;
using std::cout;

int main() {
    while (true) {
        int2048 a, b;
        cin >> a >> b;
        a.minus(b);
        cout << a << '\n';
    }
    return 0;
}