
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
    
    int n, t;
    cin >> n;

    int arr[3] = {};

    fori(i, n)  {
        cin >> t;
        arr[i%3] += t;
    }

    if(arr[0] > arr[1] && arr[0] > arr[2]) cout << "chest" << endl;
    else if(arr[1] > arr[0] && arr[1] > arr[2]) cout << "biceps" << endl;
    else cout << "back" << endl;

    return 0;
}
