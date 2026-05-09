// Cho phép duyệt cây nhị phân Inorder và Preorder, hãy đưa ra kết quả phép duyệt Postorder của cây nhị phân. Ví dụ với cây nhị phân có các phép duyệt cây nhị phân của cây dưới đây:

//          1
//       /    \    
//      2       3
//    /   \      \
//   4     5      6
// Inorder     : 4  2  5  1  3  6

// Preorder:  : 1  2  4  5  3  6

// Postorder : 4  5  2  6  3  1 

//      Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng node; dòng tiếp theo đưa vào N số theo phép duyệt Inorder; dòng cuối cùng đưa vào N số là kết quả của phép duyệt Preorder; các số được viết cách nhau một vài khoảng trống.
// T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤1000; 1≤ giá trị node ≤104;
// Output:

// Đưa ra kết quả phép duyệt Postorder theo từng dòng.
//      Ví dụ:

// Input

// Output

// 1

// 6
// 4  2  5  1  3  6

// 1  2  4  5  3  6
 

// 4  5  2  6  3  1

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> Pre , Ino;
unordered_map<int,int> pos;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void postorder(Node* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);

    cout << root->val << " ";
}

Node* build(int inL , int inR , int preL , int preR){
    if(inL > inR || preL > preR) return nullptr;
    
    int rootVal = Pre[preL];
    int k = pos[rootVal];
    int leftSize = k - inL;

    Node* root = new Node(rootVal);

    root->left = build(inL , k - 1 , preL + 1 , preL + leftSize);
    root->right = build(k+1 , inR , preL + leftSize + 1 , preR);

    return root;
}
void testCase(){
    int n;
    cin >> n;

    Ino.resize(n);
    Pre.resize(n);

    pos.clear();

    nhap(Ino , n);
    nhap(Pre , n);

    for(int i=0;i<n;i++){
        pos[Ino[i]] = i;
    }

    Node* root = build(0 , n-1 , 0 , n-1);
    postorder(root);
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