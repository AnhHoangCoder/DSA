// Cho biểu thức P chỉ chứa các ký tự ‘(’, ‘)’ và các ký tự. Không có phép toán nào trong biểu thức P. Nhiệm vụ của bạn là thực hiện ít nhất các phép loại bỏ các ký tự ‘(’, ‘)’ để P trở thành biểu thức đúng. Chú ý: một biểu thức chỉ có 1 ký tự chữ (không có dấu ngoặc) hoặc một biểu thức rỗng thì không được xem là biểu thức đúng.

// Nếu có nhiều hơn một biểu thức đúng với cùng số phép loại bỏ ít nhất hãy đưa ra tất cả các biểu thức đúng theo thứ tự từ điển.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng.
// T, P thỏa mãn ràng buộc: 1≤T ≤100; 1≤length(P)≤100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng. Nếu không có đáp án, in ra -1.
// Input

// 2
// ()())()
// (u)())()

// Output

// (())() ()()()

// (u())() (u)()() 

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int max_len;
set<string> mp;

bool isValid(string s){
    if(s.length() < 2) return false;
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(1);
        }
        else if(s[i] == ')'){
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

void Try(string s , int start){
    if(s.length() < max_len){
        return;
    }
    //Luôn lấy chuỗi lớn nhất có thể
    if(isValid(s)){
        if(s.length() > max_len){
            max_len = s.length();
            mp.clear();
        }
        mp.insert(s);
    }
    for(int i=start;i<s.length();i++){
        if(s[i] == '(' || s[i] == ')'){
            string tmp = s;
            tmp.erase(i , 1);
            Try(tmp , i);
        }
    }
}

void testCase(){
    string s;
    cin >> s;
    max_len = 0;
    mp.clear();
    Try(s , 0);
    if(mp.empty()){
        cout << "-1" << endl;
        return;
    }
    for(string x : mp){
        cout << x << " ";
    }
    cout << endl;
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