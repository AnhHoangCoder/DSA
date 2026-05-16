// Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Tổng số tiền cần đổi có giá trị bằng N.  Hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 50).  Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

// Output:  Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input:

// Output

// 2

// 70

// 121

 

// 2

// 3

#include <iostream>
#include <vector>

using namespace std;

void greedy(vector<int> &coins , vector<int> &count , int n , int l){
    for(int i=l-1;i>=0;i--){
        while(coins[i] <= n){
            n -= coins[i];
            count[i]++;
        }
    }
}

void testCase(){
    int n;
    cin >> n;

    vector<int> coins = {1 , 2 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 1000};
    int l = coins.size();
    
    vector<int> count(10 , 0);
    greedy(coins , count , n , l);
    int cnt = 0;
    for(int x : count){
        if(x > 0) cnt += x;
    }
    cout << cnt << endl;
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