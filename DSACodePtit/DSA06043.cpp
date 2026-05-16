// Cho dãy số A[] gồm có N phần tử nguyên dương. Phần tử thứ i được gọi là điểm cân bằng của dãy số nếu như tổng các số bên trái bằng tổng các số bên phải của nó.

// Nhiệm vụ của bạn là điểm cân bằng đầu tiên của dãy A[] cho trước. Nếu không có đáp án, in ra -1.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu.

// Dòng tiếp theo gồm N số nguyên A[i] (-1000 ≤ A[i] ≤ 1000).

// Output: 

// Với mỗi test, in ra trên một dòng vị trí của điểm cân bằng tìm được.

 

// Ví dụ:

// Input:

// Output

// 2

// 7

// -7 1 5 2 -4 3 0

// 5

// 1 2 3 4 5

 

// 4

// -1

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n , sumR = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i > 0) sumR += a[i];
    }    

    int ans = -1;
    int sumL = 0;
    for(int i=1;i<n-1;i++){
        sumL += a[i-1];
        sumR -= a[i];
        if(sumL == sumR){
            ans = i+1;
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