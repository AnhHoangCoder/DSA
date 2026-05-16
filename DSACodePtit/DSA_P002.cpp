// Cho số nguyên dương N.

// Hãy liệt kê các hoán vị của N số tự nhiên đầu tiên.

// Input

// Chỉ có 1 dòng ghi số N (1 < N < 10).

// Output

// Ghi ra các hoán vị của N số tự nhiên đầu tiên theo thứ tự từ nhỏ đến lớn, bao gồm cả số thứ tự theo mẫu như trong ví dụ dưới đây.

// Ví dụ

// Input

// Output

// 3

// 1: 1 2 3

// 2: 1 3 2

// 3: 2 1 3

// 4: 2 3 1

// 5: 3 1 2

// 6: 3 2 1

//0.98s
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n;
// vector<int> a;

// bool sinh(){
//     int i = n-2;
//     while(i >= 0 && a[i] > a[i+1]) i--;
//     if(i < 0) return false;
//     int j = n-1;
//     while(a[i] > a[j]) j--;
//     swap(a[i] , a[j]);
//     reverse(a.begin()+i+1 , a.end());
//     return true;    
// }

// int main(){
//     cin >> n;
//     a.resize(n);

//     for(int i=0;i<n;i++){
//         a[i] = i+1;
//     }

//     int dem = 1;
//     do{
//         cout << dem << ": ";
//         for(int i=0;i<n;i++){
//             cout << a[i] << " ";
//         }
//         cout << endl;
//         dem++;
//     } while(sinh());
//     return 0;
// }

//1.11s
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<bool> used;
int dem;

void backTrack(int i){
    if(i > n){
        cout << dem << ": ";
        for(int u=1;u<=n;u++){
            cout << a[u] << " ";
        }
        dem++;
        cout << endl;
        return;
    }
    for(int j=1;j<=n;j++){
        if(!used[j]){
            a[i] = j;
            used[j] = true;

            backTrack(i+1);

            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    a.resize(n+1);
    used.assign(n+1 , false);
    dem = 1;
    backTrack(1);
    return 0;
}