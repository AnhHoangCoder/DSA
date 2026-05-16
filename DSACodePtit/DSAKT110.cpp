// Có N ngôi nhà trên một dãy phố, mỗi ngôi nhà chứa đựng một số lượng tài sản khác nhau. Một tên trộm muốn ăp cắp được nhiều nhất tài sản của dãy phố nhưng không muốn lấy tài sản của hai nhà kề nhau. Hãy cho biết, bằng cách đó tên trộm có thể đánh cắp được nhiều nhất bao nhiêu tài sản.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N là số lượng ngôi nhà; dòng tiếp theo đưa vào N số là tài sản tương ứng trong mỗi ngôi nhà; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤106; 1≤A[i] ≤107.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

//  Input

// Output

// 2
// 6
// 5 5 10 100 10 5
// 4
// 3 2 7 10

// 110
// 13

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = a[1];
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1] , dp[i-2] + a[i]);
    }
    cout << dp[n] << endl;
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