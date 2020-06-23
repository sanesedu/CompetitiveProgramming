
#include <iostream>

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
        
    int left = 0;
    int right = 9;

    int nleft = -1;
    int nright = -1;

    for(char c: s) {
        if(c == 'L') {
            arr[left] = 1;
            if(nleft == -1) ++left;
            else {
                left = nleft;
                nleft = -1;   
            }
        } else if(c == 'R') {
            arr[right] = 1;
            if(nright == -1) ++right;
            else {
                right = nright
            }
        } else {
            int p = c - '0';
            if(p < left) {
                left = p;
            } else {
                right = p;
            }
        }
    }

    return 0;
}
