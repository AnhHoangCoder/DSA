// Cho một cây biểu thức là một cây nhị phân đầy đủ bao gồm các phép toán +, -, *. / và một số toán hạng có giá trị nguyên. Nhiệm vụ của bạn là hãy tính toán giá trị biểu thức được biểu diễn trên cây nhị phân đầy đủ. Ví dụ với cây dưới đây là biểu diễn của biểu thức P = ( (5*4) + (100-20)) sẽ cho ta giá trị là 100.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là gồm hai dòng: dòng thứ nhất đưa vào N là số lượng node của cây; dòng thứ hai đưa vào nội dung các node của cây; các node được viết cách nhau một vài khoảng trống. Các số có giá trị nguyên không vượt quá 1000.
// T, N, P thỏa mãn ràng buộc : 1≤T≤100; 1≤N, lenght(P)≤100.
// Output:

// Đưa ra giá trị của cây biểu thức.
// Ví dụ:

// Input

// Output

// 2
// 7
// + * - 5 4 100 20
// 3
// - 4 7 

// 100
// -3

#include <iostream>
#include <vector>

using namespace std;

bool isOperator(string s){
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

struct Node{
    string val;
    Node* left;
    Node* right;
    Node(string v) : val(v) , left(nullptr) , right(nullptr){}
};

Node* buildTree(vector<string> &a , int i , int n){
    if(i >= n) return nullptr;

    Node* root = new Node(a[i]);

    root->left = buildTree(a , 2*i + 1 , n);
    root->right = buildTree(a , 2*i + 2 , n);

    return root;
}

int solve(Node* node){
    if(!isOperator(node->val)){
        return stoi(node->val);
    }

    int left = solve(node->left);
    int right = solve(node->right);

    if(node->val == "+") return left + right;
    if(node->val == "-") return left - right;
    if(node->val == "*") return left * right;
    return left / right;
}

void testCase(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    Node* root = buildTree(a , 0 , n);
    cout << solve(root) << endl;
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