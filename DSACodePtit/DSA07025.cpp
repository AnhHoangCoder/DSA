// Biểu thức dưới dạng hậu tố là phép biểu diễn biểu thức trong đó phép toán được đặt sau hai toán hạng. Ví dụ AB+CD-* (tương ứng với biểu thức trung tố (A+B)*(C-D).

// Hãy viết chương trình tính toán giá trị của biểu thức hậu tố.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test bắt đầu bởi số nguyên N (N ≤ 1000), là số lượng toán tử và toán hạng.

// Dòng tiếp theo là biểu thức hậu tố với N toán tử và toán hạng. Các toán hạng và toán tử cách nhau bởi một dấu cách.

// Các toán hạng có thể có nhiều chữ số, có thể là số âm. Phép chia thực hiện trên số nguyên. Input đảm bảo kết quả phép toán có giá trị tuyệt đối không vượt quá 10^18.

// Output: 

// Với mỗi test, in ra giá trị biểu thức tìm được.

// Ví dụ:

// Input:

// Output

// 3

// 7

// 2 3 1 * + 9 –

// 7

// 8 7 5 * + 9 –

// 3

// -10 -4 +

 

// -4

// 34

// -14

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;

ll toNum(string s){
    ll res = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            res = res * 10 + (s[i] - '0');
        }
    }
    if(s[0] == '-'){
        res *= (-1);
    }
    return res;
}

bool check(string c){
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

void testCase(){
    int n;
    cin >> n;

    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    stack<ll> st;
    for(int i=0;i<n;i++){
        if(check(s[i])){
            ll a = st.top();
            st.pop();
            
            ll b = st.top();
            st.pop();

            if(s[i] == "+") st.push(b + a);
            if(s[i] == "-") st.push(b - a);
            if(s[i] == "*") st.push(b * a);
            if(s[i] == "/") st.push(b / a);
        }
        else{
            st.push(toNum(s[i]));
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