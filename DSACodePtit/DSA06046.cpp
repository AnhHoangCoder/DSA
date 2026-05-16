// Cho dãy số A[] gồm có N phần tử. Bạn cần tìm chênh lệch nhỏ nhất giữa hai phần tử bất kì trong dãy số đã cho.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).

// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

// Output: 

// Với mỗi test, in ra trên một dòng là đáp án tìm được.

 

// Ví dụ:

// Input:

// Output

// 3

// 6

// 1 5 3 19 18 25

// 4

// 30 5 20 9

// 7

// 1 19 2 31 38 25 100

// 1

// 4

// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    int ans = a[1] - a[0];
    for(int i=2;i<n;i++){
        ans = min(ans , a[i] - a[i-1]);
        if(ans == 0){
            break;
        }
    }
    cout << ans << endl;
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