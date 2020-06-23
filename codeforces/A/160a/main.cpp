
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, temp, total;

    total = 0;

    scanf("%d", &n);

    int coins[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &temp);
        total += temp;
        coins[i] = temp;
    }

    int size = sizeof(coins)/sizeof(coins[0]);

    sort(coins, coins + size, greater<int>());

    int sum = 0;

    int j;

    total /= 2;

    for(j = 0; j < n && sum <= total; ++j){
        sum += coins[j];
    }

    printf("%d\n", j);

    return 0;
}
