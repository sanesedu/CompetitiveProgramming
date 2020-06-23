
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int di[]={1,-1,0,0,1,-1,-1,1};
int dj[]={0,0,1,-1,1,-1,1,-1};
char arr[1001][1001];
int r,c,res;

void dfs(int a, int b){
    int cnt=0;
        for(int i=0;i<8;i++){
            int I=a+di[i];
            int J=b+dj[i];
            if(I>=0 && I<r && J>=0 && J<c && arr[I][J]=='*')  cnt++;
        }
    if(cnt>=6) res++;
}

int main()
{
    while(scanf("%d%d",&c,&r)==2 && (r!=0 && c!=0))
    {
        for(int i=0; i<r;i++)
          for(int j=0; j<c;j++) cin>>arr[i][j];
        res=0;
        for(int i=0; i<r;i++)
          for(int j=0; j<c;j++)
              if(arr[i][j]=='-') dfs(i,j);
        cout<<res<<'\n';
    }
    return 0;
}
