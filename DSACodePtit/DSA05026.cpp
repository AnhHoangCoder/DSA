// John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

// Input:

// Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách
// Dòng 2..N+1:   Ghi lần lượt các số nguyên: w[i]
// Output:

// Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.
// Ví dụ:

// Input

// Output

// 259 5

// 81

// 58

// 42

// 33

// 61

 

// 242

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int c , n;
    cin >> c >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<bool> dp(c + 1 , false);
    dp[0] = true;

    for(int i=0;i<n;i++){
        for(int j=c;j>=a[i];j--){
            if(dp[j - a[i]]){
                dp[j] = true;
            }
        }
    }

    for(int i=c;i>=0;i--){
        if(dp[i]){
            cout << i << " ";
            break;
        }
    }
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