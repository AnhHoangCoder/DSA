// Cho dãy số A[] gồm có N phần tử.

// Nhiệm vụ của bạn là hãy đếm số bộ ba (i, j, k) mà A[i] + A[j] + A[k] < K cho trước.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm số nguyên N và K (1≤ N ≤5000, -109 ≤ K ≤ 109).

// Dòng tiếp theo gồm N số nguyên A[i] (-109 ≤ A[i] ≤ 109).

// Output: 

// Với mỗi test, in ra trên một dòng là đáp án tìm được.

// Ví dụ:

// Input

// Output

// 2

// 4 2

// -2 0 1 3

// 5 12

// 5 1 3 4 7


// 2

// 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin() , a.end());
    
    ll cnt = 0;
    for(int i=0;i<n-2;i++){
        int left = i+1 , right = n-1;
        while(left < right){
            ll sum = a[i] + a[left] + a[right];
            if(sum < k){
                cnt += right - left;
                left++;
            }
            else{
                right--;
            }
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