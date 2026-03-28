// Cho dãy số A[], B[] và C[] là dãy không giảm và có lần lượt N, M, K phần tử. Nhiệm vụ của bạn là hãy tìm các phần tử chung của 3 dãy số này.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm số nguyên N, M và K (1≤ N, M, K ≤ 100 000).

// Dòng tiếp theo gồm N số nguyên A[i], rồi M số nguyên B[i] và K số nguyên C[i].

// (0 ≤ A[i], B[i], C[i] ≤ 10^9).

// Output: 

// Với mỗi test, in ra trên một dòng là đáp án thu được. Nếu không tìm được đáp án, in ra “NO”.

 

// Ví dụ:

// Input:

// Output

// 3

// 6 5 8

// 1 5 10 20 40 80

// 5 7 20 80 100

// 3 4 15 20 30 70 80 120

// 3 5 4

// 1 5 5

// 3 4 5 5 10

// 5 5 10 20

// 3 3 3

// 1 2 3

// 4 5 6

// 7 8 9

// 20 80

// 5 5

// NO

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
    vector<int> a(n) , b(m) , c(k);

    nhap(a , n);
    nhap(b , m);
    nhap(c , k);

    vector<int> res;
    int i = 0 , j = 0 , u = 0 , tmp = 0;
    while(i < n && j < m && u < k){
        tmp = max(a[i] , max(b[j] , c[u]));
        if(a[i] == b[j] && b[j] == c[u]){
            res.push_back(a[i]);
            i++; j++; u++;
            continue;
        }

        while(i < n && a[i] < tmp) i++;
        while(j < m && b[j] < tmp) j++;
        while(u < k && c[u] < tmp) u++;
    }
    if(res.empty()){
        cout << "NO" << endl;
        return;
    }
    for(int x : res){
        cout << x << " ";
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