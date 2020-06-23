
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

    int n, tmp, inter;

    bool flag = false;

    while(cin >> n) {
        
        int arr[n];

        flag = false;
        
        inter = 1;
       
        cin >> tmp; 
        
        arr[0] = arr[1] = tmp;
        
        n--;
        
        while(n != 0) {
            
            n--;
           
            cin >> tmp; 
           
            //we check if we have a combination that makes us not give the prize 
            for (int i = inter; i > 0 && arr[i - 1] < tmp && flag==0; i -= 2) {
                if(arr[i - 1] < tmp && arr[i] > tmp) flag = true;
            }

            if(flag) break;

            if(arr[inter - 1] < tmp) {
                arr[inter] = tmp;
            } else if(arr[inter - 1] == arr[inter]) {
                arr[inter - 1] = arr[inter] = tmp;
            } else {
                inter += 2;
                arr[inter - 1] = arr[inter] = tmp;
            }
        }

        while(n != 0) {
            n--; 
            cin >> tmp;
        }
        
        if(flag) cout << "ELEGIR OTRA\n";
        else cout << "SIEMPRE PREMIO\n";
    }

    return 0;
}
