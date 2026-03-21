// Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào số lượng sợi dây N; dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤106; 0≤A[i]≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 4
// 4 3 2 6
// 5
// 4 2 7 6 9

// 29
// 62

#include <iostream>
#include <set>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    ll x;
    cin >> n;

    multiset<int> st;
    for(int i=0;i<n;i++){
        cin >> x;
        st.insert(x);
    }
    ll cp = 0;
    while(st.size() != 1){
        ll a = *st.begin();
        st.erase(st.begin());

        ll b = *st.begin();
        st.erase(st.begin());

        cp += a+b;
        st.insert(a+b);
    }
    cout << cp << endl;
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