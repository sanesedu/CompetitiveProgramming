
#include <iostream>

using namespace std;

int main(){

    int n, t, hours, minutes, seconds;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> t;

        hours = t/3600;
        int temp = t%3600;
        minutes = temp/60;
        temp = t%60;
        seconds = temp;
        
        printf("%d%d:%d%d:%d%d\n", hours/10, hours%10, minutes/10, minutes%10, seconds/10, seconds%10);


    }

}
