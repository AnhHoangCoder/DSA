// Cho dãy số a[] có n phần tử, đánh số từ 1 đến n. Hãy sắp xếp các phần tử ở vị trí lẻ theo thứ tự tăng dần, các phần tử ở vị trí chẵn theo thứ tự giảm dần.

// Input

// Dòng đầu tiên ghi số n, không quá 105

// Dòng thứ 2 ghi n số của dãy a[] (a ≤ a[i] ≤ 109)

// Output

// Ghi ra dãy số kết quả trên một dòng

// Ví dụ

// Input

// Output

// 4

// 1 2 3 4

// 1 4 3 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<int> chan , le;
    for(int i=1;i<=n;i++){
        if(i % 2 == 1){
            le.push_back(a[i]);
        }
        else{
            chan.push_back(a[i]);
        }
    }

    sort(le.begin() , le.end());
    sort(chan.begin() , chan.end() , greater<int>());

    int j1 = 0 , j2 = 0;
    for(int i=1;i<=n;i++){
        if(i % 2 == 1){
            a[i] = le[j1++];
        }
        else{
            a[i] = chan[j2++];
        }
    }

    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }

    cout << endl;
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