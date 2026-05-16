// Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).

// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng.

// Ví dụ:

// Input:

// Output

// 4

// ))((

// ((((

// (((())

// )(())(((

// 2

// 2

// 1

// 3

#include <iostream>
#include <stack>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    stack<char> st;

    for(char c : s){
        if(c == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        else{
            st.push(c);
        }
    }

    int n = 0 , m = 0;
    while(!st.empty()){
        char t = st.top();
        if(t == '('){
            n++;
        }
        else{
            m++;
        }
        st.pop();
    }

    int ans = ((n + 1) / 2) + ((m + 1) / 2);

    cout << ans << endl;
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