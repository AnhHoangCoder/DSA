// Cho dãy số A[] gồm N phần tử. Với mỗi A[i], bạn cần tìm phần tử bên phải đầu tiên lớn hơn nó. Nếu không tồn tại, in ra -1.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100000).

// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).

// Output: 

// Với mỗi test, in ra trên một dòng N số R[i], với R[i] là giá trị phần tử đầu tiên lớn hơn A[i].

// Ví dụ

// Input

// Output

// 3

// 4

// 4 5 2 25

// 3

// 2 2 2

// 4

// 4 4 5 5

// 5 25 25 -1

// -1 -1 -1

// 5 5 -1 -1

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n) , res(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= a[i]){
            st.pop();
        }
        
        if(st.empty()){
            res[i] = -1;
        }
        else{
            res[i] = st.top();
        }
        st.push(a[i]);
    }
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
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