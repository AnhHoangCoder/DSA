// Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
// Ví dụ:

 

// Input

// Output

// 3

// ((a+b))

// (a + (b)/c)

// (a + b*(c-d))

// Yes

// Yes

// No

#include <iostream>
#include <stack>

using namespace std;

bool check(string &s){
    stack<char> st;

    for(char c : s){
        if(c == ')'){
            bool hasOp = false;

            while(!st.empty() && st.top() != '('){
                char t = st.top();
                if(t == '+' || t == '-' || t == '*' || t == '/'){
                    hasOp = true;
                }
                st.pop();
            }
            if(!hasOp){
                return true;
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else if (c != ' '){
            st.push(c);
        }
    }
    return false;
}

void testCase(){
    string s;
    getline(cin , s);
    cout << (check(s) ? "Yes" : "No") << endl; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        testCase();
    }
    return 0;
}