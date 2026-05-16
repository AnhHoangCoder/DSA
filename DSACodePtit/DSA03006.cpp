// Cho mảng A[] gồm N số và thực hiện các thao tác theo nguyên tắc dưới đây:

// Ta chọn một mảng con sao cho phần tử ở giữa của mảng con cũng là phần tử ở giữa của mảng A[] (trong trường hợp N lẻ).
// Đảo ngược mảng con đã chọn trong mảng A[]. Ta được phép chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý.
// Ví dụ với mảng A[] = {1, 6, 3, 4, 5, 2, 7} ta có câu trả lời là Yes vì: ta chọn mảng con {3, 4, 5} và đảo ngược để nhận được mảng A[]={1, 6, 5, 4, 3, 2, 7}, chọn tiếp mảng con {6, 5, 4, 3, 2} và đảo ngược ta nhận được mảng A[]={1, 2, 3, 4, 5, 6, 7}. Hãy cho biết ta có thể sắp xếp được mảng A[] bằng cách thực hiện các thao tác kể trên hay không?

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N ≤50; 0≤A[i]≤1000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

 
// Input

// Output

// 2
// 7
// 1 6 3 4 5 2 7
// 7
// 1 6 3 4 5 7 2

// Yes
// No

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin() , b.end());

    for(int i=0;i<n/2;i++){
        vector<int> x = {a[i] , a[n-i-1]};
        vector<int> y = {b[i] , b[n-i-1]};

        sort(x.begin() , x.end());
        sort(y.begin() , y.end());

        if(x != y){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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