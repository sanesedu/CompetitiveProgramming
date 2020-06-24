
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MAX_BOLTS 500
#define MAX_NUTS  500

using namespace std;

int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];

void read_input_data(void) {
    int n,b;
    
    scanf("%d%d", &bolts, &nuts);
    
    for(b = 0; b < bolts; ++b) {
        for(n = 0; n < nuts; ++n){
            scanf("%d", &fits[b][n]);
        }
    }
}

int nut_used[MAX_NUTS];
int bestmatched;

void init_match(void) {
    int n;
    bestmatched = 0;
    for(n = 0; n < nuts; ++n) nut_used[n] = 0;
}

void match_bolt(int boltno, int matched) {
    
    int n;
    
    if(boltno == bolts){    
        if(matched > bestmatched) bestmatched = matched;
        return;
    }
    
    match_bolt(boltno+1, matched);
    
    for(n = 0; n < nuts; ++n) {
        if(!nut_used[n] && fits[boltno][n]) {
            nut_used[n] = 1;
            match_bolt(boltno+1,matched+1);
            nut_used[n] = 0;
        }
    }
}

int main(){

    int cases,caseno;
    scanf("%d",&cases);

    for(caseno = 1; caseno <= cases; ++caseno){
        read_input_data();
        init_match();
        match_bolt(0,0);
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}

