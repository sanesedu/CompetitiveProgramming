
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

void lis() {
  
    int temp[arr.size()];
   
    int sol[arr.size()];

    fori(i, arr.size()) {
        temp[i] = 1;
        sol[i] = i;
    }  

    for(int i = 1; i < (int) arr.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(arr[i].second > arr[j].second) {
                if(temp[j] + 1 > temp[i]) {
                    temp[i] = temp[j] + 1;
                    sol[i] = j;
                }
            }
        }
    }

    int maxindex = 0;

    for(int i = 0; i < (int) arr.size(); ++i) {
        if(temp[i] > temp[maxindex]) {
            maxindex = i;
        }
    }

    int t = maxindex;
    int newt = maxindex;

    cout << temp[t] << endl;

    do {
        t = newt;
        cout << m[arr[t].second] << endl;
        newt = sol[t];
    } while(t != newt); 
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
