
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

    stack<int> s;
    queue<int> aux;

    bool b = true;

    while(b) {

        int t, n;
        
        while(b) {
            cin >> t;
            if(t == -1) break;
            s.push(t);
        }

        if(s.empty()) {
            b = false;
            break;
        }

        cin >> n;

        fori(i, n) {
            cin >> t;
            
            fori(i, t) {
                aux.push(s.top());
                s.pop();
            }

            fori(i, t) {
                s.push(aux.front());
                aux.pop();
            }
        }

        cout << s.top() << endl;

        while(!s.empty()) s.pop(); //clear stack

    }

    return 0;
}
