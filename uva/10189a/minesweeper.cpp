
#include <iostream>

using namespace std;

void compute(int arr[100][100], int n, int m){
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != -1){
                int a1 = (i == 0) ? i:(i-1);
                int b1 = (j == 0) ? j:(j-1);
                int a2 = (i == n-1) ? i:(i+1);
                int b2 = (j == m-1) ? j:(j+1);

                int val = 0;

                for(int k = a1; k <= a2; k++){
                    for(int h = b1; h <= b2; h++){
                        if(arr[k][h] == -1){
                            val++;
                        }
                    }
                }
                
                arr[i][j] = char(val);

            }
        }
    }
}

int main(){
 
    int n, m;

    bool b = true;
            
    int arr[100][100];

    int field = 1;

    while(b){
        cin >> n >> m;

        if(n == 0 && m == 0){
            b = false;
        } else {        

            if(field != 1){
                cout<<endl;
            }
                        
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    char temp;
                    cin >> temp;
                    if(temp == '*'){
                        temp = -1;
                    } else {
                        temp = 0;
                    }
                    arr[i][j] = temp;
                }
            }

            compute(arr, n, m);
            
            cout << "Field #" << field << ":" <<endl;

            for(int k = 0; k < n; k++){
                for(int h = 0; h < m; h++){
                    if(arr[k][h] == -1){
                        cout<<"*";   
                    } else{
                        cout << arr[k][h];
                    }
                }
                cout << endl;
            }

            field++;

        }
    }
}
