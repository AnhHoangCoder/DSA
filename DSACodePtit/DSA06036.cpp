// Cho dãy số A[] gồm có N phần tử.

// Nhiệm vụ của bạn là hãy kiểm tra tồn tại bộ ba (i, j, k) mà A[i] + A[j] + A[k] = K cho trước hay không.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm số nguyên N và K (1≤ N ≤5000, 0 ≤ K ≤ 10^9).

// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

// Output: 

// Với mỗi test, in ra trên một dòng là “YES” nếu tìm được bộ ba thỏa mãn, “NO” trong trường hợp ngược lại.

 

// Ví dụ:

// Input:

// Output

// 2

// 6 22

// 1 4 15 6 10 8

// 3 4

// 1 1 1

 

// YES

// NO

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin() , a.end());
    bool isOk = false;
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;

        while(j < k){
            ll sum = a[i] + a[j] + a[k];
            if(sum == x){
                isOk = true;
                break;
            }
            else if(sum < x){
                j++;
            }
            else{
                k--;
            }
        }
        if(isOk) break;
    }
    cout << (isOk ? "YES" : "NO") << endl;
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