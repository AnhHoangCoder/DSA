// Cho dãy số A[] gồm có N phần tử.

// Một dãy con liên tiếp được gọi là dãy tam giác nếu như dãy đó tăng dần rồi lại giảm dần, hay tồn tại i, j, k sao cho A[i] ≤ A[i+1] ≤ … ≤ A[k] >= A[k+1] >= … >= A[j].

// Nhiệm vụ của bạn là hãy tìm dãy con liên tiếp là dãy tam giác có độ dài lớn nhất.

// Lưu ý: Dãy đơn điệu không giảm hoặc không tăng cũng là dãy tam giác.

// Ví dụ A[] = {10, 20, 30, 40} là một dãy tam giác.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm số nguyên N(1≤ N ≤ 100 000).

// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6).

// Output: 

// Với mỗi test, in ra trên một dòng là độ dài của dãy con tìm được.

 

// Ví dụ:

// Input:

// Output

// 2

// 6

// 12 4 78 90 45 23

// 8

// 20 4 1 2 3 4 2 10

// 5

// 5

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }   
    
    vector<int> inc(n,1) , dec(n,1);

    //Tính dãy ko giảm
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1]){
            inc[i] = inc[i-1] + 1;
        }
    }
    //Tính dãy ko tăng
    for(int i=n-2;i>=0;i--){
        if(a[i] > a[i+1]){
            dec[i] = dec[i+1] + 1;
        }
    }

    int ans = 1;
    for(int i=0;i<n;i++){
        ans = max(ans , inc[i] + dec[i] - 1);
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