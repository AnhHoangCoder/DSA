// Cho xâu ký tự S. Nhiệm vụ của bạn là đảo ngược các từ trong S. Ví dụ S =  “I like this program very much”, ta nhận được kết quả là “much very program this like I”.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
// T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input:

// Output:

// 2
// I like this program very much
// much very program this like I

// much very program this like I
// I like this program very much

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void testCase(){
    string s;
    getline(cin , s);
    stringstream ss(s);
    string tmp;

    stack<string> st;
    while(ss >> tmp){
        st.push(tmp);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
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