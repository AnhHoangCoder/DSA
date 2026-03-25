// Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để hai ký tự giống nhau đều không kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
// T, S thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 3
// geeksforgeeks
// bbbabaaacd
// bbbbb

// 1
// 1

// -1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26);

    for(char c : s){
        freq[c-'a']++;
    }

    int mx = 0;
    for(int x : freq){
        mx = max(mx , x);
    }
    if(mx <= (n+1)/2) cout << 1;
    else cout << -1;
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