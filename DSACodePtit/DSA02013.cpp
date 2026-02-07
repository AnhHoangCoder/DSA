// Cho ba số N, P, S. Trong đó, P là một số nguyên tố. Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố lớn hơn P có tổng bằng S. Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.
// S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.
// Output:

// Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.
// Input

// 2
// 2  7  28
// 3  2  23

// Output

// 1

// 11 17

// 2

// 3 7 13

// 5 7 11

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define Max 500

bool primes[Max+1];
vector<int> listPrime;
int n,p,s;
vector<vector<int>> res;
vector<int> a;

void sang(){
    memset(primes , true , sizeof(primes));
    primes[0] = false , primes[1] = false;
    for(int i=2;i*i <= Max;i++){
        if(primes[i]){
            for(int j=i*i;j<=Max;j+=i){
                primes[j] = false;
            }
        }
    }
}

void backTrack(int idx , int k , int sum){
    if(k == 0){
        if(sum == s){
            res.push_back(a);
        }
        return;
    }
    for(int i=idx;i<listPrime.size();i++){
        int v = listPrime[i];
        
        if(sum + v <= s){
            a.push_back(v);
            backTrack(i + 1 , k - 1 , sum + v);
            a.pop_back();
        }
        else{
            break;
        }
    }
}

void testCase(){
    cin >> n >> p >> s;
    a.clear();
    res.clear();
    listPrime.clear();

    for(int i=p+1;i<=s;i++){
        if(primes[i]){
            listPrime.push_back(i);
        }
    }
    backTrack(0 , n , 0);
    cout << res.size() << endl;
    for(auto &x : res){
        for(int i=0;i<x.size();i++){
            cout << x[i];
            if(i < x.size()-1) cout << " ";
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