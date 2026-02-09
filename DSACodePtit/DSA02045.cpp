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

using namespace std;

int n;
vector<char> a , tmp;
vector<vector<char>> res;

void Try(int idx , int start){
    if(!tmp.empty()){
        res.push_back(tmp);
    }
    if(idx == n) return;
    for(int i=start;i<n;i++){
        tmp.push_back(a[i]);
        Try(idx+1 , i+1);
        tmp.pop_back();
    }
}

void testCase(){
    string s;
    cin >> n >> s;
    a.clear();
    a.resize(n);
    tmp.clear();
    res.clear();
    for(int i=0;i<n;i++){
        a[i] = s[i];
    }
    Try(0 , 0);
    sort(res.begin() , res.end());
    for(auto &x : res){
        for(int i=0;i<x.size();i++){
            cout << x[i];
        }
        cout << " ";
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