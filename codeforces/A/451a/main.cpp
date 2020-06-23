
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int count = 0;

    while(n != 1 && m != 1){
        --n;
        --m;
        ++count;
    }

    string res = "";

    if(count % 2 == 0) res = "Akshat";
    else res = "Malvika";

    cout << res << "\n";
        
    return 0;
}
