// Cho dãy số A[] gồm có N phần tử.

// Nhiệm vụ của bạn là đếm xem có bao nhiêu cặp (i, j) mà A[i] + A[j] = K cho trước.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 0 ≤ K ≤ 10^9).

// Dòng tiếp theo gồm N số nguyên A[i] (-10^9 ≤ A[i] ≤ 10^9).

// Output: 

// Với mỗi test, in ra trên một dòng là đáp án thu được.

 

// Ví dụ:

// Input:

// Output

// 4

// 4 6

// 1 5 7 -1

// 5 6

// 1 5 7 -1 5

// 4 2

// 1 1 1 1

// 13 11

// 10 12 10 15 -1 7 6 5 4 2 1 1 1

// 2

// 3

// 6

// 9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void testCase(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    int l = 0 , r = n-1;

    ll cnt = 0;
    while(l < r){
        ll sum = a[l] + a[r];
        if(sum == k){
            if(a[l] == a[r]){
                ll m = r - l + 1;
                cnt += m * (m - 1) / 2; // mC2
                break;
            }

            //đếm số lượng trùng nhau của mỗi số bên trái và bên phải
            ll leftcnt = 1 , rightcnt = 1;
            while(l + 1 < r && a[l] == a[l + 1]){
                leftcnt++;
                l++;
            }
            
            while(r - 1 > l && a[r] == a[r - 1]){
                rightcnt++;
                r--;
            }
            
            cnt += leftcnt * rightcnt;
            l++;
            r--;
        }
        else if(sum < k){
            l++;
        }
        else{
            r--;
        }
    }
    cout << cnt << "\n";
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