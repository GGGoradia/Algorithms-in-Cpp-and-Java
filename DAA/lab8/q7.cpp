#include <iostream>
#include <string>
using namespace std;

bool isCyclicRotation(string T, string T_prime) {
    return T.size() == T_prime.size() && (T + T).find(T_prime) != string::npos;
}
