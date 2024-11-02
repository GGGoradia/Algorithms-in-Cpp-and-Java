#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> validShifts(const string& T, const string& P) {
    vector<int> valid_positions;
    string modified_P;

    for (char ch : P) {
        if (ch != '#') {
            modified_P += ch;
        }
    }

    int n = T.length();
    int m = modified_P.length();

    for (int i = 0; i <= n - m; i++) {
        int p_index = 0;
        for (int j = i; j < n; j++) {
            if (p_index < m && T[j] == modified_P[p_index]) {
                p_index++;
            }
            if (p_index == m) {
                valid_positions.push_back(i);
                break;
            }
            if (P[p_index] == '#') {
                continue;
            }
        }
    }

    return valid_positions;
}

int main() {
    string text = "ababcabc";
    string pattern = "ab#ba#c";  // Use # or any other symbol you prefer
    vector<int> shifts = validShifts(text, pattern);

    cout << "Valid shifts: ";
    for (int shift : shifts) {
        cout << shift << " ";
    }
    cout << endl;

    return 0;
}
