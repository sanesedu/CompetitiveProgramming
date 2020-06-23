
#include <iostream>

using namespace std;

int main(){
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        int res = (a+1)*b + (b+1)*a;

        cout << res << endl;
    }
}
