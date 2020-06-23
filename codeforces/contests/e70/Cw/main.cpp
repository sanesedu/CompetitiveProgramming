
#include <iostream>

using namespace std;

long long red(long long i, long long j) {
    long long val1 = (i-1) * j;
    long long val2 = (j-1) * i;

    if(val1 == 0) return val2;
    else if (val2 == 0) return val1;
    else return min((i-1) *j, (j-1) * i);
}

long long compmin(string s) {

    long long up = -1;
    long long down = -1;
    long long left = -1;
    long long right = -1;

    long long i = 1; //vertical
    long long j = 1; //horizontal

    for(long long h = 0; h < s.length(); ++h) {
        switch(s[h]) {
            case 'W':
                if(up >= down) ++i;
                ++up;
                break;
            case 'S':
                if(down >= up) ++i;
                ++down;
                break;
            case 'A':
                if(left >= right) ++j;
                ++left;
                break;
            case 'D':
                if(right >= left) ++j;
                ++right;
                break;
        }
    }
    
    if((i == 1 && j == 2) || (j == 1 && i == 2)) {
        return i * j;
    } else if(i == 2 && j == 2) {
        return i * j;
    } else if(up != down || left != right) {
        return red(i, j);
    } else {
        return i * j;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;

    cin >> t;

    string s;

    for(long long i = 0; i < t; ++i) {
        cin >> s;
        cout << compmin(s) << endl;
    }

    return 0;
}
