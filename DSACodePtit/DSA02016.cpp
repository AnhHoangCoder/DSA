// Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể di chuyển theo chiều ngang, dọc, chéo. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.

// Input: Dòng đầu ghi số bộ test T (T<5). Mỗi bộ test ghi một số nguyên dương n duy nhất (không quá 10)

// Output:  Ghi kết quả mỗi bộ test trên một dòng. Số cách đặt quân hậu.

// Ví dụ:

// Input

// 1

// 4

// Output

// 2

#include <iostream>
#include <vector>

using namespace std;

int n , cnt;
vector<bool> used_col;
vector<bool> used_main;
vector<bool> used_sub;

void backTrack(int row){
    if(row > n){
        cnt++;
        return;
    }
    for(int col = 1 ; col <= n ; col++){
        if(!used_col[col] && !used_sub[row - col + n] && !used_main[col + row]){
            used_col[col] = true;
            used_main[col + row] = true;
            used_sub[row - col + n] = true;

            backTrack(row + 1);

            used_col[col] = false;
            used_main[row + col] = false;
            used_sub[row - col + n] = false;
        }
    }
}

void testCase(){
    cin >> n;
    cnt = 0;
    used_col.assign(n+1 , false);
    used_main.assign(2*n+1 , false);
    used_sub.assign(2*n+1 , false);

    backTrack(1);
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}