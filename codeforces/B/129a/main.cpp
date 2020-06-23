
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

    int n, m, a, b;
    cin >> n >> m;
   
    bool graph[n+1][n+1] = {}; 
    int count[n+1] = {};
    
    memset(count, 0, sizeof(count));
    memset(graph, false, sizeof(graph));

    fori(i, m) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        ++count[a];
        ++count[b];
    }

    int c = 0;
    int res = -1;

    int reps[n] = {}; //to reprimend

    do{
        
        c = 0;

        fori(i, n+1) {
            if(count[i] == 1) {
                --count[i];
                reps[++c] = i;
            }
        }

        fori(i, c+1) {
            fori(j, n+1) {
                if(graph[reps[i]][j]) --count[j];
            }
        }

        ++res;

    } while(c > 0);

    cout << res << endl;

    return 0;
}
