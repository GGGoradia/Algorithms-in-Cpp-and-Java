#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void generateSubsequences(const string &str, vector<string> &subsequences) {
    int n = str.length();
    int total = pow(2, n);
    
    for (int i = 0; i < total; i++) {
        string subsequence = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subsequence += str[j];
            }
        }
        subsequences.push_back(subsequence);
    }
}

vector<string> computeCommonSubsequences(const vector<string> &subsequences_X, const vector<string> &subsequences_Y) {
    vector<string> commonSubsequences;
    
    for (const string &subseq_X : subsequences_X) {
        for (const string &subseq_Y : subsequences_Y) {
            if (subseq_X == subseq_Y && find(commonSubsequences.begin(), commonSubsequences.end(), subseq_X) == commonSubsequences.end()) {
                commonSubsequences.push_back(subseq_X);
            }
        }
    }
    
    return commonSubsequences;
}

string findLongestCommonSubsequence(const vector<string> &commonSubsequences) {
    string longest_common_subsequence = "";
    
    for (const string &subseq : commonSubsequences) {
        if (subseq.length() > longest_common_subsequence.length()) {
            longest_common_subsequence = subseq;
        }
    }
    
    return longest_common_subsequence;
}

int main() {
    string X, Y;
    
    cout << "Enter the first sequence (X): ";
    cin >> X;
    
    cout << "Enter the second sequence (Y): ";
    cin >> Y;
    
    vector<string> subsequences_X, subsequences_Y;
    
    generateSubsequences(X, subsequences_X);
    generateSubsequences(Y, subsequences_Y);
    
    vector<string> commonSubsequences = computeCommonSubsequences(subsequences_X, subsequences_Y);
    string longest_common_subsequence = findLongestCommonSubsequence(commonSubsequences);
    
    if (!longest_common_subsequence.empty()) {
        cout << "The longest common subsequence is: " << longest_common_subsequence << endl;
    } else {
        cout << "No common subsequence found." << endl;
    }
    
    return 0;
}
