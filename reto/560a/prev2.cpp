
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll next_greater(vector<int> nums, vector<int> pos, int n) {
 
    stack<int> data_stack;
 
    data_stack.push(nums[0]);
    
    ll res = 0;
    
    bool found = true;

    for (int i = 1; i < n; i++) {
        int next_element = nums[i];
 
        if (data_stack.empty() == false) {

            int array_element = data_stack.top();
            data_stack.pop();

            found = false;

            while(array_element < next_element) {
                cout << array_element << ": " << next_element << " " << pos[next_element] - pos[array_element] << endl;
                res += pos[next_element] - pos[array_element];
                found = true;
                if (data_stack.empty() == true) break;
                array_element = data_stack.top();
                data_stack.pop();
            }
 
           if (array_element > next_element) {
               data_stack.push(array_element);
           }

           if(!found) {
               res += (n - i);
           }
           
        }
 
        data_stack.push(next_element);
         
    }
   
    cout << res << endl;

    return res; 
} 

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, t, val;

    ll res;

    while(cin >> n) {
        if(n == 0) break;

        vector<int> arr(n);
        vector<int> pos(n+1);

        fori(i, n) {
            cin >> arr[i];
            cout << arr[i] << " ";
            pos[arr[i]] = i;
        }
        cout << endl;
        
        next_greater(arr, pos, n);    
    }

    return 0;
}
