// Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Nam muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

// Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.

// Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.  

// Input

// Dòng đầu ghi số bộ test T (không quá 10)
// Mỗi bộ test ghi số N (3 < N < 10)
// Output

// Với mỗi bộ test, ghi ra tất cả các cách xếp thứ tự thỏa mãn, mỗi cách trên một dòng.
// Ví dụ

// Input

// 1

// 4

// Output

// 2413

// 3142

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> a;
vector<bool> used;

void backTrack(int pos){
    if(pos > n){
        for(int i = 1 ; i <= n ; i++){
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    for(int i = 1 ; i <= n ; i++){
        if(!used[i]){
            if(pos > 1 && (abs(i - a[pos-1]) == 1)) continue;
            a[pos] = i;
            used[i] = true;
            backTrack(pos + 1);
            used[i] = false;
        }
    }
}

void testCase(){
    cin >> n;
    a.assign(n+1 , 0);
    used.assign(n+1 , false);
    backTrack(1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}