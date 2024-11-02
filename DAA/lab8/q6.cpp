#include <bits/stdc++.h>
using namespace std;

void searchPatterns(vector<string>& texts, vector<string>& patterns) {
    int n, m, j, k;
    j = texts.size();    
    k = patterns.size(); 
    n = texts[0].size(); 
    m = patterns[0].size();
    
    const int prime = 101;
    const int d = 256;
    
    vector<int> pattern_hash(k);
    int h = 1;
    
    for(int i = 0; i < m-1; i++)
        h = (h * d) % prime;
        
    for(int i = 0; i < k; i++) {
        int hash = 0;
        for(int j = 0; j < m; j++) {
            hash = (d * hash + patterns[i][j]) % prime;
        }
        pattern_hash[i] = hash;
    }
    
    for(int t = 0; t < j; t++) {
        int text_hash = 0;
        for(int i = 0; i < m; i++) {
            text_hash = (d * text_hash + texts[t][i]) % prime;
        }
        
        for(int i = 0; i <= n-m; i++) {
            for(int p = 0; p < k; p++) {
                if(pattern_hash[p] == text_hash) {
                    bool is_match = true;
                    for(int x = 0; x < m; x++) {
                        if(texts[t][i+x] != patterns[p][x]) {
                            is_match = false;
                            break;
                        }
                    }
                    if(is_match) {
                        cout << "Pattern " << p+1 << " found in Text " << t+1 
                             << " at position " << i << endl;
                    }
                }
            }
            
            if(i < n-m) {
                text_hash = (d * (text_hash - texts[t][i] * h) + 
                           texts[t][i+m]) % prime;
                if(text_hash < 0)
                    text_hash += prime;
            }
        }
    }
}

int main() {
    vector<string> texts = {
        "AABAACAADAABAAABAA",
        "AAAAABAAABA",
        "CCCCCCCCCC"
    };
    
    vector<string> patterns = {
        "AABA",
        "AAA",
        "CC"
    };
    
    searchPatterns(texts, patterns);
    return 0;
}