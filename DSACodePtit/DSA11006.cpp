// Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo xoắn ốc (spiral-order). Phép. Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt spiral-order: 1 2 3  4 5 6 7.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Output:

// Đưa ra kết quả phép duyệt level-order theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 2
// 1 2 R 1 3 L
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R

// 1 3 2

// 10 0 30 60 40

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

void freeTree(Node* root){
    if(root == nullptr) return;
    
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void printTree(Node* root){
    if(root == nullptr) return;
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* node = s1.top();
            s1.pop();

            cout << node->val << " ";
            if(node->right){
                s2.push(node->right);
            }

            if(node->left){
                s2.push(node->left);
            }
        }

        while(!s2.empty()){
            Node* node = s2.top();
            s2.pop();

            cout << node->val << " ";
            if(node->left){
                s1.push(node->left);
            }

            if(node->right){
                s1.push(node->right);
            }
        }
    }
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
        else if(x == 'R'){
            parent->right = child;
        }
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