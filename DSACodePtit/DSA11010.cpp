// Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây hoàn hảo hay không (perfect tree)? Một cây nhị phân được gọi là cây hoàn hảo nếu tất cả các node trung gian của nó đều có hai node con và tất cả các node lá đều có cùng một mức.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 3
// 6
// 10 20 L 10 30 R 20 40 L 20 50 R 30 60 L 30 70 R
// 2
// 18 15 L 18 30 R
// 5
// 1 2 L 2 4 R 1 3 R 3 5 L 3 6 R

// Yes
// Yes
// No

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

bool isPerfect(Node* root , int dep , int level){
    if(root == nullptr){
        return true;
    }

    if(root->left == nullptr && root->right == nullptr){
        return dep == level + 1;
    }

    if(root->left == nullptr || root->right == nullptr){
        return false;
    }

    return isPerfect(root->left , dep , level + 1) && isPerfect(root->right , dep , level + 1);
}

int leftDepth(Node* root){
    int d = 0;
    while(root){
        d++;
        root = root->left;
    }
    return d;
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
    unordered_map<int,Node*> mp;

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

    int d = leftDepth(root);
    cout << (isPerfect(root , d , 0) ? "Yes" : "No") << endl;
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