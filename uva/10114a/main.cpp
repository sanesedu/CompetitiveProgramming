
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    
    int months, deps;
    float down, owed, car;    
    
    bool b = true;

    while(b){
        scanf("%d %f %f %d", &months, &down, &owed, &deps);
        
        if(months < 0){
           b = false;
           break;
        }

        car = down + owed;
        
        int m, mtemp;
        float d;

        vector<float> v;
        int ind = 0;

        scanf("%d %f", &m, &d);
        
        for(int i = 1; i < deps; i++){
            scanf("%d", &mtemp);
           
            for(int j = 0; j < (mtemp - m); j++){
                v.push_back(d);
            }
            
            m = mtemp;
            scanf("%f", &d);
        }
        
        for(int j = 0; j < (months - m); j++){
            v.push_back(d);
        }

//        cout << "Vector: " << endl;

  //      for(vector<float>::iterator it = v.begin(); it != v.end(); it++){
    //        cout << *it << endl;
      // }

        vector<float>::iterator it = v.begin();

//        cout << "Car0 : " << car << endl;
        car *= (1 - *it);

       // cout << "v: " << *it << endl;
        //cout << "Car1: " << car << endl;

        float rate = owed / months;
        
        //cout << "Rate: " << rate << endl;        

        int k;

        //printf("%f %f\n", owed, car);

        int length = v.end() - v.begin();

        //for(k = 1; k < length && owed >= car; k++){
          //  owed -= rate;
            //car *= (1 - v[k]);
            //printf("%f %f\n", owed, car);
        //}
        
        for(it = v.begin() + 1; it != v.end() && owed >= car; it++){
            owed -= rate;
            car *= (1 - *it);
//            printf("%d. %f %f\n", it - v.begin(), owed, car);
        }

        if(it == v.end() && owed >= car){
            if(months == 1){
                cout << "1 month" << endl;
            } else {
                printf("%d months\n", months);
            }
        } else {

            int res = it - v.begin() - 1;
            if(res == 1){
                cout << "1 month" << endl;
            } else {
                printf("%d months\n", res);
            }
        }

        v.clear();
    }

    return 0;
}
