
#include <bits/stdc++.h>

using namespace std;

int main() {

    int b, g, temp;

    scanf("%d", &b);

    vector<int> boys, girls;

    for(int i = 0; i < b; ++i){
        scanf("%d", &temp);
        boys.push_back(temp);
    }

    scanf("%d", &g);

    for(int j = 0; j < g; ++j){
        scanf("%d", &temp);
        girls.push_back(temp);
    }

    sort(boys.begin(), boys.end(), greater<int>());
    sort(girls.begin(), girls.end(), greater<int>());

    vector<int>::iterator bit, git;

    int res = 0;

    for(bit = boys.begin(); bit != boys.end(); ++bit){
        for(git = girls.begin(); git != girls.end(); ++git){
            if(abs(*bit - *git) <= 1){
                girls.erase(git);
                ++res;
                break;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
