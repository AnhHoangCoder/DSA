// Cho số tự nhiên N. Hãy tìm cặp số nguyên tố đầu tiên có tổng là N. Nếu không tồn tại cặp số nguyên tố có tổng bằng N, hãy đưa ra -1.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là một số N được ghi trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// Output:

// 2
// 4

// 8

// 2 2

// 3 5

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define Max 1000000

bool prime[Max+1];

void sang(){
    memset(prime , true , sizeof(prime));
    prime[0] = false , prime[1] = false;
    for(int i=2;i*i<=Max;i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = false;
            }
        }
    }
}

void testCase(){
    int n;
    cin >> n;
    for(int i=2;i<=n/2;i++){
        if(prime[i] && prime[n-i]){
            cout << i << " " << n-i << endl;
            return;
        }
    }
    cout << "-1" << endl;
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