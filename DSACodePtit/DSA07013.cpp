// Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức hậu tố exp. Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
// Ví dụ:

// Input

// Output

// 2

// 231*+9-

// 875*+9-

// -4

// 34

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
    stack<int> st;
    for(char c : s){
        if(check(c)){
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if(c == '+') st.push(b + a);
            if(c == '-') st.push(b - a);
            if(c == '*') st.push(b * a);
            if(c == '/') st.push(b / a);
        }
        else{
            st.push(c - '0');
        }
    }
    cout << st.top() << endl;
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