// Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.

// Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.

// Output:  Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input

// 1

// 1 2 3 4 5 6 7 8

// 9 10 11 12 13 14 15 16

// 17 18 19 20 21 22 23 24

// 25 26 27 28 29 30 31 32

// 33 34 35 36 37 38 39 40

// 41 42 43 44 45 46 47 48

// 48 50 51 52 53 54 55 56

// 57 58 59 60 61 62 63 64

// Output 

// 260

#include <iostream>
#include <vector>

using namespace std;

int n , Max;
vector<vector<int>> a;
vector<bool> usedCol , usedMain , usedSub;

void backTrack(int row , int sum){
    if(row > n){
        Max = max(Max , sum);
        return;
    }
    for(int col = 1 ; col <= n ; col++){
        if(!usedCol[col] && !usedMain[row+col] && !usedSub[row-col+n]){
            usedCol[col] = true;
            usedMain[row+col] = true;
            usedSub[row-col+n] = true;

            backTrack(row+1 , sum + a[row][col]);

            usedCol[col] = false;
            usedMain[row+col] = false;
            usedSub[row-col+n] = false;
        }
    }
}

void testCase(){
    n = 8;
    a.assign(n+1 , vector<int> (n+1));
    usedCol.assign(n+1 , false);
    usedMain.assign(2*n+1 , false);
    usedSub.assign(2*n+1 , false);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    Max = 0;
    backTrack(1 , 0);
    cout << Max << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}