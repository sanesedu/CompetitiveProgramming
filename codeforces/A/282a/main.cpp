
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    
    int n, res;
    string s;

    scanf("%d", &n);

    res = 0;

    for(int i = 0; i < n; ++i){
        
        cin >> s; 

        for(int j = 0; j < 3; ++j){
            if(s.at(j) == '+'){
                ++res;
                break;
            } else if(s.at(j) == '-'){
                --res;
                break;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
