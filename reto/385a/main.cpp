
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 0x3F3F3F3F

using namespace std ;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool visited[1001][1001] ;

int r, c , x, y, goalx, goaly, res = INF;

char arr[1001][1001] ;

struct BFSstate{
    int coordx;
    int coordy;
    int dist;
};

bool isValid(int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int bfs(int inix, int iniy) {

    queue<BFSstate> q;

    BFSstate p;

    visited[inix][iniy] = true;

    if(arr[inix][iniy] == 'D' || arr[goalx][goaly] == 'D') return res;

    p.coordx = inix; 
    p.coordy = iniy; 
    p.dist = 1;

    q.push(p);

    while(!q.empty()) {
        
        p = q.front();
        q.pop();

        fori(i, 4) {
            x = dx[i] + p.coordx;
            y = dy[i] + p.coordy;
            
            if(isValid(x, y) && (arr[x][y] == '.' || arr[x][y] == 'P') && p.dist < res) {
                if(!visited[x][y]) {
                    
                    visited[x][y] = true;
                    
                    if(arr[x][y] == 'P') {
                        res=p.dist;
                    } else {
                        BFSstate aux;
                        aux.coordx = x; 
                        aux.coordy = y; 
                        aux.dist = p.dist+1;
                        q.push(aux);
                    }
                }
            }
        }
    }
    return res;
}
int main()
{
    int inix,iniy;
    int t;
    cin >> t;
    
    while(t--) {
        res = INF;
        inix = iniy = 0;

        scanf("%d%d",&c,&r);
        
        fori(i, r) {
            fori(j, c) {
                visited[i][j] = false;
            }
        }

        fori(i, r) {
            fori(j, c) {
        
                char a;
        
                cin>>a;
        
                if(a == 'E') {
                    inix = i; 
                    iniy = j;
                } else if(a == 'P') {
                    goalx = i;
                    goaly = j;
                }
                arr[i][j] = a;
            }
        }

        fori(i, r) {
            fori(j, c) {
                char a = arr[i][j];
                
                if(isdigit(a)) {
                    
                    arr[i][j] = a;
                    
                    int p = a - '0';

                    fori(k, 4) {
                        forb(l, 1, p) {
                            int nx = i + l * dx[k];
                            int ny = j + l * dy[k];
                            if(isValid(nx, ny)) {
                                if(arr[nx][ny] == '#') break;
                                else if(!isdigit(arr[nx][ny])) arr[nx][ny] = 'D';
                            }
                        }
                    }
                }
            }
        }

        if(bfs(inix,iniy) != INF) cout << res << endl;
        else cout << "NO\n";
    }
    return 0 ;
}
