
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long reverseNumber(long long input) {

    long long reversed = 0;

    while(input) {
        reversed = reversed * 10 + (input % 10);
        input /= 10;
    }

    return reversed;

}



static char resultString[16];

bool isPalindrome(long long sum) {

    int  i = 0;

    while(sum) {
        resultString[i++] = sum % 10;
        sum /= 10;
    }

    for(int j = 0, k = i - 1; j < k; ++j, --k) {
        if(resultString[j] != resultString[k])
            return false;
    }

    return true;
}


int main() {

    long long input;
    int times, iters;

    scanf("%d", &times);

    while( times-- ) {

        scanf("%lld", &input);

        iters = 0;

        while(true) {
            input += reverseNumber(input);
            ++iters;

            if( isPalindrome(input) ){
                printf("%d %lld\n", iters, input);
                break;
            }

        }

    }

    return 0;
}
