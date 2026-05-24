// Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đưa ra phép duyệt theo thứ tự sau (post-order) của cây tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với node gốc là 33 : 15, 23, 20, 30, 28, 25, 35, 38, 45, 40, 33.  

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// Output

// 2

// 11

// 40  28  45 38  33  15  25  20  23  35  30

// 10

// 1  2  3  4  5  6  7  8  9  10

// 20 15 28 25 23 35 33 45 40 38 30

// 1 4 3 2 7 6 10 9 8 5

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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    Node* root = build(a , 0 , n - 1);
    printTree(root);
    cout << endl;
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