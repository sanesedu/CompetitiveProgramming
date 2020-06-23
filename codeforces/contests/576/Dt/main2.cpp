
#include <stdio.h>
#include <string>

using namespace std;

int main() {

    int n, q, a;

    scanf("%d", &n);

    long long arr[n] = {};

    for(int i = 0; i < n; ++i) scanf("%I64d", &arr[i]);

    scanf("%d", &q);

    long long b, c;

    for(int j = 0; j < q; ++j){
        
        scanf("%d", &a);

        if(a == 1){
            scanf("%I64d %I64d", &b, &c);
            
            arr[b-1] = c;

        } else {
            
            scanf("%lld", &b);

            for(int k = 0; k < n; ++k){
                if(arr[k] < b) arr[k] = b;
            }
        }
    }

    string res = "";

    for(int h = 0; h < n; ++h){
        res += to_string(arr[h]) + " ";
    }

    printf("%s\n", res.c_str());

    return 0;
}
