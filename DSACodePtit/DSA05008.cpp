// Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

// Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

// Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

// Ví dụ:

// Input

// Output

// 2

// 5 6
// 1 2 4 3 5

// 10 15

// 2 2 2 2 2 2 2 2 2 2

// YES

// NO

#include <iostream>
#include <vector>

using namespace std;

#define Max 40000

void testCase(){
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    vector<bool> l(Max+1);
    for(int i=0;i<=s;i++){
        l[i] = false;
    }
    l[0] = true;

    for(int i=0;i<n;i++){
        for(int j=s;j>=a[i];j--){
            if(!l[j] && l[j - a[i]]){
                l[j] = true;
            }
        }
    }
    cout << (l[s] ? "YES" : "NO") << endl;
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