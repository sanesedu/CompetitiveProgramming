
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
typedef pair<int, int> ii;

class Proposal {
    public:
        string name;
        float price;
        int met;
        
        Proposal(string n, float p, int m) {
            name = n;
            price = p;
            met = m;
        }

        Proposal() {
            name = "";
            price = 10000000;
            met = -1;
        }

        void print() {
            cout << name << " " << price << " " << met << endl;
        }
};

bool cmp(Proposal a, Proposal b) {
    if(a.met == b.met) {
        if(a.price == b.price) {
            return false;
        } else {
            return a.price > b.price;
        }
    } else {
        return a.met < b.met;
    }
}

int main() {

    cout.precision(10);

    int num_reqs, num_props, index = 1;
    string t;
    string name;
    float price;
    int met_reqs;

    while(scanf("%d %d", &num_reqs, &num_props), num_reqs || num_props) {
        
        if(index > 1) cout << endl;

        fori(i, num_reqs) {
            cin.ignore();
            getline(cin, t);
        }

        Proposal* best = new Proposal();

        while(num_props--) {
            getline(cin, name);
            cin >> price >> met_reqs;

            if(cmp(*best, *(new Proposal(name, price, met_reqs)))) {
                best = new Proposal(name, price, met_reqs);
            }

            cin.ignore();
            fori(i, met_reqs) {
                getline(cin, t);
            }
        }
        
        cout << "RFP #" << index++ << endl;
        cout << best->name << endl;

        delete best;
    }
    
    return 0;
}
