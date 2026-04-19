// Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D? Ví dụ với S = 9, D = 2 ta có số nhỏ nhất thỏa mãn S và D là 18.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 2 số S và D được viết trên một dòng.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤ S,D≤1000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng. Nếu không có đáp án, in ra -1.
// Ví dụ:

// Input

// Output

// 2
// 9 2
// 20 3

// 18
// 299

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int s , d;
    cin >> s >> d;
    vector<int> a(d);

    if(s > 9 * d){
        cout << -1 << endl;
        return;
    }

    if(s == 0){
        if(d == 1){
            cout << 0;
        }
        else{
            cout << -1;
        }
        cout << endl;
        return;
    }

    s--;
    for(int i=d-1;i>=0;i--){
        if(s > 9){
            a[i] = 9;
            s -= 9;
        }
        else{
            a[i] = s;
            s = 0;
        }
    }
    a[0]++;
    for(int x : a){
        cout << x;
    }
    cout << endl;
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