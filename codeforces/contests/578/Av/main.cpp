
#include <iostream>
#include <set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n; 
    cin >> n;

    string s;
    cin >> s;

    int arr[10] = {};
        
    set<int> empty;
    set<int> full;

    for(int i = 0; i <= 9; ++i) empty.insert(i);

    set<int>::iterator pos;

    int los;

    for(char c: s) {
        if(c == 'R') {
            pos = empty.end();
            --pos;
            arr[*(pos)] = 1;
            full.insert(*pos);
            empty.erase(pos);
        } else if(c == 'L') {
            pos = empty.begin();
            arr[*pos] = 1;
            full.insert(*pos);
            empty.erase(pos);
        } else {
            los = c - '0';
            empty.insert(los);
            full.erase(los);
            arr[los] = 0;
        }
    }

    for(int i = 0; i <= 9; ++i) cout << arr[i];

    cout << "\n";

    return 0;
}
