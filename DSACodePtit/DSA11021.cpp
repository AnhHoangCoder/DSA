// Cho dãy số gồm N số là phép duyệt theo thứ tự trước (Preorder) của một cây nhị phân tìm kiếm. Hãy in ra tất cả các node lá của cây ?

// Ví dụ với dãy A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45} là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả: 15, 23, 28, 33, 38, 45.                                           

//     Input:

// Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤1000). Dòng tiếp theo là N số là phép duyệt theo thứ tự trước của cây BST.
//    Output:

// Đưa ra kết quả mỗi test theo từng dòng.
//    Ví dụ:

// Input

// Output

// 2

// 6

// 10 5 1 7 40 50

// 11

// 30 20 15 25 23 28 40 35 33 38 45

// 1 7 50

// 15 23 28 33 38 45

#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int v) : key(v) , left(nullptr) , right(nullptr){}
};

Node* insert(Node* node , int x){
    if(node == NULL){
        return new Node(x);
    }
    if(node->key == x){
        return node;
    }
    if(node->key > x){
        node->left = insert(node->left , x);
    }
    else{
        node->right = insert(node->right , x);
    }
    return node;
}

void printNode(Node* node){
    if(node == nullptr) return;
    printNode(node->left);
    if(node->left == nullptr && node->right == nullptr){
        cout << node->key << " ";
    }
    printNode(node->right);
}

void testCase(){
    int n;
    cin >> n;

    Node* root = nullptr;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        root = insert(root , x);
    }
    printNode(root);
    cout << endl;
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