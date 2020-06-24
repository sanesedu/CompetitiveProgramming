
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

    double n;
   
    // max heap to store the smaller half elements  
    priority_queue<double> s; 
    // min heap to store the greater half elements
    priority_queue<double, vector<double>, greater<double>> g;

    cin >> n;

    cout << n << endl;

    s.push(n);

    double med = n;

    while(cin >> n) {
        // case1(left side heap has more elements)
        if(s.size() > g.size()) {
            if(n < med) {
                g.push(s.top());
                s.pop();
                s.push(n);
            } else {
                g.push(n);
            }
            med = (s.top() + g.top()) / 2.0; 
        } else if(s.size() == g.size()) {
            // case2(both heaps are balanced)
            if(n < med) {
                s.push(n);
                med = s.top();
            } else {
                g.push(n);
                med = g.top();
            }
        } else {
            // case3(right side heap has more elements) 
            if(n > med) {
                s.push(g.top());
                g.pop();
                g.push(n);
            } else {
                s.push(n);
            }
            med = (s.top() + g.top()) / 2.0;
        }
        cout << (int) med << endl; 
    }

    return 0;
}
