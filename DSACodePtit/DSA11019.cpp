// Cho một mảng A[] gồm N phần tử biểu diễn phép duyệt preorder của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là đưa ra phép duyệt postorder của cây nhị phân tìm kiếm.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào phép duyệt preorder của cây tìm kiếm; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng là phép duyệt postorder của cây tìm kiếm.
// Ví dụ:

// Input

// Output

// 2
// 5
// 40 30 35 80 100
// 8
// 40 30 32 35 80 90 100 120

// 35 30 100 80 40
// 35 32 30 120 100 90 80 40

#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

Node* insert(Node* root , int val){
    if(root == nullptr){
        return new Node(val); 
    }

    if(val < root->val){
        root->left = insert(root->left , val);
    }
    else{
        root->right = insert(root->right , val);
    }
    return root;
}

void printTree(Node* root){
    if(root == nullptr) return;

    printTree(root->left);
    printTree(root->right);
    cout << root->val << " ";
}

void freeTree(Node* root){
    if(root == nullptr) return;
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

    printTree(root);
    freeTree(root);
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