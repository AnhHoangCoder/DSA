// Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:

// -     Xâu rỗng là 1 dãy ngoặc đúng.

// -     Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

// -     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

// Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm một xâu S có độ dài không vượt quá 105 kí tự.

// Output:  Với mỗi test in ra một số nguyên là độ dài dãy ngoặc đúng dài nhất tìm được.

// Ví dụ:

// Input:

// Output

// 3

// ((()

// )()())

// ()(()))))

 

// 2

// 4

// 6

#include <iostream>
#include <stack>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    int n = s.size();

    stack<int> st;
    int len = 0;

    st.push(-1);
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();

            if(st.empty()){
                st.push(i);
            }
            else{
                len = max(len , i - st.top());
            }
        }
    }
    cout << len << endl;
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