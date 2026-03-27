// Cho dãy số A gồm N phần tử là các số nguyên. Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.

// Input

// Dòng đầu tiên ghi số N (3 ≤ N ≤ 10000)

// Dòng thứ 2 ghi N số của dãy A (|Ai| ≤ 1000)

// Outpput

// Ghi ra kết quả trên một dòng

// Ví dụ

// Input

// Output

// 6

// 5 10 -2 3 5 2

// 250

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());

    ll res = -1e18;

    //2 số lớn nhất
    res = max(res , a[n-1] * a[n-2]);

    res = max(res , a[0] * a[1]);

    //3 số số lớn nhất
    res = max(res , a[n-1] * a[n-2] * a[n-3]);

    res = max(res , a[0] * a[1] * a[n-1]);
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        testCase();
    }
    return 0;
}