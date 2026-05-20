// Cho một mảng là phép duyệt level-order của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là xây dựng lại cây nhị phân tìm kiếm bảo toàn được cấu trúc cây nhị phân ban đầu.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm dòng: dòng đầu tiên đưa vào số N là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào phép duyệt level-order của cây tìm kiếm; các số được viết cách nhau một vài khoảng trống.
// T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤node≤104;

// Output:

// Đưa ra kết quả mỗi test theo từng dòng là phép duyệt trước (preOrder) của cây tìm kiếm.

// Ví dụ:

// Input

// Output

// 2
// 9
// 7 4 12 3 6 8 1 5 10
// 6
// 1 3 4 6 7 8

// 7 4 3 1 6 5 12 8 10
// 1 3 4 6 7 8

#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
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

void printTree(Node* root){
    if(root == nullptr) return;

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

void freeTree(Node* root){
    if(root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void testCase(){
    int n , val;
    cin >> n;

    Node* root = nullptr;
    for(int i=0;i<n;i++){
        cin >> val;
        root = insert(root , val);
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