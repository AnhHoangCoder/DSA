// Cho một mảng A[] gồm N phần tử. Nhiệm vụ của bạn là đưa ra 1 nếu mảng A[] biểu diễn phép duyệt inorder của cây nhị phân tìm kiếm, ngược lại đưa ra 0.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 3
// 5
// 10 20 30 40 50
// 6
// 90 80 100 70 40 30
// 3
// 1 1 2

// 1
// 0
// 0

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        if(a[i] >= a[i+1]){
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;
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