
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
    
    int n;
    
    long long a[505][505];

    while(cin>>n) {
        
        int x,y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
                if(a[i][j] == 0) { //pos of empty cell
                    x = i; 
                    y = j;
                }
            }
        }

        if(n == 1) { //only the empty cell
            cout << "1" << endl;
            continue;
        }

        long long sum2 = 0;
        long long sum1 = 0;
        
        for(int i = 0; i < n; i++) {
            sum1 += a[x][i]; //sum of row with empty cell
            sum2 += a[(x+1)%n][i]; //sum of regular row
        }

        a[x][y] = sum2-sum1; //temporarily assume that is the value

        bool flag = true;
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum = 0;
            
            for(int j = 0; j < n; j++)
                sum += a[i][j];

            if(sum != sum2) { //if sum of row differs from others
                cout << "-1" << endl; //not magic square regardless
                flag = false;
                break;
            }
        }
        
        if(!flag) continue;
 
        for(int i = 0; i < n; i++) {
            sum = 0; 
            
            for(int j = 0; j < n; j++) {
                sum += a[j][i];
            }

            if(sum != sum2) { //sum of column differs from sum of row
                cout << "-1" << endl;
                flag = false;
                break;
            }
        }

        if(!flag) continue;

        sum = 0;

        for(int i = 0; i < n; i++)
            sum += a[i][i]; //sum of main diagonal
        
        if(sum2 != sum) { //sum of main diagonal differs from sum of row
            cout << "-1" << endl;
            continue;
        }

        sum = 0;
        for(int i = n-1; i >= 0; i--)
            sum += a[i][n-i-1]; //sum of other diagonal

        if(sum2 != sum) { //sum of other diagonal differs from sum of row
            cout << "-1" << endl;
            continue;
        }
        
        if(a[x][y] > 0) //value must be positive, else not magic square
            cout << a[x][y] << endl;
        else
            cout << "-1" << endl;
    }
    
    return 0;
}
