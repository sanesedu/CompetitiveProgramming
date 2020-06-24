
#include <iostream>

using namespace std;

int main(){
    
    string s;

    string r1 = "`1234567890-=";
    string r2 = "QWERTYUIOP[]\\\\";
    string r3 = "ASDFGHJKL;'";
    string r4 = "ZXCVBNM,./";

    while(getline(cin, s)){

        for(int i = 0; i < (int) s.length(); i++){
            
            if(r1.find(s[i]) != string::npos){
                cout << r1[(r1.find(s[i])-1 + r1.length()) % r1.length()];
            } else if(r2.find(s[i]) != string::npos){
                cout << r2[(r2.find(s[i])-1 + r2.length()) % r2.length()];
            } else if(r3.find(s[i]) != string::npos){
                cout << r3[(r3.find(s[i])-1 + r3.length()) % r3.length()];
            } else if(r4.find(s[i]) != string::npos){
                cout << r4[(r4.find(s[i])-1 + r4.length()) % r4.length()];
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}
