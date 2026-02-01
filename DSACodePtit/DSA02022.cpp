// Hôm nay là ngày 22/02/2022. Một ngày đặc biệt. Chỉ có hai chữ số là 0 và 2. Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.

// Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày hợp lệ chỉ có 2 chữ số 0 và 2.

// Một số chú ý:

// Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.
// Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép. Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.
// Bài toán không có dữ liệu vào. Bạn chỉ cần liệt kê kết quả gồm tất cả các ngày tháng hợp lệ. Coi dãy ký tự ngày tháng là một xâu ký tự. Hãy liệt kê theo đúng thứ tự từ điển tăng dần.


//Đề bài lừa vl , code AC đây nhé
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> day, month, year;

void backTrack(int n, bool noZeroFirst, string cur, vector<string>& res) {
    if (cur.size() == n) {
        res.push_back(cur);
        return;
    }
    for (char c : {'0', '2'}) {
        if (noZeroFirst && cur.empty() && c == '0') continue;
        backTrack(n, noZeroFirst, cur + c, res);
    }
}

int main() {
    backTrack(2, false, "", day);
    backTrack(2, false, "", month);
    backTrack(4, true, "", year);

    vector<string> ans;

    for (string d : day)
        for (string m : month)
            for (string y : year) {
                int dd = stoi(d);
                int mm = stoi(m);
                int yy = stoi(y);

                if (dd > 0 && dd <= 31 && mm > 0 && mm <= 12 && yy >= 2000) {
                    ans.push_back(d + "/" + m + "/" + y);
                }
            }

    sort(ans.begin(), ans.end());
    for (auto &x : ans) cout << x << "\n";
}


// //Đây là code theo yêu cầu đề bài
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<string> dateDay , dateMon , dateYear;

// void backTrack(int len, vector<string> &v , bool year , string s = ""){
//     if((int)s.size() == len){
//         if(!year && s == "00") return;
//         v.push_back(s);
//         return;
//     }
//     for(char c : {'0' , '2'}){
//         if(year && s.empty() && c == '0'){
//             continue;
//         }
//         backTrack(len , v , year , s + c);
//     }
// }

// bool isPalindrome(const string &s){
//     return s == string(s.rbegin() , s.rend());
// }

// bool validDate(string &d , string &m , string &y){
//     int day = stoi(d);
//     int mon = stoi(m);
//     int year = stoi(y);
//     return (day > 0 && day <= 31 && 
//             mon > 0 && mon <= 12 &&
//             year >= 2000);
// }

// int main(){
//     backTrack(2 , dateDay , false);
//     backTrack(2 , dateMon , false);
//     backTrack(4 , dateYear , true);

//     for(string d : dateDay){
//         for(string m : dateMon){
//             for(string y : dateYear){
//                 if(!validDate(d , m , y)) continue;

//                 string plain = d + m + y;
//                 if(isPalindrome(plain)){
//                     cout << d << "/" << m << "/" << y << "\n";
//                 }
//             }
//         }
//     }

//     return 0;
// }