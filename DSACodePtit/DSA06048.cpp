// Ban đầu dãy số A[] gồm N phần tử đã được sắp xếp tăng dần. Các phần tử của dãy A[] có thể giống nhau. Sau đó ta thực hiện quay vòng phải, mỗi lần lấy một ký tự ở cuối dãy đưa lên đầu dãy.

// Cho trạng thái dãy số của A[] sau khi đã thực hiện quay vòng K lần. Hãy tìm K.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số M, N, K; dòng tiếp theo đưa vào N số của mảng A[]các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 0≤ A[i]≤1018.
// Output:

// Đưa ra số lần quay vòng K của mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 5
// 5 1 2 3 4
// 5
// 1 2 3 4 5

// 1
// 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> b;

bool sinh(){
    int tmp = b[n-1];
    for(int i=n-1;i>0;i--){
        b[i] = b[i-1];
    }
    b[0] = tmp;
    return true;
}

void testCase(){
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    b.assign(n , 0);
    b = a;
    sort(b.begin() , b.end());

    int cnt = 0;
    do{
        if(a == b){
            break;
        }
        cnt++;
    }while(sinh());
    cout << cnt << endl;
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