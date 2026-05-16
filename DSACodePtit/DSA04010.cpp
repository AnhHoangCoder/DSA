// Cho mảng A[] gồm N số có cả các số âm và số dương. Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng. Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6} ta có kết quả là 7 tương ứng với dãy con {6, -2, -3, 1, 5}.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào hai số N tương ứng với số phần tử của mảng; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤100; -100≤A[i] ≤100.
// Output:

// Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 1
// 8
// -2 -5 6 -2 -3 1 5 -6

// 7

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int numSum(vector<int> &a , int l , int m , int r){
    int sum = 0 , leftSum = INT_MIN , rightSum = INT_MIN;

    for(int i=m;i>=l;i--){
        sum += a[i];
        if(sum > leftSum){
            leftSum = sum;
        }
    }
    sum = 0;
    for(int i=m+1;i<=r;i++){
        sum += a[i];
        if(sum > rightSum){
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int solve(vector<int> &a , int l , int r){
    if(l == r) return a[l];

    int mid = l + (r - l) / 2;
    return max(max(solve(a , l , mid) , solve(a , mid+1 , r)) , numSum(a , l , mid , r));
}

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << solve(a , 0 , n-1) << endl;
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