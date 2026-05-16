// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng trung tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// T, exp thỏa màng ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Ví dụ:

// Input

// Output

// 2

// ABC++

// AB*C+

// (A+(B+C)

// ((A*B)+C)

#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postFixToInFix(string s){
    stack<string> st;

    for(char c : s){
        if(isOperator(c)){
            string a = st.top();
            st.pop();

            string b = st.top();
            st.pop();

            string res = "(" + b + string(1 , c) + a + ")";
            st.push(res);
        }
        else{
            st.push(string(1 , c));
        }
    }
    return st.top();
}

void testCase(){
    string s;
    cin >> s;
    cout << postFixToInFix(s) << endl;
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