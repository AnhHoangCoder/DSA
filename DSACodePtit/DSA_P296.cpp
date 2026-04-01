// Cho dãy số A[] có N phần tử là các số nguyên, chỉ số tính từ 1.

// Với mỗi cặp vị trí L và R, hãy in ra tổng lớn nhất có thể của dãy con nào đó trong đoạn từ vị trí L đến vị trí R. Chú ý: tính cả dãy con rỗng (không có phần tử nào).

// Input

// Dòng đầu ghi 2 số N và Q (không quá 100.000).

// Dòng tiếp theo ghi N số của dãy A[], các số có trị tuyệt đối không quá 100.000.

// Q dòng tiếp theo, mỗi dòng ghi một cặp số L, R (1 ≤ L ≤ R ≤ N).

// Output

// Ghi ra Q dòng, lần lượt là tổng lớn nhất tính được với mỗi cặp (L, R) tương ứng.

// Ví dụ

// Input

// Output

// 5 2

// -1 2 -3 4 -5

// 2 4

// 3 3

 

// 6

// 0

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<ll> presum(n+1);
    presum[0] = 0;

    for(int i=0;i<n;i++){
        if(a[i] < 0){
            presum[i+1] = presum[i];
        }
        else{
            presum[i+1] = presum[i] + a[i];
        }
    }
    int l , r;
    while(q--){
        cin >> l >> r;
        cout << presum[r] - presum[l-1] << endl;
    }
    return 0;
}