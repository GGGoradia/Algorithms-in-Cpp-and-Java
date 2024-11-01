#include <iostream>
#include <string>
using namespace std;

int computeRepetitiveFactor(string x) {
    int n = x.size(), factor = 1;
    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0 && x.substr(0, len) * (n / len) == x) factor = max(factor, n / len);
    }
    return factor;
}
