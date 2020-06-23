
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 21

#define U 0
#define D 1
#define L 2
#define R 3

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Snake {
    public:
        pair<int, int> head;
        deque<pair<int, int>> snake; //{row, col}
        int dir;
        
        void init() {
            fori(i, 9) {
                snake.pb({11+i, 10});
            }
            head = {10,10};
            dir = U;
        }
        
        void move() {
            snake.pop_back();    
            snake.push_front(head);
            if(dir == U) {
                --head.first;
            } else if(dir == D) {
                ++head.first;
            } else if(dir == L) {
                --head.second;
            } else if(dir == R) {
                ++head.second;
            }
        }

        void changedir(char newdir) {
            if(newdir == 'U') dir = U;
            else if(newdir == 'D') dir = D;
            else if(newdir == 'L') dir = L;
            else if(newdir == 'R') dir = R;
        }

        void grow() {
            snake.push_back(snake.back()); 
        }

        bool check() { //true == gameover
            if(head.first == -1 || head.second == -1 || head.first == N || head.second == N) return true;
            else {
                if(find(all(snake), head) != snake.end()) return true;
            }
            return false;
        }

        void print() {
            for(auto it = snake.begin(); it != snake.end(); ++it) {
                cout << "(" << it->first << ", " << it->second << ") -> ";
            }
            cout << endl;
        }

        void draw() {
            fori(i, N) {
                fori(j, N) {
                    if(make_pair(i, j) == head || find(all(snake), make_pair(i, j)) != snake.end()) {
                        cout << 1;
                    } else {
                        cout << 0;
                    }
                }
                cout << endl;
            }
            cout << endl; 
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, tm, t, id;

    string line;

    while(getline(cin, line)) {

        stringstream ss(line);

        ss >> n;

        if(n == 0) break;
       
        vector<pair<int, char>> arr(n);

        fori(i, n) {
            ss >> arr[i].first >> arr[i].second;
        }

        id = 0;
        t = 1;

        Snake s;
        s.init();

        while(true) {
            
            s.move();
            if(s.check()) break;
            
            if(t > 0 && t % 10 == 0) {
                s.grow();
            } 
            
            if(id < n && t == arr[id].first) {
                s.changedir(arr[id].second);
                ++id;
            } 
            
//            s.draw();
 //           s.print();
            
            ++t;

        }

        cout << t-1 << endl;
    }

    return 0;
}
