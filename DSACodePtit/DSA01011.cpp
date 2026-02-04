// Hãy viết chương trình nhận vào một chuỗi (có thể khá dài) các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó (với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên). Chú ý: Các ký tự số trong dãy có thể trùng nhau.

// Ví dụ:               123 -> 132

// 279134399742 -> 279134423799  

// Cũng có trường hợp sẽ không thể có hoán vị kế tiếp. Ví dụ như khi đầu vào là chuỗi 987.  

// Dữ liệu vào: Dòng đầu tiên ghi số nguyên  t là số bộ test (1 ≤ t ≤ 1000).  Mỗi bộ test có một dòng, đầu tiên là số thứ tự bộ test, một dấu cách, sau đó là chuỗi các ký tự số, tối đa 80 phần tử.  

// Kết quả: Với mỗi bộ test hãy đưa ra một dòng gồm thứ tự bộ test, một dấu cách, tiếp theo đó là hoán vị kế tiếp hoặc chuỗi “BIGGEST” nếu không có hoán vị kế tiếp. 

// Ví dụ:

// INPUT

// 3

// 1 123

// 2 279134399742

// 3 987

// Output

// 1 132

// 2 279134423799

// 3 BIGGEST

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
bool check;

void sinh(){
    int i = n-2;
    while(i >= 0 && a[i] >= a[i+1]) i--;
    if(i < 0){
        check = true;
        return;
    }
    int j = n-1;
    while(a[j] <= a[i]) j--;
    swap(a[i] , a[j]);
    reverse(a.begin() + i + 1 , a.end());
}

void testCase(){
    int tt;
    string s;
    cin >> tt >> s;
    n = s.size();
    a.assign(n , 0);
    for(int i=0;i<n;i++){
        a[i] = s[i] - '0';
    }
    check = false;
    sinh();
    if(check){
        cout << tt << " " << "BIGGEST" << endl;
        return;
    }
    cout << tt << " ";
    for(int x : a){
        cout << x;
    }
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