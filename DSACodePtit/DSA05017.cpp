// Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số phần tử của dãy A[]; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 0≤A[i] ≤100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 6
// 80 60 30 40 20 10
// 9
// 1 15 51 45 33 100 12 18 9

// 210
// 194

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> inc(n), dec(n);
    
    for(int i = 0; i < n; i++){
        inc[i] = a[i];
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                inc[i] = max(inc[i], inc[j] + a[i]);
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        dec[i] = a[i];
        for(int j = n-1; j > i; j--){
            if(a[j] < a[i]){
                dec[i] = max(dec[i], dec[j] + a[i]);
            }
        }
    }

    int ans = inc[0] + dec[0] - a[0];
    for(int i = 1; i < n; i++){
        ans = max(ans, inc[i] + dec[i] - a[i]);
    }
    cout << ans << "\n";
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