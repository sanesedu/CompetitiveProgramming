
#include <iostream>
#include <cmath>

using namespace std;

bool isprime(long long p){

    if(p == 1){
        return false;
    } else if(p == 2){
        return true;
    } else if(p % 2 == 0){
        return false;
    }else {
        
        for(long long i = 3; i * i <= p; i += 2){
            if(p % i == 0) return false;
        }

        return true;
    }

}

bool is_tprime(long long x){

    long long p = sqrt(x);

    if(p * p != x){
        return false;
    } else {
        return isprime(p);
    }
}

int main() {

    int n;

    cin >> n;

    long long curr;

    for(int i = 0; i < n; ++i){
        cin >> curr;

        if(is_tprime(curr)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
