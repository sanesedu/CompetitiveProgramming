
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    
    int n, m, temp;

    scanf("%d %d", &n, &m);

    int arr[m] = {0};

    for(int i = 0; i < m; ++i){
        scanf("%d", &temp);
        arr[i] = temp;
    }

    int size = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + size, greater<int>());

    int min, curr;

    min = curr = 1000;

    for(int j = 0; j <= m - n; ++j){
        curr = arr[j] - arr[j+n-1];

        if(curr < min) min = curr;
    }

    printf("%d\n", min);

    return 0;
}
