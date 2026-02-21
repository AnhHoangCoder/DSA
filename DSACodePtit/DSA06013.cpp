// Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy tìm số lần xuất hiện số X trong mảng. Nếu số lần xuất hiện số x trong mảng là 0 hãy đưa ra -1.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N và X; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, X, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤103, 1≤A[i], X ≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// Output:

// 2
// 7 2

// 1 1 2 2 2 2 3

// 7 4

// 1 1 2 2 2 2 3

// 4

// -1

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int t : a){
        if(t == x){
            cnt++;
        }
    }
    if(cnt == 0){
        cout << "-1";
    }
    else{
        cout << cnt;
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