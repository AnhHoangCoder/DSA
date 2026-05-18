// Cho cây nhị phân, nhiệm vụ của bạn là dịch chuyển cây nhị phân thành cây nhị phân tìm kiếm. Phép dịch chuyển phải bảo toàn được cấu trúc cây nhị phân ban đầu. Ví dụ dưới đây sẽ minh họa phép dịch chuyển:

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng là phép duyệt Inorder của cây tìm kiếm.
// Ví dụ:

// Input

// Output

// 2
// 2
// 1 2 R 1 3 L
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R

// 1 2 3
// 10 20 30 40 60

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

void store(Node* root , vector<int> &a){
    if(root == nullptr) return;

    store(root->left , a);
    a.push_back(root->val);
    store(root->right , a);
}

void buildTree(Node* root , vector<int> &a , int& idx){
    if(root == nullptr){
        return;
    }

    buildTree(root->left , a , idx);
    root->val = a[idx++];
    buildTree(root->right , a , idx);
}

void inorder(Node* root){
    if(root == nullptr){
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void freeTree(Node* root){
    if(root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void testCase(){
    int n , par , child;
    char c;
    cin >> n;
    Node* root = nullptr;
    vector<int> a;
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
    while(--n){
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

    store(root , a);
    sort(a.begin() , a.end());

    int idx = 0;
    buildTree(root , a , idx);
    inorder(root);
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
