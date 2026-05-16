// Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

// Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

// Ví dụ:

// Input

// Output

// 2

// AGGTAB

// GXTXAYB

// AA

// BB

// 4

// 0

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    string a,b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> c(n+1 , vector<int> (m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }
            else{
                c[i][j] = max(c[i-1][j] , c[i][j-1]);
            }
        }
    }
    cout << c[n][m] << endl;
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