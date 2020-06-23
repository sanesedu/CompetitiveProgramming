
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

class Node {

    public:
        Node* left;
        Node* right;
        int data;
};

int val;

void print(Node* root, int spaces) {
   
    if(root != nullptr) {
        if(root->left != nullptr) {
            print(root->left, spaces+1);
        }
        fori(i, spaces) {
            cout << " ";
        }
        cout << root->data << endl;
        if(root->right != nullptr) {
            print(root->right, spaces+1);
        }
    } 

}

void build(Node* root) {

    cin >> val;

    if(val != -1) {
        root->left = new Node();
        root->left->data = val; 
        build(root->left);
    }
        
    cin >> val;

    if(val != -1) {
        root->right = new Node();
        root->right->data = val; 
        build(root->right);
    }
}

bool isBST(Node* root, int mn, int mx) {
    
    if(root == NULL) return true;
    if((mn != -1 && root->data <= mn) || (mx != -1 && root->data >= mx)) return false;

    return isBST(root->left, mn, root->data) && isBST(root->right, root->data, mx);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q;
    cin >> q;

    while(q--) {
        
        cin >> val;

        if(val == -1) {
            cout << "SI\n";
        } else {

            Node* root = new Node();
            
            root->data = val;
            
            build(root);
            
//            print(root, 0);

            if(isBST(root, -1, -1)) cout << "SI\n";
            else cout << "NO\n"; 

            delete root;
        }
    }

    return 0;
}
