
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

char board[8][8];

bool kw, kb;

bool isValid(int y, int x) {
    return (y >= 0 && y < 8 && x >= 0 && x < 8);
}

bool cw, cb;

bool handlePawn(int x, int y, char target) {
   
    int row = y;

    if(target == 'k') --row;
    else ++row;

    int col1 = x - 1;     
    int col2 = x + 1;     

    if(isValid(row, col1) && board[row][col1] == target) return true; 
    if(isValid(row, col2) && board[row][col2] == target) return true; 

    return false;
}

bool handleKnight(int x, int y, char target) {

    if (x - 2 >= 0)  {
        if (y - 1 >= 0 && board[y - 1][x - 2] == target) return true;
        if (y + 1 < 8 && board[y + 1][x - 2] == target) return true;
    }
    
    if (x + 2 < 8) {
        if (y - 1 >= 0 && board[y - 1][x + 2] == target) return true;             
        if (y + 1 < 8 && board[y + 1][x + 2] == target) return true;
    }
    
    if (y - 2 >= 0) {
        if (x - 1 >= 0 && board[y - 2][x - 1] == target) return true;         
        if (x + 1 < 8 && board[y - 2][x + 1] == target) return true;
    }
    
    if (y + 2 < 8) {
        if (x - 1 >= 0 && board[y + 2][x - 1] == target) return true;             
        if (x + 1 < 8 && board[y + 2][x + 1] == target) return true;
    }
    
    return false;
}

bool handleBishop(int x, int y, char target) {
    
    int i = y-1, j = x-1;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        --i;
        --j; 
    }
    
    i = y+1;
    j = x+1;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        ++i;
        ++j; 
    }
    
    i = y-1;
    j = x+1;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        --i;
        ++j; 
    }
    
    i = y+1;
    j = x-1;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        ++i;
        --j; 
    }
    
    return false;
}

bool handleRook(int x, int y, char target) {
    
    int i = y-1, j = x;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        --i;
    }
    
    i = y+1;
    j = x;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        ++i;
    }
    
    i = y;
    j = x+1;

    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        ++j; 
    }
    
    i = y;
    j = x-1;
    
    while(isValid(i, j)) {
        if(board[i][j] == target) return true;
        if(board[i][j] != '.') break;
        --j; 
    } 
    
    return false;
}

bool handleKing(int x, int y, char target) {
    
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            int newy = y + j;
            int newx = x + i;
            
            if(isValid(newy, newx) && board[newy][newx] == target) return true;
        }
    }
    
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string line;

    int index = 1;

    while(1) {
    
        kw = kb = false;
    
        fori(i, 8) {
            fori(j, 8) {
                cin >> board[i][j];        
                if(board[i][j] == 'k') kb = true;
                else if(board[i][j] == 'K') kw = true;
            }
        }

        if(!kw) break;
    
        cw = cb = false;

        for(int i = 0; i < 8 && !cb && !cw; ++i) {
            for(int j = 0; j < 8 && !cb && !cw; ++j) {
                if(board[i][j] == '.') {
                    continue;
                } else if(board[i][j] == 'p') {
                    
                    cw = handlePawn(j, i, 'K');
                
                } else if(board[i][j] == 'P') {
                    
                    cb = handlePawn(j, i, 'k');
                    
                } else if(board[i][j] == 'n') {
                    
                    cw = handleKnight(j, i, 'K'); 

                } else if(board[i][j] == 'N') {
                    
                    cb = handleKnight(j, i, 'k'); 
                    
                } else if(board[i][j] == 'b') {
                    
                    cw = handleBishop(j, i, 'K'); 
                
                } else if(board[i][j] == 'B') {
                    
                    cb = handleBishop(j, i, 'k'); 
                
                } else if(board[i][j] == 'r') {
                    
                    cw = handleRook(j, i, 'K'); 
                
                } else if(board[i][j] == 'R') {
                    
                    cb = handleRook(j, i, 'k'); 
                
                } else if(board[i][j] == 'q') {
                    
                    cw = handleRook(j, i, 'K') || handleBishop(j, i, 'K'); 
                
                } else if(board[i][j] == 'Q') {
                    
                    cb = handleRook(j, i, 'k') || handleBishop(j, i, 'k'); 
                
                } else if(board[i][j] == 'k') {
                   
                    cw = handleKing(j, i, 'K');

                } else if(board[i][j] == 'K') {
                    
                    cb = handleKing(j, i, 'k');
                
                }
            }
        }
       
        cout << "Game #" << index++ << ": ";
        
        if(cb) cout << "black king is in check.\n";
        else if(cw) cout << "white king is in check.\n";
        else cout << "no king is in check.\n";

        cin.ignore();
        getline(cin, line);
    }

    return 0;
}
