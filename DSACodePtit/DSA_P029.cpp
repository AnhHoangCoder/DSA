// Trong kì nghỉ hè năm nay Tí được bố thưởng cho 1 tour du lịch quanh N đất nước tươi đẹp với nhiều thắng cảnh nổi tiếng. Tất nhiên Tí sẽ đi bằng máy bay.

// Giá vé máy bay từ đất nước i đến đất nước j là C[i][j] (dĩ nhiên C[i][j] có thể khác C[j][i]). Tuy được bố thưởng cho nhiều tiền để đi du lịch nhưng Tí cũng muốn tìm cho mình 1 hành trình với chi phí rẻ nhất có thể để dành tiền mua quà về tặng mọi người.

// Bạn hãy giúp Tí tìm 1 hành trình đi qua tất cả các nước, mỗi nước đúng 1 lần sao cho chi phí là bé nhất nhé.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T <= 20).

// Mỗi test bắt đầu bởi số nguyên dương N (5 <= N <= 15).

// N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả chi phí C[i][j] (1<= C[i][j] <= 10000).

// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng.

 

// Ví dụ:

// Input:

// Output

// 1

// 6

// 0 1 2 1 3 4

// 5 0 3 2 3 4

// 4 1 0 2 1 2

// 4 2 5 0 4 3

// 2 5 3 5 0 2

// 5 4 3 3 1 0

 

// 8

// Giải thích test: 1 hành trình tối ưu là 3à 6 à 5 à 1 à 2 à 4.

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;

    vector<vector<int>> a(n , vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
        }
    }

    int Max = 1 << n;
    const int INF = 1e9;
    vector<vector<int>> dp(Max , vector<int>(n , INF));

    //Bắt đầu từ đỉnh ngẫu nhiên
    for(int i = 0 ; i < n ; i++){
        dp[1 << i][i] = 0;
    }

    for(int mask = 0 ; mask < Max ; mask++){
        for(int u = 0 ; u < n ; u++){
            if(mask & (1 << u)){ //u đã được thăm
                for(int v = 0 ; v < n ; v++){
                    if(!(mask & (1 << v))){ // v chưa được thăm
                        dp[mask | (1 << v)][v] = min(
                            dp[mask | (1 << v)][v],
                            dp[mask][u] + a[u][v]
                        );
                    }
                }
            }
        }
    }

    int res = INF;
    for(int i = 0; i < n; i++){
        res = min(res, dp[Max-1][i]); //mỗi điểm đi qua 1 lần và quay lại đỉnh xuất phát
    }

    cout << res << endl;
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