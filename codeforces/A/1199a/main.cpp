
#include <stdio.h>

using namespace std;

int main() {

    int n, x, y;

    scanf("%d %d %d", &n, &x, &y);

    int arr[n] = {};

    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    bool b = true;
    bool t1, t2;

    int j;

    for(j = 0; j < n && b; ++j){
        
        t1 = false;
        for(int h = x; h > 0 && !t1; --h){
            if(j - h >= 0 && arr[j] >= arr[j-h]) t1 = true;
        }

        t2 = false;
        for(int h = 1; h <= y && !t2; ++h){
            if(j + h < n && arr[j] >= arr[j+h]) t2 = true;
        }
        
        b = !(!t1 && !t2);

    }

    printf("%d\n", j);

    return 0;
}
