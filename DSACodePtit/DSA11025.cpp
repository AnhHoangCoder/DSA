// Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đưa ra phép duyệt theo thứ tự trước (preorder) của cây tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với node gốc là 33 : 33, 25, 20, 15, 23, 28, 30, 40, 38, 35, 45.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2

// 11

// 40  28  45 38  33  15  25  20  23  35  30

// 10

// 1  2  3  4  5  6  7  8  9  10

// 30 23 15 20 25 28 38 33 35 40 45

// 5 2 1 3 4 8 6 7 9 10

#include <iostream>
#include <vector>
#include <algorithm>

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

Node* build(vector<int> &a , int l , int r){
    if(l > r) return nullptr;

    int mid = l + (r - l) / 2;
    Node* root = new Node(a[mid]);
    root->left = build(a , l , mid - 1);
    root->right = build(a , mid + 1 , r);
    return root;
}

void printTree(Node* root){
    if(root == nullptr) return;

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    Node* root = build(a , 0 , n - 1);
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