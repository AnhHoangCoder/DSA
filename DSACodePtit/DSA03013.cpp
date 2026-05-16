// Cho xâu ký tự S bao gồm các ký tự và số D. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để tất cả các ký tự giống nhau đều có khoảng cách là D hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số D; dòng tiếp theo là xâu S.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤D≤100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 2

// ABB
// 2
// AAA

// 1
// -1

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Words{
    char word;
    int cnt;
};

void testCase(){
    int d;
    string s;
    cin >> d >> s;
    int n = s.size();

    map<char , int> mp;
    for(char c : s){
        mp[c]++;
    }

    Words a[26];
    int idx = 0;
    for(auto x : mp){
        a[idx].word = x.first;
        a[idx].cnt = x.second;
        idx++;
    }
    
    for(int i=0;i<idx;i++){
        int p = a[i].cnt;
        for(int j=0;j<p;j++){
            if(i + (j * d) > n){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << 1 << endl;
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