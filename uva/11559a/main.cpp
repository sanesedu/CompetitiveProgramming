
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    
    int participants = 0;
    int budget = 0;
    int hotels = 0;
    int weeks = 0;
    int cost = 0; 
    int rooms = 0;

    while(scanf("%d", &participants) != EOF){

        scanf("%d %d %d", &budget, &hotels, &weeks);

        int min = 0;

        for(int i = 0; i < hotels; i++){
            scanf("%d", &cost);
            for(int j = 0; j < weeks; j++){
                scanf("%d", &rooms);
                if(rooms >= participants){
                    if(min == 0){
                        min = cost * participants;
                    } else if(cost * participants < min){
                        min = cost * participants;
                    }
                }
            }
        }

        if(min <= budget && min != 0){
            printf("%d\n", min);
        } else {
            cout << "stay home" << endl;
        }

    }

    return 0;
}
