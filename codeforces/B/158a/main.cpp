
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {

    int n, temp;
    
    int arr[5] = {0};

    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &temp);
        arr[temp]++;
    }
    
    int res = arr[4] + arr[3];

    arr[1] -= arr[3];

    if(arr[1] < 0) arr[1] = 0;

    res += arr[2] / 2;

    arr[2] = (arr[2] % 2);

    if(arr[2] != 0){
        res++;
        if(arr[1] >= 2) arr[1] -= 2;
        else if(arr[1] == 1) arr[1]--;
    }

    if(arr[1] <= 0){
        arr[1] = 0;
    } else {
        
        int d = 4;

        while(arr[1] > 0){
            
            res += arr[1] / d;
            arr[1] = arr[1] % d;

            d--;

        }
    }

    printf("%d\n", res);

    return 0;
}
