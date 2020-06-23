
#include <iostream> 
#include <cmath>

using namespace std;

void kmp_array(string pat, int M, int* lps); 
  
int kmp_search(string pat, string txt) { 

    int M = pat.length(); 
    int N = txt.length(); 
  
    int lps[M]; 
  
    kmp_array(pat, M, lps); 
  
    int i = 0;
    int j = 0; 
    
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            ++j; 
            ++i; 
        } 
  
        if (j == M) { 
            return i - j;
        } else if (i < N && pat[j] != txt[i]) { 
            if (j != 0)  j = lps[j - 1]; 
            else i = i + 1; 
        } 
    } 

    return -1;
} 
  
void kmp_array(string pat, int M, int* lps) { 
    
    int len = 0; 
  
    lps[0] = 0; 
  
    int i = 1; 
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

    int i = kmp_search(pat, txt); 
    int j = txt.length() - (i + pat.length());

    int res = max(i, j);

    cout << res << endl;

    return 0; 
} 
