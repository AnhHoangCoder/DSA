// Cho mảng A[] gồm N node là biểu diễn phép duyệt theo thứ tự trước (Preorder) của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là đưa ra phép duyệt theo thứ tự sau của cây nhị phân tìm kiếm.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng node; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
// Output:

// Đưa ra kết quả phép duyệt Postorder theo từng dòng.
// Ví dụ:

 

// Input

// Output

// 2
// 5
// 40 30 35 80 100
// 8
// 40 30 32 35 80 90 100 120

// 35 30 100 80 40
// 35 32 30 120 100 90 80 40

#include <iostream>
#include <vector>

using namespace std;

void postorder(vector<int> &pre , int l , int r){
    if(l > r) return;

    int root = pre[l];
    int mid = l + 1;

    while(mid <= r && pre[mid] < root) mid++;

    postorder(pre , l + 1 , mid - 1);

    postorder(pre , mid , r);

    cout << root << " ";
}

void testCase(){
    int n;
    cin >> n;
    vector<int> pre(n);
    for(int &x : pre){
        cin >> x;
    }

    postorder(pre , 0 , n-1);
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}