// Cho dãy số A có N phần tử và số K. Hãy đếm số cách chia dãy A thành K nhóm các phần tử liên tiếp sao cho tổng giá trị của mỗi nhóm đều bằng nhau.

// Input

// Dòng đầu ghi hai số N và K (0 < N ≤ 12; 0 < K < N ).

// Dòng thứ 2 ghi N số của dãy A (-10000 ≤ A[i] ≤ 10000)

// Output

// In ra số cách thỏa mãn

// Ví dụ

// Input

// Output

// 3 2

// -2 0 -2

// 2

// 3 2

// 1 2 3

// 1

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n,k,s;
vector<int> a;
int cnt;

void Try(int idx , int groupFound , int sum){
    if(idx == n){
        if(groupFound == k){
            cnt++;
        }
        return;
    }
    sum += a[idx];
    // Nếu gom đến cuối dãy mà sum đủ s và đây là nhóm cuối cùng
    if(idx == n-1){
        if(sum == s && groupFound == k-1){
            cnt++;
            return;
        }
    }
    // Nếu đang gom mà đủ s thì ta ngắt nhóm tại đây
    if(sum == s && groupFound < k-1){
        Try(idx+1 , groupFound+1 , 0);
    }
    Try(idx+1 , groupFound , sum);
}

void testCase(){
    cin >> n >> k;
    a.resize(n);
    s = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s += a[i];
    }
    if(s % k != 0){
        cout << 0 << endl;
        return;
    }
    cnt = 0;
    s /= k;
    Try(0 , 0 , 0);
    cout << cnt << endl;
}

int main(){
    testCase();
    return 0;
}