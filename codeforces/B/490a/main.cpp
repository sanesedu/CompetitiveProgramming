
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

#define N 2000000+17
 
int nxt[N],a[N],b[N],q[N];
bool check[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
   
    int n;
    cin>>n;
    
    fori(i, n) {
        cin >> a[i] >> b[i];
        nxt[a[i]] = b[i];
        check[b[i]] = 1;
    }
    
    for(int i = 0, j = 1; j <= n; i = nxt[i]) { //we insert next elements into q alternatively
        q[j] = nxt[i];
        j += 2;
    }
    
    int t = a[0];

    fori(i, n)  {
        if(check[a[i]] == 0) t = a[i]; //we get the element that does not appear in second column == first in q
    }
    
    for(int i = t, j = 0; j<=n ; i = nxt[i]) { //we fill the other half
        q[j] = i;
        j += 2;
    }

    cout << q[0];

    for(int i = 1; i < n; ++i) {
        cout << ' ' << q[i];
    }

    cout<<endl;

    return 0; 

}
