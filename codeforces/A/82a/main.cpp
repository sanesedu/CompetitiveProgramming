
#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> names = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    long long n;
    cin >> n;
    
    --n;

    long long people = 5;

    while(n >= people) {
        n -= people;
        people *= 2;
    }

    cout << names[(5*n)/people] << endl;

    return 0;
}
