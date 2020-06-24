
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;
    cin.ignore();
    
    string line;
    getline(cin, line);

    while(t--) {
        int reg[100] = {};
        int mem[1000] = {};

        int pc = 0, res = 0; 

        while(getline(cin, line)) {
            if(line.empty()) break;
            stringstream ss(line);
            ss >> mem[pc++]; 
        }

        pc = 0;

        while(true) {
            int a = mem[pc]/100;
            int b = (mem[pc]%100)/10;
            int c = mem[pc]%10;
            
            ++pc;
            ++res;
        
            if(a == 1) break;

            if(a == 0) {
                if(reg[c] != 0) {
                    pc = reg[b];
                }
            } else if(a == 2) {
                reg[b] = c;
            } else if(a == 3) {
                reg[b] += c;
                reg[b] %= 1000;
            } else if(a == 4) {
                reg[b] *= c;
                reg[b] %= 1000;
            } else if(a == 5) {
                reg[b] = reg[c];
            } else if(a == 6) {
                reg[b] += reg[c];
                reg[b] %= 1000;
            } else if(a == 7) {
                reg[b] *= reg[c];
                reg[b] %= 1000;
            } else if(a == 8) {
                reg[b] = mem[reg[c]];
            } else if(a == 9) {
                mem[reg[c]] = reg[b];
            }
        }

        cout << res << endl;
        
        if(t) cout << endl;
    }

    return 0;
}
