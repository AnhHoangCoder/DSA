// Cho hai xâu nhị phân biểu diễn hai số. Nhiệm vụ của bạn là đưa ra tích của hai số. Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 hai xâu nhị phân S1, S2 được viết trên một dòng.
// T, S1, S2 thỏa mãn ràng buộc: 1≤T≤100;  1≤ length(S1), length(S2)≤30.
//     Output:

// Đưa ra tích của mỗi test theo từng dòng.
//      Ví dụ:

// Input

// Output

// 2
// 1100 01
// 01 01

// 12

// 1

#include <iostream>

using namespace std;
using ll = long long;

ll to10(string s){
    ll res = 0;
    ll p = 1;
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        res += (s[i] - '0') * p;
        p *= 2;
    }
    return res;
}

void testCase(){
    string s1 , s2;
    cin >> s1 >> s2;
    ll num1 = to10(s1) , num2 = to10(s2);
    ll res = num1 * num2;
    cout << res << endl;
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