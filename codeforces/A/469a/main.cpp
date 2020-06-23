
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int n, p, q, temp;

    scanf("%d", &n);

    int arr[n+1] = {};

    scanf("%d", &p);

    for(int i = 0; i < p; ++i){
        scanf("%d", &temp);
        ++arr[temp];
    }

    scanf("%d", &q);

    for(int i = 0; i < q; ++i){
        scanf("%d", &temp);
        ++arr[temp];
    }

    bool b = true;

    for(int i = 1; i <= n && b; ++i){
        if(arr[i] == 0) b = false;
    }

    if(b){
        cout << "I become the guy.\n";   
    } else {
        cout << "Oh, my keyboard!\n";
    }

    return 0;
}
