
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    string s = to_string(n);

    bool lucky = true;
    
    int l = s.length();

    string temp;

    for(int i = 0; i < l && lucky; ++i){
        if(s[i] != '4' && s[i] != '7') lucky = false;
    }

    string res;

    if(lucky){
        res = "YES";
    } else {
        res = "NO";
        int j, t;
        for(j = 4; j <= 1000; ++j){
            if(n % j == 0){
                temp = to_string(j);
                lucky = true;
                t = temp.length();
                for(int i = 0; i < t && lucky; ++i){
                    if(temp[i] != '4' && temp[i] != '7') lucky = false;
                }
                if(lucky) {
                    res = "YES";
                    break;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
