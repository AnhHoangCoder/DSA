// Cho số tự nhiên K và xâu ký tự các chữ số S.  Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321”.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
// T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input

// 3
// 4
// 1234567
// 3
// 3435335
// 2
// 1034

// Output

// 7654321
// 5543333
// 4301

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

int Max;

int num(vector<int> &a){
    int so = 0;
    for(int x : a){
        so = so * 10 + x;
    }
    return so;
}

void backTrack(int pos , int k){
    if(k == 0 || pos == n){
        Max = max(Max , num(a));
        return;
    }
    //Giúp swap ở các vị trí sau
    backTrack(pos + 1 , k);

    for(int i=pos+1;i<n;i++){
        if(a[i] > a[pos]){
            swap(a[i] , a[pos]);
            backTrack(pos+1 , k-1);
            swap(a[i] , a[pos]);
        }
    }
}

void testCase(){
    int k;
    string s;
    cin >> k >> s;
    n = s.size();
    a.assign(n , 0);
    for(int i=0;i<n;i++){
        a[i] = s[i] - '0';
    }
    Max = num(a);
    backTrack(0 , k);
    cout << Max << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}