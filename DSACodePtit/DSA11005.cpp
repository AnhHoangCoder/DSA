// Cho hai mảng là phép duyệt Inorder và Level-order, nhiệm vụ của bạn là xây dựng cây nhị phân và đưa ra kết quả phép duyệt Postorder. Level-order là phép duyệt theo từng mức của cây. Ví dụ như cây dưới đây ta có phép Inorder và Level-order như dưới đây:

// Inorder : 4  8  10  12 14 20 22

// Level order: 20  8  22  4  12  10  14

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng node; dòng tiếp theo đưa vào N số là phép duyệt Inorder; dòng cuối cùng đưa vào N số là phép duyệt Level-order; các số được viết cách nhau một vài khoảng trống.
// T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
// Output:

// Đưa ra kết quả phép duyệt Postorder theo từng dòng.

// Ví dụ:

// Input

// Output

// 2
// 3
// 1 0 2 
// 0 1 2 
// 7
// 3 1 4 0 5 2 6 
// 0 1 2 3 4 5 6 

// 1 2 0

// 3 4 1 5 6 2 0

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> Ino , Leo;
unordered_map<int , int> pos;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

Node* build(int inL , int inR , vector<int>& level){
    if(inL > inR || level.empty()) return nullptr;

    int rootVal = level[0];
    Node* root = new Node(rootVal);

    int idx = pos[rootVal];

    vector<int> leftLevel , rightLevel;
    unordered_set<int> leftSet;

    for(int i=inL;i<idx;i++){
        leftSet.insert(Ino[i]);
    }

    for(int i=1;i<level.size();i++){
        if(leftSet.count(level[i])){
            leftLevel.push_back(level[i]);
        }
        else{
            rightLevel.push_back(level[i]);
        }
    }

    root->left = build(inL , idx - 1 , leftLevel);
    root->right = build(idx+1 , inR , rightLevel);

    return root;
}

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void printTree(Node* node){
    if(node == nullptr) return;

    printTree(node->left);
    printTree(node->right);

    cout << node->val << " ";
}

void testCase(){
    int n;
    cin >> n;
    
    Ino.resize(n);
    Leo.resize(n);
    pos.clear();

    nhap(Ino , n);
    nhap(Leo, n);

    for(int i=0;i<n;i++){
        pos[Ino[i]] = i;
    }

    Node* root = build(0 , n-1 , Leo);
    printTree(root);
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