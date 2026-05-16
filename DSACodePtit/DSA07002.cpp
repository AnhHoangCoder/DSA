// Yêu cầu bạn xây dựng một stack với các truy vấn sau đây:

// “PUSH x”: Thêm phần tử x vào stack (0 ≤ x ≤ 1000).

// “PRINT”: In ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.

// “POP”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.

// Input:

// Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).

// Mỗi truy vấn có dạng như trên.

// Output: 

// Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.

// Ví dụ:

// Input:

// Output

// 9

// PUSH 1

// PUSH 2

// POP

// PRINT

// PUSH 3

// PRINT

// POP

// POP

// PRINT

 
// 1

// 3

// NONE

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    stack<int> st;

    string s;
    while(t--){
        cin >> s;

        if(s == "PUSH"){
            int n;
            cin >> n;
            st.push(n);
        }
        else if(s == "POP"){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(s == "PRINT"){
            if(st.empty()){
                cout << "NONE" << endl;
                continue;
            }
            int n = st.top();
            cout << n << endl;
        }
    }
    return 0;
}