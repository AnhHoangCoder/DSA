// Cho cây nhị phân có giá trị mỗi node là một số, nhiệm vụ của bạn là tìm tổng lớn nhất từ một node lá này sang một node lá khác? Ví dụ với cây dưới đây ta có tổng lớn nhất là 27.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Input có thể chứa nhiều đỉnh có giá trị bằng nhau. Hãy thêm vào nút đầu tiên tìm được theo phép duyệt cây.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 12
// -15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
// 12
// -15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 6 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L

// 27
// 27

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int ans;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

inline void buildTree(Node* &root , int par , int child , char c){
    if(root){
        if(root->val == par){
            if(c == 'L'){
                root->left = new Node(child);
            }
            else{
                root->right = new Node(child);
            }
            return;
        }
        else{
            buildTree(root->left , par , child , c);
            buildTree(root->right , par , child , c);
        }
    }
}

inline int dfs(Node* root){
    if(root == nullptr) return 0;

    if(root->left == nullptr && root->right == nullptr) return root->val;

    int l = dfs(root->left);
    int r = dfs(root->right);

    if(root->left && root->right){
        ans = max(ans , l + r + root->val);
        return max(l , r) + root->val;
    }

    return (root->left ? l : r) + root->val; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t , n , par , child;
    char c;
    cin >> t;
    while(t--){
        cin >> n;
        Node* root = nullptr;
        cin >> par >> child >> c;

        root = new Node(par);
        buildTree(root , par , child , c);
        while(--n){
            cin >> par >> child >> c;
            buildTree(root , par , child , c);
        }
        ans = INT_MIN;
        int tmp = dfs(root);
        cout << (ans == INT_MIN ? tmp : ans) << endl;
    }
    return 0;
}