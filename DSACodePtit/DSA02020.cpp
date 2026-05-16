// Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số K nhỏ nhất, sao cho K có đúng N ước. Input đảm bảo rằng đáp án không vượt quá 1018.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤  20).

// Mỗi test gồm 1 số nguyên N ( 1 ≤  N ≤  1000).

// Output:  Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input

// 2

// 4

// 6

// Output

// 6

// 12

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

#define Max 1000

using namespace std;
using ll = long long;


int n;
vector<int> a;
ll k;

bool primes[Max+1];

void sang(){
    memset(primes, true , sizeof(primes));
    primes[0] = false , primes[1] = false;
    for(int i=2;i*i<=Max;i++){
        if(primes[i]){
            for(int j=i*i;j<=Max;j+=i){
                primes[j] = false;
            }
        }
    }   
}

ll Mu(int x , int y){
    ll sum = 1;
    while(y--){
        sum *= (ll)x;
    }
    return sum;
}

void Try(int idx , int end , ll res , int count){
    if(count == n){
        k = min(k , res);
        return;
    }
    if(idx >= a.size()) return;
    for(int i=1;i<=end;i++){
        if(count * (i + 1) > n) break;
        ll p = Mu(a[idx] , i);

        if(res * p > k) break;
        Try(idx + 1 , i , res * p , count * (i + 1));
    }
}

void testCase(){
    cin >> n;
    k = LLONG_MAX;
    a.clear();
    for(int i=2;i<=Max;i++){
        if(primes[i]){
            a.push_back(i);
        }
    }
    // 2^10 = 1024 suy ra 2^60 xấp xỉ 10^18
    // Nên là số mũ lớn nhất có thể là 60
    Try(0 , 60 , 1 , 1);
    cout << k << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}