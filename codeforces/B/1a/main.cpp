
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void change(int x) {
    if(x) {
        change((x - 1) / 26);
        putchar('A' + (x - 1) % 26);
    }
}
 
int main() {
    
    int n;
    char s[105];

    for(scanf("%d", &n); n; --n) {
        int row, col;

        scanf("%s", s);

        if(sscanf(s, "%*[A-Z]%d%*[A-Z]%d", &row, &col) == 2) { //2 fields converted successfully, i.e. 2 set of numbers separated, RxCy
            change(col); //change col to letter representation
            printf("%d\n", row);
        } else {
            col = 0;
            for(int i = 0; isupper(s[i]); ++i) { //change all letters to number representation
                col = col * 26 + s[i] - 'A' + 1;
            }
            printf("R%dC%d\n", row, col); 
        }
 
    }
    return 0;
}
