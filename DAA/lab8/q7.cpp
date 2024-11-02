#include <iostream>
#include <string>
using namespace std;

bool isCyclicRotation(const string& T, const string& T_prime) {
    return T.size() == T_prime.size() && (T + T).find(T_prime) != string::npos;
}

int main() {
    string T, T_prime;

    cout << "Enter the first string: ";
    cin >> T;
    cout << "Enter the second string: ";
    cin >> T_prime;

    if (isCyclicRotation(T, T_prime)) {
        cout << T_prime << " is a cyclic rotation of " << T << "." << endl;
    } else {
        cout << T_prime << " is not a cyclic rotation of " << T << "." << endl;
    }

    return 0;
}
