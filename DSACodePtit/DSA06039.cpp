// Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là hãy tìm số xuất hiện nhiều hơn 1 lần trong dãy số và số thứ tự là nhỏ nhất.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu.

// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

// Output: 

// Với mỗi test in ra đáp án của bài toán trên một dòng. Nếu không tìm được đáp án, in ra “NO”.

// Ví dụ:

// Input:

// Output

// 2

// 7

// 10 5 3 4 3 5 6

// 4

// 1 2 3 4

// 5

// NO

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);

    unordered_map<int,int> um;
    for(int i=0;i<n;i++){
        cin >> a[i];
        um[a[i]]++;
    }
    bool isOk = false;
    for(int i=0;i<n;i++){
        if(um[a[i]] > 1){
            isOk = true;
            cout << a[i] << endl;
            return;
        }
    }
    cout << "NO" << endl;   
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