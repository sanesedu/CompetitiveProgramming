
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Candidate {
    public:
        int id, votes;
        string name;

    bool operator<(const Candidate &other) {
        if(votes == other.votes) return id < other.id;
        else return votes > other.votes;
    }
};

void addvote(vector<Candidate> &arr, int id) {
    for(auto it = arr.begin(); it != arr.end(); ++it) {
        if(it->id == id) {
            it->votes++;
            break;
        }
    }
}

void printcands(vector<Candidate> arr) {
    for(auto it = arr.begin(); it != arr.end(); ++it) {
        cout << it->id << " " << it->name << " " << it->votes << endl;
    }
    cout << endl;
}

void printvotes(vector<vector<int>> votes) {
    for(auto it = votes.begin(); it != votes.end(); ++it) {
        for(auto jit = it->begin(); jit != it->end(); ++jit) {
            cout << *jit << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void recount(vector<Candidate> &arr, vector<vector<int>> &votes, vector<int> todel) {
    
    int len = todel.size();

    fori(i, len) arr.pop_back();

    bool change;

    for(auto it = votes.begin(); it != votes.end(); ++it) {
        change = false;
        for(auto jit = todel.begin(); jit != todel.end(); ++jit) {
            auto pos = find(all(*it), *jit);
            if(pos == it->begin()) change = true;
            it->erase(pos);
        } 
        if(change) addvote(arr, *begin(*it));
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n;
    cin >> t;

    string name, line;

    while(t--) {
        cin >> n;

        vector<Candidate> arr;
    
        cin.ignore();

        fori(i, n) {
            getline(cin, name); 
            Candidate c;
            c.id = i+1;
            c.votes = 0;
            c.name = name;
            arr.pb(c);
        }

        vector<vector<int>> votes;

        while(getline(cin, line)) {
            if(line.empty()) break;
           
            vector<int> ballot(n);

            stringstream ss(line);
            
            fori(i, n) ss >> ballot[i];
        
            addvote(arr, ballot[0]);
            
            votes.pb(ballot);
        }
        
        int running = n;
        int numvotes = votes.size();

        while(true) {        

            if(arr.size() == 1) {
                cout << arr[0].name << endl;
                break;
            }

            sort(all(arr));
            
 //           printcands(arr);
  //          printvotes(votes);
           
            if(arr[0].votes > numvotes/2) {
                cout << arr[0].name << endl;
                break;
            } else {
                vector<int> todel;
                int mn = arr.rbegin()->votes;
                for(auto it = arr.rbegin(); it != arr.rend(); ++it) {
                    if(it->votes == mn) todel.pb(it->id);
                    else break;
                }
                
                running -= todel.size();
                
                if(running == 0) {
                    for(auto it = arr.begin(); it != arr.end(); ++it) {
                        cout << it->name << endl;
                    }
                    break;
                } else {
                    recount(arr, votes, todel);
                }
            } 
        }
        if(t) cout << endl;
//        cout << "-----------------" << endl;
    }

    return 0;
}
