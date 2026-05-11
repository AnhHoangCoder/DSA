// Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem tất cả các node lá của cây có cùng một mức hay không? Ví dụ với cây dưới đây sẽ cho ta kết quả là Yes.
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

// 2
// 1 2 R 1 3 L
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R

// 1
// 0

#include <iostream>
#include <unordered_map>

using namespace std;

int leafLevel;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr) , right(nullptr){}
};

bool check(Node* node , int level){
    if(node == nullptr) return true;

    if(node->left == nullptr && node->right == nullptr){
        if(leafLevel == -1){
            leafLevel = level;
            return true;
        }
        return level == leafLevel;
    }

    return check(node->left , level + 1) && check(node->right , level + 1); 
}

void testCase(){
    int n;
    cin >> n;

    Node* root = nullptr;
    unordered_map<int , Node*> mp;
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

    leafLevel = -1;
    cout << (check(root , 0) ? 1 : 0) << endl;
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