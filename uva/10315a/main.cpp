
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

map<char, int> values = {{'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8},{'9',9}, {'T',10}, {'J',11}, {'Q',12}, {'K',13}, {'A',14}};

void print(vector<pair<char, char>> arr) {
    for(auto it = arr.begin(); it != arr.end(); ++it) {
        cout << it->first << it ->second << " - ";
    }
    cout << endl;
}

bool cmp(pair<char, char> a, pair<char, char> b) {
    if(values[a.first] == values[b.first]) {
        return a.second < b.second;
    } else {
        return values[a.first] > values[b.first];
    }
}

int breaktie(bool b, bool w, vector<pair<char, char>> black, vector<pair<char, char>> white) {
    if(b && w) {
        fori(i, 5) {
            if(values[black[i].first] > values[white[i].first]) return 0;
            else if(values[black[i].first] < values[white[i].first]) return 1;
        } 
        return 2;
    } else if(b) {
        return 0;
    } else if(w) {
        return 1; 
    }
    return -1; 
}

bool straight(vector<pair<char, char>> arr) {
    
    bool b = true;
    for(int i = 0; i < 4 && b; ++i) {     
        b &= (abs(values[arr[i].first] - values[arr[i+1].first]) == 1);
    }
    return b;
}

//black = 0, white = 1, tie = 2
int solve(vector<pair<char, char>> black, vector<pair<char, char>> white) {

    map<int, int> fvb;
    map<char, int> fsb;
    
    map<int, int> fvw;
    map<char, int> fsw;

    for(auto it = black.begin(); it != black.end(); ++it) {
        fvb[values[it->first]]++;
        fsb[it->second]++;
    }
    
    for(auto it = white.begin(); it != white.end(); ++it) {
        fvw[values[it->first]]++;
        fsw[it->second]++;
    }
    
    bool b = false;
    bool w = false;
   
    int res;

    //straight flush

  //  cout << "straight flush" << endl;

    b = (fsb.size() == 1) && straight(black);
    w = (fsw.size() == 1) && straight(white);;
    
    if(b && w) {
        if(values[black[0].first] > values[white[0].first]) return 0;
        else if(values[black[0].first] < values[white[0].first]) return 1;
        else return 2;
    } else if(b) {
        return 0;
    } else if(w) {
        return 1; 
    }
        
    //four of a kind
    
   // cout << "four of a kind" << endl;

    int fourb = -1, fourw = -1;

    for(auto it = fvb.begin(); it != fvb.end(); ++it) {
        if(it->second == 4) fourb = it->first;
    }
    
    for(auto it = fvw.begin(); it != fvw.end(); ++it) {
        if(it->second == 4) fourw = it->first;
    }
    
    if(fourb != -1 && fourw != -1) {
        if(fourb > fourw) return 0;
        else if(fourb < fourw) return 1;
        else return 2;
    } else if(fourb != -1) {
        return 0;
    } else if(fourw != -1) {
        return 1;
    }

    //full house    
    
    //cout << "full house" << endl;
    
    int threew = -1, threeb = -1;
    bool pw = false, pb = false;

    for(auto it = fvb.begin(); it != fvb.end(); ++it) {
        if(it->second == 3) threeb = it->first;
        else if(it->second == 2) pb = true;
    }
    
    for(auto it = fvw.begin(); it != fvw.end(); ++it) {
        if(it->second == 3) threew = it->first;
        else if(it->second == 2) pw = true;
    }
       
    if((threeb != -1 && pb) && (threew != -1 && pw)) {
        if(threeb > threew) return 0;
        else if(threeb < threew) return 1;
        else return 2;
    } else if(threeb != -1 && pb) {
        return 0;
    } else if(threew != -1 && pw) {
        return 1;
    }

    //flush
    
//    cout << "flush" << endl;
    
    b = (fsb.size() == 1);
    w = (fsw.size() == 1);  
    
    res = breaktie(b, w, black, white);

    if(res != -1) return res;

    //straight
    
 //   cout << "straight" << endl;
    
    b = straight(black);
    w = straight(white);;
    
    if(b && w) {
        if(values[black[0].first] > values[white[0].first]) return 0;
        else if(values[black[0].first] < values[white[0].first]) return 1;
        else return 2;
    } else if(b) {
        return 0;
    } else if(w) {
        return 1; 
    }
       
    //three of a kind 
    
    //cout << "three of a kind" << endl;
    
    threew = -1;
    threeb = -1;
    pw = false;
    pb = false;

    for(auto it = fvb.begin(); it != fvb.end(); ++it) {
        if(it->second == 3) threeb = it->first;
    }
    
    for(auto it = fvw.begin(); it != fvw.end(); ++it) {
        if(it->second == 3) threew = it->first;
    }
       
    if((threeb != -1) && (threew != -1)) {
        if(threeb > threew) return 0;
        else if(threeb < threew) return 1;
        else return 2;
    } else if(threeb != -1) {
        return 0;
    } else if(threew != -1) {
        return 1;
    }
    
    //two pairs
    
    //cout << "two pairs" << endl;
    
    int pb1 = -1, pb2 = -1, ob = -1;
    int pw1 = -1, pw2 = -1, ow = -1;
    
    for(auto it = fvb.begin(); it != fvb.end(); ++it) {
        if(it->second == 2) {
            if(pb1 == -1) pb1 = it->first;
            else pb2 = it->first;
        } else {
            ob = it->first;
        }
    }
    
    for(auto it = fvw.begin(); it != fvw.end(); ++it) {
        if(it->second == 2) {
            if(pw1 == -1) pw1 = it->first;
            else pw2 = it->first;
        } else {
            ow = it->first;
        }
    }
    
    if((pb1 != -1 && pb2 != -1) && (pw1 != -1 && pw2 != -1)) {
        if(pb1 == pw1) {
            if(pb2 > pw2) return 0;
            else if(pb2 < pw2) return 1;
            else {
                if(ob > ow) return 0;
                else if(ob < ow) return 1;
                else return 2;   
            }
        } else if(pb1 > pw1) {
            return 0;
        } else {
            return 1;
        }
    } else if(pb1 != -1 && pb2 != -1) {
        return 0;
    } else if(pw1 != -1 && pw2 != -1) {
        return 1;
    }

    //pair
    
    //cout << "pair" << endl;

    pb1 = -1;
    pw1 = -1;
    
    for(auto it = fvb.begin(); it != fvb.end(); ++it) {
        if(it->second == 2) pb1 = it->first;
    }
    
    for(auto it = fvw.begin(); it != fvw.end(); ++it) {
        if(it->second == 2) pw1 = it->first;
    }

    if(pb1 != -1 && pw1 != -1) {
        if(pb1 > pw1) return 0;
        else if(pb1 < pw1) return 1;
        else {
            res = breaktie(true, true, black, white);
            if(res != -1) return res;
        }
    } else if(pb1 != -1) {
        return 0;
    } else if(pw1 != -1) {
        return 1;
    }

    //high card
    
    //cout << "high card" << endl;

    res = breaktie(true, true, black, white);

    if(res != -1) return res;

    return 2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    char v, s;

    while(cin >> v >> s) {
        
        vector<pair<char, char>> black(5);
        
        black[0].first = v;
        black[0].second = s;

        fori(i, 4) {
            cin >> black[i+1].first >> black[i+1].second;
        }
        
        vector<pair<char, char>> white(5);
       
        fori(i, 5) {
            cin >> white[i].first >> white[i].second;
        }
        
        sort(all(black), cmp);
        sort(all(white), cmp);
        
       // print(black);
      //  print(white);
        
        int res = solve(black, white);

        if(res == 0) cout << "Black wins.\n";
        else if(res == 1) cout << "White wins.\n";
        else cout << "Tie.\n";

    }

    return 0;
}
