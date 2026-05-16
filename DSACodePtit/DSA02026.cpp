// Cho một biểu thức trong phạm vi hai chữ số với các phép toán cộng trừ nhân chia. Các toán hạng và kết quả đảm bảo là số nguyên dương có hai chữ số, nếu có phép chia thì phải thỏa mãn tính chia hết.

// Người ta có thể ẩn đi một số chữ số hoặc phép toán bằng cách điền dấu chấm hỏi (?). Nhiệm vụ của bạn là khôi phục các dấu chấm hỏi và in ra phép toán chính xác ban đầu. Nếu không thể có kết quả đúng thì ghi ra WRONG PROBLEM!

// Dữ liệu vào

// Dòng đầu ghi số bộ test T (1 ≤ T ≤ 100).

// T dòng tiếp theo, mỗi dòng là một biểu thức có thể có các dấu ?.

// Nếu có thể có nhiều kết quả đúng thì in ra kết quả đầu tiên theo thứ tự từ điển, tức là số nhỏ nhất có thể tính từ trái sang phải.

// Kết quả

// Với mỗi bộ test, ghi ra biểu thức đúng tìm được. Hoặc WRONG PROBLEM!

// Ví dụ

// Input

// 2
// ?0 ? 12 = 28
// 40 / ?3 = ??

// Output

// 40 - 12 = 28

// WRONG PROBLEM!

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
vector<char> sign = {'+' , '-'};
bool isOk;

bool isCorrect(){
    int x = stoi(str.substr(0 , 2));
    int y = stoi(str.substr(5 , 2));
    int z = stoi(str.substr(10 , 2));
    if(x < 10 || y < 10 || z < 10){
        return false;
    }
    if(str[3] == '+'){
        return (x + y == z);
    }
    else{
        return (x - y == z);
    }
}

void backTrack(int pos){
    if(isOk) return;
    if(pos == str.size()){
        if(isCorrect()){
            isOk = true;
            cout << str << endl;
        }
        return;
    }
    if(str[pos] == '?'){
        if(pos == 3){
            for(int i=0;i<2;i++){
                str[pos] = sign[i];
                backTrack(pos + 1);
            }
        }
        else{
            for(int i=0;i<10;i++){
                str[pos] = i + '0';
                backTrack(pos + 1);
            }
        }
        str[pos] = '?';
    }
    else{
        backTrack(pos + 1);
    }
}

void testCase(){
    isOk = false;
    getline(cin , str);
    for(int i=0;i<str.size();i++){
        if(str[i] == '*' || str[i] == '/'){
            //ko tồn tại 2 chữ số cùng số phần tử mà * or / ko làm thay đổi phần tử
            cout << "WRONG PROBLEM!" << endl;
            return;
        }
    }

    backTrack(0);
    if(!isOk){
        cout << "WRONG PROBLEM!" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        testCase();
    }
    return 0;
}