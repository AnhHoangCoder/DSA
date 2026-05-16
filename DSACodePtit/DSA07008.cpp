// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng trung tố về dạng hậu tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤10.
// Các phép toán bao gồm +, -, *, /, ^. Phép lũy thừa có ưu tiên cao hơn nhân chia và cộng trừ.
// Ví dụ:

// Input

// Output

// 2

// (A+(B+C)

// ((A*B)+C)

// ABC++

// AB*C+

#include <iostream>
#include <stack>

using namespace std;

int priority(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string s){
    stack<char> st;
    string res = "";

    for(char c : s){
        if(isalnum(c)){
            res += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(st.top()) >= priority(c)){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;
}

void testCase(){
    string s;
    cin >> s;
    cout << infixToPostfix(s) << endl;
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