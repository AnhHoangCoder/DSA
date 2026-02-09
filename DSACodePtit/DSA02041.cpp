// Cho số nguyên dương N. Hãy đếm số bước ít nhất để đưa N về 1 bằng cách thực hiện ba thao tác dưới đây:

// Nếu N chia hết cho 2 bạn có thể giảm N = N/2.
// Nếu N chia hết cho 3 bạn có thể giảm N = N/3.
// Giảm N đi 1.
// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

//  Input

// 2
// 10
// 6

// Output

// 3

// 2

#include <iostream>
#include <climits>

using namespace std;

int cnt;

void Try(int n , int dem){
    if(dem >= cnt) return;
    if(n == 1){
        cnt = min(cnt , dem);
        return;
    }
    if(n % 2 == 0){
        Try(n / 2 , dem + 1);
    }
    if(n % 3 == 0){
        Try(n / 3 , dem + 1);
    }
    Try(n - 1 , dem + 1);
}

void testCase(){
    int n;
    cin >> n;
    cnt = n;
    Try(n , 0);
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