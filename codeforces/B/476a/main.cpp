
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    char s1[15], s2[15] ;

    scanf("%s%s", s1, s2) ;

    int n = strlen(s1) ;

    int answerPosition = 0 ;
    
    fori(i, n)
        answerPosition += (s1[i]=='+'?1:-1) ;

    int finalPosition = 0 ;
    int moves = 0 ; //number of '?'
    
    fori(i, n) {
        if(s2[i] == '?') {
            moves++ ;
        } else {
            finalPosition += (s2[i] == '+') ? 1:-1;
        }
    }

    int distance = answerPosition-finalPosition ;
    double answer ;
    
    if((distance+moves) % 2 != 0 || moves < abs(distance)) { //can't reach the destination no matter how
        answer = 0 ;
    } else {
        int m = (moves + abs(distance))/2 ; //moves needed toward the distance m is abs(distance)+(moves-abs(distance))/2
        //answer is C(moves,m)/(1<<moves)
        int c = 1 ;
        fori(i, m) c *= moves-i;
        
        forb(i, 2, m) c /= i ;
        
        answer = (double)c / (1 << moves) ;
    }

    printf("%.12f\n", answer) ;

    return 0;
}
