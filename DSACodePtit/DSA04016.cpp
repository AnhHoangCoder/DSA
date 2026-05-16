// Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số M, N, K; dòng tiếp theo đưa vào M số của mảng A[];dòng tiếp theo đưa vào N số của mảng B[];các số được viết cách nhau một vài khoảng trống.
// T, M,N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N, A[i], B[i]≤106; 1≤ K≤N+M.
// Output:

// Đưa ra giá trị phần tử thứ K của mỗi test theo từng dòng.
//    Ví dụ:

// Input

// Output

// 1
// 5 4 5
// 2 3 6 7 9
// 1 4 8 10

// 6

#include <iostream>
#include <vector>

using namespace std;

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void testCase(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n) , b(m);
    nhap(a , n);
    nhap(b , m);
    
    int i = 0 , j = 0 , cnt = 0;
    while(i < n && j < m){
        int val;
        if(a[i] <= b[j]) val = a[i++];
        else val = b[j++];
        cnt++;
        if(cnt == k){
            cout << val << endl;
            return;
        }
    }
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