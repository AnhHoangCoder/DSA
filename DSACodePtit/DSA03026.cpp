// Cho hai số nguyên dương N và S. Hãy lựa chọn các chữ số phù hợp để tạo ra số nhỏ nhất và số lớn nhất có N chữ số sao cho tổng chữ số đúng bằng S.

// Input

// Chỉ có một dòng ghi hai số N và S. (0 < N <= 100; 0 <= S <= 900)

// Output

// Ghi ra hai số nhỏ nhất và lớn nhất tìm được, cách nhau một khoảng trống.

// Nếu không thể tìm được thì ghi ra “-1 -1”

// Ví dụ

// Input

// Output

// 3 20

// 299 992

// 2 900

// -1 -1

// 3 0

// -1 -1

#include <iostream>
#include <vector>

using namespace std;

string maxNum(int n , int s){
    string ans = "";

    for(int i=0;i<n;i++){
        int d = min(9 , s);
        ans += char(d + '0');
        s -= d;
    }
    return ans;
}

string minNum(int n , int s){
    string ans = "";
    for(int i=0;i<n;i++){
        for(int d = (i == 0 ? 1 : 0) ; d <= 9 ; d++){
            int remain = s - d;

            if(remain >= 0 && remain <= 9 * (n - i - 1)){
                ans += char(d + '0');
                s -= d;
                break;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , s;
    cin >> n >> s;
    if((s == 0 && n > 1) || s > 9 * n){
        cout << "-1 -1";
        return 0;
    }

    if(n == 1 && s == 0){
        cout << "0 0";
        return 0;
    }

    cout << minNum(n , s) << " " << maxNum(n , s) << endl;
    return 0;
}