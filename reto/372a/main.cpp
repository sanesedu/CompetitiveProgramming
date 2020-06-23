
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main()
{
    int casos;
    
    cin >> casos;
    
    char palabras[40];

    for(int i = 0; i < casos; ++i)  {
       
       cin >> palabras;
       if(palabras[0] > 64 && palabras[0] < 91) {
           palabras[0] = tolower(palabras[0]);
           palabras[strlen(palabras)-1] = toupper(palabras[strlen(palabras)-1]);
       }
       for (int j = strlen(palabras)-1; j >= 0; --j) {
           cout << palabras[j];
       }
       cout << "\n";
    }
    return 0;
}
