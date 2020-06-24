
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int binSearch(vector<int> arr, int t[], int len, int val) { //returns pos in t[] to replace with val
    //remember: t[] always remains sorted 
    
    int start = 0;
    int middle;
    int end = len;

    while(start <= end) {
        middle = (start + end) / 2;

        if(middle < len && arr[t[middle]] < val && val <= arr[t[middle+1]]) {
            //middle < val < middle + 1 -> substitutes middle + 1
            return middle + 1;
        } else if(arr[t[middle]] < val) {
            //val is still > than middle + 1 -> keep looking higher in array
            start = middle + 1;
        } else {
            //look lower in the array
            end = middle - 1;
        }
    }
    return -1;
}

void lis(vector<int> arr) {

    int n = arr.size();

    int t[n];
    int r[n];
    
    memset(r, -1, sizeof(r));
    
    t[0] = 0;

    int len = 0;

    for(int i = 1; i < n; ++i) {
        
        if(arr[t[0]] > arr[i]) { //if arr[i] < min value, replace it
            t[0] = i;
        } else if(arr[t[len]] < arr[i]) { //if arr[i] > greater value, append it
            ++len;
            t[len] = i;
            r[t[len]] = t[len-1]; //store predecessor
        } else {
            int index = binSearch(arr, t, len, arr[i]);
            t[index] = i;
            r[t[index]] = t[index-1]; 
        }
    }

    cout << len+1 << "\n-\n";

    int index = t[len];

    int res[len+1];

    int pos = len;

    while(index != -1) {
        res[pos] = arr[index];
        index = r[index];
        pos--;
    }

    fori(i, len+1) {
        cout << res[i] << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    vector<int> arr;

    int p;

    while(cin >> p) arr.pb(p);

    lis(arr);

    return 0;
}
