// Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
// T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 1
// 3
// abc

// a ab abc ac b bc c

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void Try(string &s , string cur , int idx , vector<string> &res){
    for(int i=idx;i<s.length();i++){
        //cứ mỗi lần thêm cur thì ta lấy luôn
        cur.push_back(s[i]);
        res.push_back(cur);

        Try(s , cur , i + 1 , res);
        //nhánh cận để hoàn lại cho cur
        cur.pop_back();
    }
}

void testCase(){
    int n;
    string s;
    if(!(cin >> n >> s)) return;
    //sắp xếp lại để có thể in theo thứ tự từ điển
    sort(s.begin() , s.end());

    vector<string> res;
    Try(s , "" , 0 , res);
    sort(res.begin() , res.end());

    for(int i=0;i<res.size();i++){
        cout<< res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
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