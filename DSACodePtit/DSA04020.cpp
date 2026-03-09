// Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

// Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 106).

// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 106), các phần tử là riêng biệt.

// Output: 

// Với mỗi test in ra trên một dòng đáp án tìm được.

// Ví dụ:

// Input:

// Output

// 2

// 5 3

// 1 2 3 4 5

// 6 5

// 0 1 2 3 9 10

// 3

// NO

#include <iostream>
#include <vector>

using namespace std;

int k;
int ans;

void solve(vector<int> &a , int l , int r){
    if(l >= r) return;

    int mid = l + (r - l) / 2;

    if(a[mid] == k){
        ans = mid;
        return;
    }
    else if(a[mid] > k){
        solve(a , l , mid);
    }
    else{
        solve(a , mid+1 , r);
    }
}

void testCase(){
    int n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ans = -1;
    solve(a , 0 , n-1);
    if(ans != -1){
        cout << ans+1;
    }
    else{
        cout << "NO";
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