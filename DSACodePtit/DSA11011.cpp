// Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây đủ hay không (full binary tree)? Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 4
// 1 2 L 1 3 R 2 4 L 2 5 R
// 3
// 1 2 L 1 3 R 2 4 L

// 1
// 0

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

bool fullTree(Node* root){
    if(root == nullptr) return true;

    if(root->left == nullptr && root->right == nullptr){
        return true;
    }

    if(root->left != nullptr && root->right != nullptr){
        return fullTree(root->left) && fullTree(root->right);
    }

    return false;
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

    unordered_map<int,Node*> mp;
    Node* root = nullptr;
    while(n--){
        int u , v;
        char x;
        cin >> u >> v >> x;

        if(mp.find(u) == mp.end()){
            mp[u] = new Node(u);
        }

        if(mp.find(v) == mp.end()){
            mp[v] = new Node(v);
        }

        Node* parent = mp[u];
        Node* child = mp[v];

        if(root == nullptr){
            root = parent;
        }

        if(x == 'L'){
            parent->left = child;
        }

        if(x == 'R'){
            parent->right = child;
        }
    }

    cout << (fullTree(root) ? 1 : 0) << endl;
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