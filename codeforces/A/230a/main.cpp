
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main() {

    int s, n, x, y;

    scanf("%d %d", &s, &n);

    map<int, int> m;

    for(int i = 0; i < n; ++i){

        scanf("%d %d", &x, &y);
        
        if(m.find(x) != m.end()){
            y += m.at(x);
        } 

        m[x] = y;
    }

    map<int, int>::iterator it;

    bool dead = false;

    for(it = m.begin(); it != m.end() && !dead; ++it){
        if(s > it->first) s += it->second;
        else dead = true;
    }

    if(dead) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
