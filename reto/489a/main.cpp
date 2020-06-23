
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

    int n, m, t;

    while(cin >> n >> m) {

        priority_queue<int> students;
        priority_queue<int> classes;
        
        fori(i, n) {
            cin >> t;
            students.push(t);
        }

        fori(i, m) {
            cin >> t;
            classes.push(t);
        }

        if(students.size() > classes.size()) {
            cout << "NO\n";
            continue;        
        }

        bool res = true;

        int a, b;

        while(!students.empty() && res) {
            
            a = students.top();
            b = classes.top();

            students.pop();
            classes.pop();

            if(a > b) res = false;

        }

        if(res) cout << "SI\n";
        else cout << "NO\n";

    }

    return 0;
}
