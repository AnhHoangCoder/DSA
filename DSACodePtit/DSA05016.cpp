// Số Ugly là các số chỉ có ước số là 2, 3, 5. Theo qui ước số 1 cũng là 1 số Ugly. Dưới đây là 11 số Ugly đầu tiên: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15. Cho số tự nhiên N, nhiệm vụ của bạn là tìm số Ugly thứ N.

// Input:  Dòng đầu tiên đưa vào số lượng bộ test T.  Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng. T, N thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ N ≤ 104.

// Output: Đưa ra kết quả mỗi test theo từng dòng.

// Ví dụ:

// Input

// Output

// 2
// 10
// 4

// 12
// 4

#include <iostream>

using namespace std;
using ll = long long;

ll ugly[10005];

void precompute(){
    ugly[0] = 1; //Lùi lại số đi 1 đơn vị
    int i2 = 0, i3 = 0, i5 = 0;

    for(int i = 1; i < 10000; i++){
        ll next2 = ugly[i2] * 2;
        ll next3 = ugly[i3] * 3;
        ll next5 = ugly[i5] * 5;

        ugly[i] = min(next2 , min(next3 , next5));

        if(ugly[i] == next2) i2++;
        if(ugly[i] == next3) i3++;
        if(ugly[i] == next5) i5++;
    }
}

void testCase(){
    int n;
    cin >> n;
    cout << ugly[n-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}