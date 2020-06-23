#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;
int main()
{
	ll a; cin >> a; (a % 2 == 0) ? cout << "4 " << a - 4 : cout << "9 " << a - 9; return 0;	
}
