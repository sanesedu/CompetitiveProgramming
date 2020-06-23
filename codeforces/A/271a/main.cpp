
#include <stdio.h>
#include <string>

using namespace std;

bool check(int y) {
    string s = to_string(y);

    bool diff = true;

    for(int i = 0; i < 4 && diff; ++i){
        for(int j = i + 1; j < 4 && diff; ++j){
            if(s[i] == s[j]) diff = false;
        }
    }

    return diff;
}

int main() {

    int year, i;

    scanf("%d", &year);

    bool end = false;

    for(i = year + 1; i <= 10000 & !end; ++i){
        end = check(i);
    }

    printf("%d\n", i - 1);

    return 0;
}
