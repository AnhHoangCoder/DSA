// Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau. Các phần tử của mảng A[] và B[] chưa được sắp xếp. Hãy tìm mảng hợp và giao được sắp giữa A[] và B[]. Ví dụ với A[] = {7, 1, 5, 2, 3, 6}, B[]={3, 8, 6, 20, 7} ta có mảng hợp Union = {1, 2, 3, 5, 6, 7, 8, 20}, mảng giao Intersection = {3, 6}.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m là số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A [i] của mảng A [];dòng tiếp theo là m số B[i] của mảng B[]; các số được viết cách nhau một vài khoảng trống.
// T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m, A[i], B[i] ≤105.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// 1
// 6 5
// 7 1 5 2 3 6
// 3 8 6 20 7

// Output;

// 1 2 3 5 6 7 8 20

// 2 6

#include <iostream>
#include <map>

using namespace std;

void testCase(){
    int n,m;
    cin >> n >> m;
    map<int , int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto x : mp){
        cout << x.first << " ";
    }
    cout << "\n";
    for(auto x : mp){
        if(x.second >= 2){
            cout << x.first << " ";
        }
    }
    cout << "\n";
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