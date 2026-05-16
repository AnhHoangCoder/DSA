// Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra tất cả các hoán vị của xâu ký tự S. Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}. 

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.
// T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
 
// Input

// 2

// AB

// ABC

// Output

// AB BA

// ABC ACB BAC BCA CAB CBA 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;

bool sinh(){
    int i = n-2;
    while(i>=0 && a[i] > a[i+1]) i--;
    if(i < 0) return false;
    int j = n-1;
    while(a[j] < a[i]) j--;
    swap(a[i] , a[j]);
    reverse(a.begin() + i + 1 , a.end());
    return true;
}

void testCase(){
    string s;
    cin >> s;
    n = s.size();
    a.assign(n,0);
    for(int i=0;i<n;i++){
        a[i] = i;
    }
    do{
        for(int i=0;i<n;i++){
            cout << s[a[i]];
        }
        cout << " ";
    }while(sinh());
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}