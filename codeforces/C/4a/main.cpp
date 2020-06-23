
#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    string temp;

    map<string, int> m;

    for(int i = 0; i < n; ++i){
        cin >> temp;
        
        bool b = true;
        for(int i = temp.length()-1; i >= 0 && b; --i){
            if(isdigit(temp[i])) temp.erase(i, 1);
            else b = false;
        }

        if(m.find(temp) == m.end()){
            cout << "OK\n";
            m[temp] = 0;
        } else {
            temp += to_string(++m[temp]);
            cout << temp << "\n";
        }
    }

    return 0;
}
