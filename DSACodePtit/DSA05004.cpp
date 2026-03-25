// Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N]. 

// Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]

// thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].

// Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử? 

// Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000). 

// Output: Ghi ra độ dài của dãy con tăng dài nhất.

// Ví dụ:

// Input

// Output

// 6

// 1 2 5 4 6 2

// 4

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[1001];
int a[1001];
int n;
int ans;

int solve(int i){
    if(dp[i] != -1) return dp[i];

    dp[i] = 1;
    for(int j=0;j<i;j++){
        if(a[j] < a[i]){
            dp[i] = max(dp[i] , solve(j) + 1);
        }
    }
    return dp[i];
}

void testCase(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    memset(dp , -1 , sizeof(dp));
    ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans , solve(i));
    }
    cout << ans << endl;
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