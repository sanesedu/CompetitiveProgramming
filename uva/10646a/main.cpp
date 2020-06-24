
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int get_value(string s) {
    if(isdigit(s[0])) return (s[0] - '0');
    else return 10;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    stack<string> pile, hand, fin;

    string s;

    int q;
    cin >> q;

    fori(j, q) {
        
        fori(i, 52) {
            cin >> s;
            
            if(i < 27) pile.push(s);
            else hand.push(s);
        }
        
        int y = 0;
        int x;

        fori(i, 3) {
            x = get_value(pile.top());
            y += x;
            pile.pop();
            fori(i, 10 - x) pile.pop();
        }

        while(!hand.empty()) {
            fin.push(hand.top());
            hand.pop();
        }

        while(!pile.empty()) {
            fin.push(pile.top());
            pile.pop();
        }

        fori(i, y-1) fin.pop();

        cout << "Case " << j+1 << ": " << fin.top() << endl;

        while(!fin.empty()) fin.pop();
    }

    return 0;
}
