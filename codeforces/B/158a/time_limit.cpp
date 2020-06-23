
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printv(vector<int> v){
    
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); ++it){
        printf("%d, ", *it);
    }
    
    printf("\n");
}

int main() {
    
    int n, t;

    scanf("%d", &n);

    int res = 0;

    vector<int> v;
    
    vector<int>::iterator temp;

    for(int i = 0; i < n; ++i){
        scanf("%d", &t);
        v.push_back(t);
    }

    for(temp = v.begin(); temp != v.end(); ++temp){
        sort(v.begin(), v.end(), greater<int>());
//        printv(v);
        if(*temp == 4) {
            res++;
  //          cout << "temp = 4" << endl;
            v.erase(temp);
            if(v.end() - v.begin() + 2 >= 0) temp = v.begin() - 1;
        } else {
            bool f = false;
            vector<int>::iterator it;
            for(it = temp + 1; it != v.end() && !f; ++it){
                if(*it == 4){
                    v.erase(it);
                }
                int sum = *it + *temp;
                int cp = *it;
                int cp2 = *temp;
                if(sum <= 4){
                    v.erase(it);
                    v.erase(temp);
    //                cout << "size " << v.end() - v.begin() + 2 << endl;
                    if(v.end() - v.begin() + 2 >= 0) temp = v.begin() - 1;
                    if(sum < 4){
      //                  cout << "adding " << sum << endl;
                        v.push_back(sum);
                    } else {
                        res++;
                    }
                    f = true;
        //            cout << cp2 << " + " << cp << " replaced by " << sum << endl;
                }
            }

            if(it == v.end() && !f){
          //      cout << "not found" << endl;
            }
        
        }
    }
    
  //  printf("%d\n", res);

    res += v.size();

    printf("%d\n", res);

    return 0;
}
