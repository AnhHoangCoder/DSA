// Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.  Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

// Input: Có một dòng chứa hai số nguyên dương A và B ( 1 ≤ A, B ≤ 1 000 000).

// Output: In ra 2 số nguyên cách nhau một dấu cách, tổng nhỏ nhất và lớn nhất có thể nhận được.

// Ví dụ:

// Test 1

// Test 2

// Test 3

// Input:
// 11 25

// Ouput:
// 36 37

// Input:
// 1430 4862

// Ouput:
// 6282 6292

// Input:
// 16796 58786

// Ouput:
// 74580 85582

#include <iostream>

using namespace std;

string minNum(string s){
    for(char &c : s){
        if(c == '6') c = '5';
    }
    return s;
}

string maxNum(string s){
    for(char &c : s){
        if(c == '5') c = '6';
    }
    return s;
}

int stringToNum(string s){
    int res = 0;
    for(char c : s){
        res = res * 10 + (c - '0');
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin >> a >> b;

    int Min = stringToNum(minNum(a)) + stringToNum(minNum(b));
    int Max = stringToNum(maxNum(a)) + stringToNum(maxNum(b));

    cout << Min << " " << Max << endl;
    return 0;
}