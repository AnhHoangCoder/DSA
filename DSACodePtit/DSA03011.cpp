// Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây (A[i] + A[j]) % BASE.

// Dữ liệu vào

// Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên là số nguyên N (N ≤ 2*106).

// Dòng tiếp theo gồm N số nguyên dương c[i] (1 ≤ A[i] ≤ 109).

// Kết quả 

// In ra đáp án của bộ test trên từng dòng, theo modulo BASE = 109+7.

// Ví dụ:

// Input:

// Output

// 1

// 7

// 2 4 1 2 10 2 3

// 59

#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

const ll BASE = 1e9 + 7;

void testCase(){
    int n;
    cin >> n;
    multiset<ll> st;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        st.insert(x);
    }

    ll sum = 0;
    while(st.size() > 1){
        ll a = *st.begin();
        st.erase(st.begin());

        ll b = *st.begin();
        st.erase(st.begin());

        ll c = (a + b) % BASE;
        sum = (sum + c) % BASE;

        st.insert(c);
    }

    cout << sum << endl;
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