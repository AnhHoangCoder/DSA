// Ma trận kề A của một đồ thị vô hướng là một ma trận chỉ có các số 0 hoặc 1 trong đó A[i][j] = 1 có ý nghĩa là đỉnh i kề với đỉnh j (chỉ số tính từ 1).

// Danh sách kề thì liệt kê các đỉnh kề với đỉnh đó theo thứ tự tăng dần.

// Hãy chuyển biểu diễn đồ thị từ dạng ma trận kề sang dạng danh sách kề.

// Input: Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 < n ≤ 1000). n dòng tiếp theo, mỗi dòng có n số nguyên có giá trị 0 và 1 mô tả ma trận kề của đồ thị.

// Output:  Gồm n dòng, dòng thứ i chứa các số nguyên là đỉnh có nối với đỉnh i và được sắp xếp tăng dần. Dữ liệu đảm bảo mỗi đỉnh có kết nối với ít nhất 1 đỉnh khác.

// Ví dụ:

// Input

// Output

// 3

// 0 1 1

// 1 0 1

// 1 1 0

// 2 3

// 1 3

// 1 2

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    vector<int> a[n+1];
    vector<vector<int>> b(n+1 , vector<int> (n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> b[i][j];
            if(b[i][j] == 1){
                a[i].push_back(j);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int x : a[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}