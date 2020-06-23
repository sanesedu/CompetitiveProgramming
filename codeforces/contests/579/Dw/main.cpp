
#include <iostream> 
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

void kmp_array(string pat, long long M, long long* lps); 
  
vector<long long> kmp_search(string pat, string txt) { 

    vector<long long> v;

    long long M = pat.length(); 
    long long N = txt.length(); 
  
    long long lps[M]; 
  
    kmp_array(pat, M, lps); 
  
    long long i = 0;
    long long j = 0; 

    long long mx = -1;
    long long min = LONG_MAX;

    while (i < N) { 
        if (pat[j] == txt[i]) { 
            ++j; 
            ++i; 
        } 
  
        if (j == M) { 
            if(i - j > mx) mx = i-j;
            if(i - j < min) min = i-j;
            j = 0;
        } else if (i < N && pat[j] != txt[i]) { 
            if (j != 0)  j = lps[j - 1]; 
            else i = i + 1; 
        } 
    } 

    v.push_back(min);
    v.push_back(mx);

    return v;
} 
  
void kmp_array(string pat, long long M, long long* lps) { 
    
    long long len = 0; 
  
    lps[0] = 0; 
  
    long long i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } else { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } else { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
  
int main() { 
    
    string txt, pat;

    cin >> txt >> pat; 

    vector<long long> v;
    v  = kmp_search(pat, txt);

    long long min = v[0];
    long long mx = v[1];

    long long i = min;
    long long j = txt.length() - (min + pat.length());

    long long res = max(i, j);

    i = mx;
    j = txt.length() - (mx + pat.length());

    long long res2 = max(i, j);

    res = max(res, res2);

    cout << res << endl;

    return 0; 
} 
