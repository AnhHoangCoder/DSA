// Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
// T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input

// Output

// 2

// 5 

// 1  2  3  4  5

// 5

// 5  4  3  2  1

 

// 1 2  3  5  4

// 1 2  3  4  5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;

void sinh(){
    int i = n-2;
    while(i >= 0 && a[i] > a[i+1]) i--;
    
    if(i < 0){
        reverse(a.begin() , a.end());
        return;
    }
    int j = n-1;
    while(a[j] < a[i]) j--;
    swap(a[i] , a[j]);
    reverse(a.begin() + i + 1 , a.end());
}

void test_case(){
    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sinh();
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}