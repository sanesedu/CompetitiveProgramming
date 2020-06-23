
#include <iostream> 

using namespace std;

int main(){
    int n;

    cin >> n;

    string a = "aeiou";

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        bool res[5];

        for(int j = 0; j < s.length(); j++){
            for(int k = 0; k < a.length(); k++){
                if(s[j] == a[k]){
                    res[k] = true;
                }
            } 
        }

        if(res[0] && res[1] && res[2] && res[3] && res[4]){
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
