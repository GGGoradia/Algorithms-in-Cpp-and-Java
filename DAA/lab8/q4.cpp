#include <iostream>
#include <string>
using namespace std;

int computeRepetitiveFactor(string x) {
    int n = x.size(), factor = 1;
    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) {
            string repeated = "";
            string substring = x.substr(0, len);
            
            // Repeat the substring (n / len) times
            for (int i = 0; i < n / len; i++) {
                repeated += substring;
            }
            
            if (repeated == x) {
                factor = max(factor, n / len);
            }
        }
    }
    return factor;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int repetitiveFactor = computeRepetitiveFactor(input);
    cout << "Repetitive factor of the string \"" << input << "\" is: " << repetitiveFactor << endl;

    return 0;
}
