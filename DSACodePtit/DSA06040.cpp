// Cho ba dãy số A[], B[], C[] gồm N1, N2, N3 phần tử đã được sắp xếp. Hãy đưa ra các phần tử có mặt trong cả ba dãy theo thứ tự tăng dần. Nếu không có đáp án, in ra -1.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm bốn dòng: dòng thứ nhất đưa vào N1, N2, N3 là số phần tử của mảng A[], B[], C[]; các dòng tiếp theo đưa vào 3 dãy A[], B[], C[].
// Ràng buộc: 1≤T≤100; 1≤ N1, N2, N3 ≤106, 0≤ A[i], B[j], C[k] ≤1018.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

 

// Input:

// Output:

// 1
// 6 5 8
// 1 5 10 20 40 80
// 6 7 20 80 100
// 3 4 15 20 30 70 80 120

// 20 80

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

inline void nhap(vector<ll> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

ll Max(ll a , ll b , ll c){
    ll t = max(a , b);
    return max(t , c);
}

void testCase(){
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    vector<ll> a(n1) , b(n2) , c(n3);
    
    nhap(a , n1);
    nhap(b , n2);
    nhap(c , n3);
    
    int i = 0 , j = 0 , k = 0;
    vector<ll> res;

    while(i < n1 && j < n2 && k < n3){
        ll maxNum = Max(a[i] , b[j] , c[k]);
        if(a[i] == b[j] && b[j] == c[k]){
            res.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else{
            if(a[i] < maxNum) i++;
            if(b[j] < maxNum) j++;
            if(c[k] < maxNum) k++;
        }
    }
    if(!res.empty()){
        for(ll x : res){
            cout << x << " ";
        }
    }
    else{
        cout << -1;
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