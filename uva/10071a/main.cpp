
#include <iostream>

using namespace std;

int main() {

    string s;
    int v, t, res;

    double a;

    while(getline(cin, s)){
        
        v = stoi(s.substr(0, s.find(" ")));
        t = stoi(s.substr(s.find(" ")+1, s.length()));

        a = (double)v/t;

        res = (int)((1./2)*a*(2*t)*(2*t) + 0.5 - (res<0));

        cout << res << endl;

    }
   
   return 0; 

}
