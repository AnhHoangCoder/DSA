// Cho dãy số A[] có n phần tử là các số nguyên dương. Hãy sắp xếp dãy số theo thuật toán sắp xếp đổi chỗ trực tiếp. Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).

// Input

// Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm 2 dòng:

// Dòng đầu ghi số n (1 < n < 100)
// Dòng thứ 2 ghi n số của dãy A (các số đều nguyên dương và nhỏ hơn 1000)
// Output

// Ghi ra lần lượt các bước thuật toán theo thứ tự ngược (xem ví dụ mẫu để hiểu rõ hơn).

// Ví dụ

// Input

// Output

// 1

// 6

// 5 8 3 9 1 4

// Buoc 5: 1 3 4 5 8 9

// Buoc 4: 1 3 4 5 9 8

// Buoc 3: 1 3 4 9 8 5

// Buoc 2: 1 3 8 9 5 4

// Buoc 1: 1 8 5 9 3 4

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    stack<vector<int>> st;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j] < a[i]){
                swap(a[i] , a[j]);
            }
        }
        st.push(a);
    }

    int idx = st.size();
    while(!st.empty()){
        vector<int> res = st.top();
        cout << "Buoc " << idx << ": ";
        for(int i=0;i<res.size();i++){
            cout << res[i];
            if(i < res.size() - 1) cout << " ";
        }
        cout << endl;
        idx--;
        st.pop();
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