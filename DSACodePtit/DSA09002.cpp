// Cho đơn đồ thị G vô hướng liên thông được mô tả bởi danh sách kề. Hãy in ra danh sách cạnh tương ứng của G.

// Input

// Dòng đầu tiên ghi số N là số đỉnh (1<N<50)
// N dòng tiếp theo mỗi dòng ghi 1 danh sách kề lần lượt theo thứ tự từ đỉnh 1 đến đỉnh N
// Output: Ghi ra lần lượt từng cạnh của đồ thị theo thứ tự tăng dần.

// Ví dụ

// Input

// Output

// 3

// 2 3

// 1 3

// 1 2

 

// 1 2

// 1 3

// 2 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector<int> a[51];

    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;

        while(ss >> x){
            a[i].push_back(x);
        }
    }

    for(int i = 1; i <= n; i++){
        sort(a[i].begin(), a[i].end());
        for(int x : a[i]){
            if(i < x){
                cout << i << " " << x << endl;
            }
        }
    }
}