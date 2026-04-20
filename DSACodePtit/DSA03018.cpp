// Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy

// Dữ liệu vào: Dòng đầu ghi số bộ test, mỗi bộ test có một dòng chứa số nguyên n (1 ≤ n ≤ 106) — tổng các chữ số của số may mắn cần tìm.

// Kết quả: In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n. Nếu không tồn tại số thỏa mãn, in ra -1.

// Ví dụ:

// Input

// Output

// 2

// 11

// 10

// 47

// -1

#include <iostream>

using namespace std;

void testCase(){
    int n;
    cin >> n;

    int best_i = -1 , best_j = -1;

    for(int j = 0 ;j <= n/7 ; j++){
        if((n - 7*j) % 4 == 0){
            int i = (n - 7*j) / 4;

            if(best_i = -1 || i + j < best_i + best_j || (i + j == best_i + best_j && i > best_i)){
                best_i = i;
                best_j = j;
            }
        }
    }

    if(best_i == -1){
        cout << -1 << endl;
    }
    else{
        cout << string(best_i , '4') << string(best_j , '7') << endl;
    }
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