// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con của A[] có tổng các phần tử là số nguyên tố.

// Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

// Input

// Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

// Dòng đầu ghi số N (2 < N <15)
// Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
// Output

// Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số nguyên tố theo thứ tự từ điển tăng dần, mỗi dãy con trên một dòng. 

// Ví dụ

// Input

// 1

// 4

// 3 2 5 4

// Output

// 2

// 3

// 3 2

// 4 3

// 5

// 5 2

// 5 4 2

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define Max 1000000

bool primes[Max+1];

void sang(){
    memset(primes , true , sizeof(primes));
    primes[0] = false , primes[1] = false;
    for(int i=2;i*i<=Max;i++){
        if(primes[i]){
            for(int j=i*i;j<=Max;j+=i){
                primes[j] = false;
            }
        }
    }
}

int n;
vector<int> a , tmp;
vector<vector<int>> res;

void Try(int idx , int sum){
    if(primes[sum]){
        res.push_back(tmp);
    }
    for(int i=idx;i<n;i++){
        tmp.push_back(a[i]);
        Try(i+1 , sum + a[i]);
        tmp.pop_back();
    }
}

void testCase(){
    cin >> n;
    a.assign(n , 0);    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }    
    tmp.clear();
    res.clear();
    sort(a.begin() , a.end() , greater<int>());
    Try(0 , 0);
    sort(res.begin() , res.end());
    for(auto &y : res){
        for(int i=0;i<y.size();i++){
            cout << y[i];
            if(i < y.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    sang();
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}