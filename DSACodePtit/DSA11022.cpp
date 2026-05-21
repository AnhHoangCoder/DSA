// Cho dãy số gồm N số là phép duyệt theo thứ tự trước (Preorder) của một cây nhị phân tìm kiếm. Hãy đưa ra số các node trung gian của cây ?

// Ví dụ với dãy A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45} là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả là 5 bao gồm các node: 30, 20, 25, 40, 35.                     

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤1000). Dòng tiếp theo là N số là phép duyệt theo thứ tự trước của cây BST.

// Output:

// Đưa ra kết quả mỗi test theo từng dòng.

// Ví dụ:

// Input:

// Output

// 2

// 6

// 10 5 1 7 40 50

// 11

// 30 20 15 25 23 28 40 35 33 38 45

// 3

// 5

#include <iostream>

using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

Node* insert(Node* root , int val){
    if(root == nullptr) return new Node(val);

    if(val < root->val){
        root->left = insert(root->left , val);
    }
    else{
        root->right = insert(root->right , val);
    }
    return root;
}

int checkCount(Node* root){
    if(root == nullptr) return 0;
    
    int s = 0;
    if(root->left != nullptr || root->right != nullptr){
        s = 1;
    }

    return s + checkCount(root->left) + checkCount(root->right);
}

void freeTree(Node* root){
    if(root == nullptr){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void testCase(){
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        root = insert(root , x);
    }
    cout << checkCount(root) << endl;
    freeTree(root);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}