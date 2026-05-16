// Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau. Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và K; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, K, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N, K≤20, 0≤A[i]≤100.
// Output:

// Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0.
// Input

// 2
// 5 3
// 2 1 4 5 6
// 5 3
// 2 1 5 5 6

// Output

// 1
// 0

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;
bool isOk;
int s;

void Try(int sum , int count){
    if(isOk) return;
    if(count == k){
        isOk = true;
        return;
    }
    for(int i=0;i<n;i++){
        if(sum == s){
            Try(0 , count+1);
        }
        else if(sum < s){
            Try(sum + a[i] , count);
        }
        else return;
    }
}

void testCase(){
    cin >> n >> k;
    a.assign(n , 0);
    s = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s += a[i];
    }
    //vì là có k tập con bằng nhau nên phải chia hết cho k
    if(s % k != 0){
        cout << 0 << endl;
        return;
    }
    // s cuối cùng sẽ là điều kiện giới hạn
    s /= k;
    Try(0 , 0);
    if(isOk){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
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