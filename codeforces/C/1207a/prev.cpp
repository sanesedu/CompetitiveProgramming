
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void print(long long n, long long arr[]) {
     fori(i, n) {
        cout << arr[i] << " ";
     }
     cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;

    long long n;

    long long a, b;
    string s;

    fori(i, t) {
        cin >> n >> a >> b >> s;
        
        if(n == 2) {
            cout << 3*b + 2*a << endl;
            continue;
        }

        long long nz[n] = {};
        long long no[n] = {};

        long long z = 0;
        long long o = 0;

        for(int i = n-2; i >= 0; --i) {
            
            if(s[i] == '0') {
                ++z;
                no[i] = o;
//                o = 0;
            } else {
                ++o;
                nz[i] = z;
                z = 0;
            }

        }

        long double acost = 0; //pipe
        long double bcost = 0; //pillar

        bool up = false;
        bool down = false;

        for(int i = 0; i < n-1; ++i) {
//            cout << acost << " " << bcost << endl; 
            if(i == 0) {
                bcost += b;
            } else if(i == n-2) {
                if(s[i] == '1') {
                    if(up) {
                        acost += 4*a;
                    } else {
                        acost += 5*a;
                    }
                    bcost += 5*b;
                } else {
                    if(up) {
                        acost += 4*a;
                    } else {
                        acost += 3*a;
                    }
                    bcost += 3*b;
                }
            } else {
                if(s[i] == '1') {
                    if(up) {
                        acost += a;
                        bcost += 2*b;
                    } else {
                        acost += 2*a;
                        bcost += 2*b;
                        up = true;
                    }
                } else {
                    if(up) {
                        if(no[i] > 0) { //have to go up again
                            if(nz[i-1] > 1) { //possible to go down
                                
                                long long td = 4*a + (nz[i-1] - 2) * a + (nz[i-1]-1) * b; //cost going down
                                long long tu = nz[i-1] * a + (nz[i-1]-1)*2*b; //cost staying up
                                
//                                cout << "td " << td << " tu " << tu << endl;

                                if(td < tu) { //go down
                                    up = false;
                                    down = true;
                                } 
                                acost += a;
                                bcost += 2*b;

                            } else {
                                acost += a;
                                bcost += 2*b;
                            }

                        } else {
                            acost += 2*a;
                            bcost += b;
                            up = false;
                        }
                    } else {
                        if(down) {
                            acost += 2*a;
                            down = false;
                        } else {
                            acost += a;
                        }
                        bcost += b;
                    }
                }
            }
        }
        
  //      cout << acost << " " << bcost << endl;

        cout << acost + bcost << endl;

    }

    return 0;
}
