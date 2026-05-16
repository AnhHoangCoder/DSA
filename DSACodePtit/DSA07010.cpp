// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng tiền tố về dạng hậu tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Ví dụ:

// Input

// Output

// 2

// *+AB-CD

// *-A/BC-/AKL

// AB+CD-*

// ABC/-AK/L-*

#include <iostream>
#include <stack>

using namespace std;

bool check(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void testCase(){
    string s;
    cin >> s;

    int n = s.size();
    stack<string> st;
    for(int i=n-1;i>=0;i--){
        if(check(s[i])){
            string a = st.top();
            st.pop();

            string b = st.top();
            st.pop();

            string res = a + b + s[i];
            st.push(res);
        }
        else{
            st.push(string(1 , s[i]));
        }
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
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