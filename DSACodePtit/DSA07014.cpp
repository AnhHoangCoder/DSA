// Hãy viết chương trình tính toán giá trị của biểu thức tiền tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp. Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
// Ví dụ:

// Input

// Output

// 2

// -+8/632

// -+7*45+20

// 8

// 25

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
    for(int i=n-1;i>=0;i--){
        if(check(s[i])){
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if(s[i] == '+') st.push(a + b);
            if(s[i] == '-') st.push(a - b);
            if(s[i] == '*') st.push(a * b);
            if(s[i] == '/') st.push(a / b);
        }
        else{
            st.push(s[i] - '0');
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