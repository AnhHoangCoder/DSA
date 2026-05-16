// Cây biểu thức là một cây nhị phân trong đó mỗi node trung gian là một phép toán, mỗi node lá là một toán hạng. Ví dụ với biểu thức P = 3 + ((5+9)*2) sẽ được biểu diễn như cây dưới đây.
// Đối với cây biểu thức, duyệt theo thứ tự trước ta sẽ được biểu thức tiền tố, duyệt theo thứ tự sau ta sẽ được biểu thức hậu tố, duyệt theo thứ tự giữa ta được biểu thức trung tố. Chú ý, cây biểu thức luôn là cây nhị phân đầy (mỗi node trung gian đều có hai node con).

// Cho biểu thức hậu tố P, hãy sử dụng cây biểu thức để đưa ra biểu thức trung tố tương ứng với biểu thức P.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một biểu thức hậu tố P.
// T, P thỏa mãn ràng buộc : 1≤T≤100; 1≤lengh(P)≤100.
// Output:

// Đưa ra biểu thức trung tố tương ứng với P.
//       Ví dụ:

 

// Input

// Output

// 2
// ab+ef*g*-
// wlrb+-*

// a + b - e * f * g

// w * l - r + b

#include <iostream>
#include <stack>

using namespace std;

struct Node{
    char val;
    Node* left;
    Node* right;
    Node(char v) : val(v) , left(nullptr) , right(nullptr) {}
};

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* buildTree(string &s){
    stack<Node*> st;
    for(char c : s){
        Node* node = new Node(c);
        if(isOperator(c)){
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }
    return st.top();
}

string inorder(Node* root){
    if(!root) return "";
    if(!isOperator(root->val)){
        return string(1 , root->val);
    }
    return inorder(root->left) + root->val + inorder(root->right);
}

void freeTree(Node* root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void testCase(){
    string s;
    cin >> s;
    Node* root = buildTree(s);
    cout << inorder(root) << endl;
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