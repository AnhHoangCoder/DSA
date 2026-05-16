// Cho tập các số A[] = (a1, a2, .., an). Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N phần tử của dãy số A[].
// T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤100; 1≤ A[i] ≤100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input

// 2
// 4
// 1 5 11 5
// 3
// 1 3 5 

// Output

// YES
// NO

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void testCase(){
    int n , sum = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 2 != 0){
        cout << "NO" << endl;
        return;
    }
    int mid = sum / 2;

    //Căng lắm thì tổng chỉ có 10^4
    bitset<100001> bs;
    //trong 2*10^5 bit đấy thì ta sẽ lưu tổng các tập con 
    bs[0] = 1;
    for(int x : a){
        //(|=) là hợp , giữ cả tổng cũ và thêm tổng mới vào
        bs |= (bs << x);
    }
    cout << (bs[mid] ? "YES" : "NO") << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}