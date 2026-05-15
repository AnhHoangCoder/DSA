// Cho hai cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có giống nhau hay không?

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái của mỗi cây; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 2
// 1 2 L 1 3 R
// 2
// 1 2 L 1 3 R
// 2
// 1 2 L 1 3 R
// 2
// 1 3 L 1 2 R

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

inline void nhap(Node* &root){
    int n;
    cin >> n;
    
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
}

bool check(Node* root1 , Node* root2){

    // cả 2 đều null
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    // 1 null 1 không
    if(root1 == nullptr || root2 == nullptr){
        return false;
    }

    // khác giá trị
    if(root1->val != root2->val){
        return false;
    }

    // kiểm tra tiếp 2 cây con
    return check(root1->left , root2->left)
        && check(root1->right , root2->right);
}


void testCase(){
    Node* root1 = nullptr;
    Node* root2 = nullptr;
    nhap(root1);
    nhap(root2);
    
    cout << (check(root1 , root2) ? 1 : 0) << endl;
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