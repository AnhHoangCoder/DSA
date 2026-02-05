// Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?

// Các tập hợp là hoán vị của nhau chỉ được tính là một.

// Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

// Input:  Gồm nhiều bộ test (không quá 100 test).

// Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155. Input kết thúc bởi 3 số 0.

// Output:  Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.

// Ví dụ:

// Input

// 9 3 23

// 9 3 22

// 10 3 28

// 16 10 107

// 20 8 102

// 20 10 105

// 20 10 155

// 3 4 3

// 4 2 11

// 0 0 0

// Output

// 1

// 2

// 0

// 20

// 1542

// 5448

// 1

// 0

// 0

#include <iostream>
#include <vector>

using namespace std;

int n,k,s;
int cnt;

void backTrack(int start , int pos , int sum){
    if(sum > s) return;
    if(pos == k){
        if(sum == s){
            cnt++;
        }
        return;
    }

    for(int i=start;i<=n;i++){
        int remain = k - pos - 1;

        // có số lượng phần tử bằng k nên là
        // nếu có 1 phần tử lớn hơn s thì ko cần phải đếm
        int minSum = sum + i + remain*(i+1);
        if(minSum > s) break;

        //nếu mà ch đến sum của toàn bộ từ i+1 cho đến k mà ko qua đc s thì bỏ qua
        int maxSum = sum + i + remain*n;
        if(maxSum < s) continue;

        backTrack(i + 1 , pos + 1 , sum + i);
    }
}

int main(){
    while(cin >> n >> k >> s){
        if(n == 0 && k == 0 && s == 0) break;
        cnt = 0;

        backTrack(1 , 0 , 0);
        cout << cnt << endl;
    }
    return 0;
}