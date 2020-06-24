
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int arr[101];
int n, k;

void roman() {
    int count, i, next = -1;
    int killed;
    
    for (i = 0; i < n; i++) arr[i] = i + 1;
    
    count = 0;
    i = n;
    
    while (i > 1) {
        count = 0;
        while (count < k) {
            next = (next + 1) % n;
            if (arr[next]) count++;
        }
        killed = next;
        arr[next] = 0;
        count = 0;
        next--;
        while (count < k) {
            next = (next + 1) % n;
            if (arr[next]) count++;
        }
        arr[killed] = arr[next];
        arr[next] = 0;
        next = killed;
        i--;
    }

    for (i = 0; i < n; i++) {
        if (arr[i]) {
            if (arr[i] == 1)
	            printf("1\n");
            else printf("%d\n", n - arr[i] + 2);
        break;
        }
    }
}

int main() {
  while (scanf("%d %d", &n, &k)) {
    if (n == 0 && k == 0) break;
    roman();
  }
  return 0;
}

