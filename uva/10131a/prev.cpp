
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<pair<int, int>> arr;
map<int, int> m;

int binSearch(int t[], int len, int val) {
    
    int start = 0;
    int end = len;
    int middle;

    while(start <= end) {
        middle = (start + end) / 2;

        if(middle < len && arr[t[middle]].second < val && val <= arr[t[middle+1]].second) {
            return middle+1;
        } else if(arr[t[middle]].second) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

void lis() {
  
    int n = arr.size();

    int t[n];
    int r[n];
    
    memset(r, -1, sizeof(r));

    t[0] = 0;

    int len = 0;

    for(int i = 1; i < n; ++i) {
        
        if(arr[t[0]].second > arr[i].second) {
            t[0] = i;            
        } else if(arr[t[len]].second < arr[i].second) {
            ++len;
            t[len] = i;
            r[t[len]] = t[len-1];
        } else {
            int index = binSearch(t, len, arr[i].second);
            t[index] = i;
            r[t[index]] = t[index-1];
        }
    }
    
    cout << len + 1 << endl;
    
    int sol[len+1];

    int index = t[len]; 

    int pos = len;

    while(index != -1) {
        sol[pos] = m[arr[index].second];
        index = r[index]; 
        --pos;
    }

    fori(i, len+1) {
        cout << sol[i] << endl;
    }

}

bool my_comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

void print() {
    vector<pair<int, int>>::iterator it;

    for(it = arr.begin(); it != arr.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int w, i;

    int index = 1;

    while(cin >> w >> i) {
        arr.pb(make_pair(i, w));
        m[w] = index;
        ++index;
    }
    
    sort(all(arr), my_comp);

    lis();

    return 0;
}
