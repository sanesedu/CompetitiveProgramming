
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

/* int div2(string s, int n) {
  
    cout << s << " " << n << endl;

    int t = stoi(s);

    if(t % 8 == 0) return t;
    
    if(n <= 0) return -1;

    string c = s.substr(n, n);

    s.erase(n);
    
    cout << "bef " << s << " " << n << endl; 

    int a = div(s, n-1); 
    
    cout << "aft " << s << " " << n << endl; 

    if(a != -1) return a;

    s.insert(n, c);

    return div(s, n-1);

} */

int div(string s, int n) {
    
    int m = (1 << n)  - 1;

    cout << m << endl;

    int t = 0;

    while(m > 0) {
        
        t = 0;    
        int mult = 1;

        for(int i = s.length()-1; i>= 0; --i) {
            bitset<8> b1(m);
            bitset<8> b2(1 << i);
            cout << b1 << " " << b2 << endl;
            if(m & (1 << i)) {
                t += (s[i] - '0') * mult;
                mult *= 10;
                cout << "here " << t << endl;
            }
        }    
        
        if(t % 8 == 0) return t;

        cout << t << endl;
        
        --m;
    }

    if(t % 8 == 0) return t;

    return -1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    string s;
    cin >> s;

    int res = div(s, s.length());

    if(res != -1) cout << "YES\n" << res << endl;
    else cout << "NO\n";

    return 0;
}
