
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

    int n, temp;

    scanf("%d", &n);

    vector<int> even;
    vector<int> odd;

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &temp);
        if(temp % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }

    if(even.size() == 1) printf("%d\n", even[0]);
    else printf("%d\n", odd[0]);

    return 0;
}   
