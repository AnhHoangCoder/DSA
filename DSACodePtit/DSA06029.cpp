// Cho dãy số A[] có n phần tử là các số nguyên dương. Hãy sắp xếp dãy số theo thuật toán sắp xếp chèn. Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).

// Input

// Dòng đầu ghi số n (1 < n < 100)

// Dòng thứ 2 ghi n số của dãy A (các số đều nguyên dương và nhỏ hơn 100000)

// Output

// Ghi ra lần lượt các bước thuật toán theo thứ tự ngược (xem ví dụ mẫu để hiểu rõ hơn).

// Ví dụ

// Input

// Output

// 6

// 5 8 3 9 1 4

// Buoc 5: 1 3 4 5 8 9

// Buoc 4: 1 3 5 8 9

// Buoc 3: 3 5 8 9

// Buoc 2: 3 5 8

// Buoc 1: 5 8

// Buoc 0: 5

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

    for(int i=0;i<n;i++){
        vector<int> tmp;
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        for(int k=0;k<=i;k++){
            tmp.push_back(a[k]);
        }

        st.push(tmp);
    }

    int idx = st.size() - 1;
    while(!st.empty()){
        vector<int> res = st.top();

        cout << "Buoc " << idx << ": ";
        for(int i=0;i<res.size();i++){
            cout << res[i];
            if(i < res.size() - 1) cout << " ";
        }
        cout << "\n";

        idx--;
        st.pop();
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