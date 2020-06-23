
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int diff;

int sum(char a) {
    if((a + diff) > 90) return (a + diff - 90 + 64);
    else if((a + diff) < 65) return (a + diff - 65 + 91);
    return a + diff;
}

int main() {

    string line;

    while(getline(cin,line)) {
        char aux = toupper(line[0]);
        diff = 'P'- aux;
        
        int vowels = 0;
        
        if(line.length() == 4 && sum(line[1]) == 'F' && sum(line[2]) == 'I' && sum(line[3]) == 'N') break;

        for(auto &c : line) c = toupper(c);
        
        for(unsigned int i = 1; i < line.length(); ++i) {
            if(!(line[i] >= 'A' && line[i] <= 'Z')) continue;
            else if(sum(line[i]) == 'I' || sum(line[i]) == 'A' || sum(line[i]) == 'E' ||sum(line[i]) == 'O' ||sum(line[i]) == 'U') ++vowels;
        }
        
        cout << vowels << endl;
    }
    
    return 0;
}
