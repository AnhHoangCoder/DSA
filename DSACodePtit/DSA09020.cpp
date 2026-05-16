// Cho đơn đồ thị vô hướng có n đỉnh dưới dạng danh sách kề.

// Hãy biểu diễn đồ thị bằng ma trận kề.

// Input: Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 ≤  n ≤  1000). n dòng tiếp theo, dòng thứ i chứa các số nguyên là các đỉnh kề với đỉnh i.  

// Output:  Ma trận kề của đồ thị.

// Ví dụ:

// Input

// Output

// 3

// 2 3

// 1 3

// 1 2

// 0 1 1

// 1 0 1

// 1 1 0

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> a(n+1 , vector<int> (n+1));
    for(int i=1;i<=n;i++){
        string s;
        getline(cin , s);
    
        stringstream ss(s);
        int v;
        
        while(ss >> v){
            a[i][v] = 1;
            a[v][i] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        testCase();
    }
    return 0;
}