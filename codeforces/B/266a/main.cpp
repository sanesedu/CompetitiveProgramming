
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int n, t;

    scanf("%d %d", &n, &t);

    string s;

    cin >> s;

    for(int i = 0; i < t; ++i){
        for(int j = 1; j < n; ++j){
            if(s[j] == 'G' && s[j-1] == 'B'){
                s[j-1] = 'G';
                s[j] = 'B';
                ++j;
            }
        }
    }
    
    cout << s << endl;

    return 0;
}
