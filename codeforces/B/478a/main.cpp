
#include <iostream>
#include <cmath>

using namespace std;

long long pairs(long long p) {

    return (p*(p-1)) / 2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long m, n;

    cin >> n >> m;

    long long max, min;

    if(n % m == 0) {
        
        long long perteam = n / m;

        min = m * pairs(perteam);

        perteam = n - (m-1);

        max = pairs(perteam);

    } else {

        long double k = m;

        long long nteam = n / m;
        long long pteam = n % m;

        min = (pteam) * pairs(nteam + 1) + (m - pteam) * pairs(nteam);

        nteam = n - (m-1);

        max = pairs(nteam);

    }

    cout << min << " " << max << "\n";    

    return 0;
}
