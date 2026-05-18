// Cho cây nhị phân, nhiệm vụ của bạn là tính tổng của tất cả các node lá bên phải trên cây? Ví dụ với cây dưới đây ta có kết quả là 2.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 2
// 1 2 L 1 3 R
// 5
// 10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

// 3
// 60

#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

ll sum;

bool isLeaf(Node* root){
    return root->left == nullptr && root->right == nullptr;
}

inline void calc(Node* root){
    if(root == nullptr) return;
    if(root->right != nullptr && isLeaf(root->right)){
        sum += root->right->val;
    }
    if(root->right != nullptr && !isLeaf(root->right)){
        calc(root->right);
    }
    if(root->left != nullptr && !isLeaf(root->left)){
        calc(root->left);
    }
}

void freeTree(Node* root){
    if(root == nullptr) return;

    freeTree(root->left);
    freeTree(root->right);

    delete root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t , n , par , child , ori;
    char c;
    cin >> t;

    while(t--){
        cin >> n;
        ori = n;
        Node* root = nullptr;
        unordered_map<int,Node*> mp;
        cin >> par >> child >> c;

        root = new Node(par);
        if(c == 'L'){
            root->left = new Node(child);
            mp[child] = root->left;
        }
        else{
            root->right = new Node(child);
            mp[child] = root->right;
        }
        mp[par] = root;
        --n;
        while(n--){
            cin >> par >> child >> c;
            if(c == 'L'){
                mp[par]->left = new Node(child);
                mp[child] = mp[par]->left;
            }
            else{
                mp[par]->right = new Node(child);
                mp[child] = mp[par]->right;
            }
        }

        sum = 0;
        calc(root);
        cout << sum << endl;
        freeTree(root);
    }
    return 0;
}