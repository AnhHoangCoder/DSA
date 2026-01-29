// Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau:

// Độ dài xâu ít nhất là 6
// Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6
// Không có 2 chữ số 8 nào ở cạnh nhau
// Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.
// Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

// Input

// Chỉ có 1 dòng ghi số N (5 < N < 16).

// Output

// Ghi ra các xâu ký tự phát lộc độ dài N, mỗi xâu trên một dòng.

// Ví dụ

// Input

// 6

// Output

// 866686

// 866866

// 868666

// 868686

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

void backTrack(int pos){
    if(pos == n){
        if(a[0] == 1 && a[n-1] == 0){
            for(int i=0;i<n;i++){
                cout << (a[i] ? 8 : 6);
            }
            cout << endl;
        }
        return;
    }
    for(int i=0;i<=1;i++){
        //ko cho 88
        if(pos > 0 && i == 1 && a[pos - 1] == 1){
            continue;   
        }
        if(i == 0){
            //ko quá 3 số 6 liên tiếp
            int cnt = 1;
            for(int j=pos-1;j>=0 && a[j] == 0;j--){
                cnt++;
            }
            if(cnt > 3) continue;
        }
        a[pos] = i;
        backTrack(pos+1);
    }
}

void testCase(){
    cin >> n;
    a.assign(n, 0);
    backTrack(0);
}

int main(){
    testCase();
    return 0;
}