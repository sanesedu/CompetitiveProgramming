
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    
    int w = 0;

    scanf("%d", &w);

    cout << ((w%2 == 0 && w > 2) ? "YES":"NO") << endl;

    return 0;
}
