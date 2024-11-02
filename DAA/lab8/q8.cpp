#include <iostream>
#include <vector>
using namespace std;

// Function to compute the prefix function
vector<int> prefixFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// Function to find valid shifts using the prefix function
vector<int> validShiftsUsingPrefix(const string& P, const string& T) {
    vector<int> shifts;
    vector<int> pi = prefixFunction(P + "#" + T); // Concatenate pattern and text
    int m = P.size();
    
    for (int i = m + 1; i < pi.size(); i++) {
        if (pi[i] == m) shifts.push_back(i - 2 * m); // Calculate starting index of the match
    }
    return shifts;
}

int main() {
    string P, T;

    cout << "Enter the pattern string: ";
    cin >> P;
    cout << "Enter the text string: ";
    cin >> T;

    vector<int> shifts = validShiftsUsingPrefix(P, T);
    
    if (shifts.empty()) {
        cout << "No matches found." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int shift : shifts) {
            cout << shift << " ";
        }
        cout << endl;
    }

    return 0;
}
