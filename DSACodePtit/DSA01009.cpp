// Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi siÎS thì si hoặc là kí tự A hoặc si là kí tự B . Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8. Cho số tự nhiên N và số tự nhiên K (1£K<N£15 được nhập từ bàn phím), hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.

// Dữ liệu vào chỉ có một dòng ghi hai số N và K.

// Kết quả ghi ra màn hình theo khuôn dạng:

// Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
// Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra theo thứ tự từ điển.
// Ví dụ:

// INPUT

// 5 3 

// OUTPUT

// 5

// AAABA

// AAABB

// ABAAA

// BAAAB

// BBAAA

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> a;
int cnt;
vector<string> res;

void backTrack(string s){
    if(s.size() == n){
        int dem = 0;
        for(char x : s){
            if(x == 'A'){
                dem++;
                if(dem > k){
                    break;
                }
            }
            else{
                if(dem == k){
                    break;
                }
                dem = 0;
            }
        }
        if(dem == k){
            cnt++;
            res.push_back(s);
        }
        return;
    }
    for(char c : {'A' , 'B'}){
        backTrack(s + c);
    }
}

void testCase(){
    cin >> n >> k;
    a.assign(n , 0);
    cnt = 0;
    backTrack("");
    sort(res.begin() , res.end());
    cout << cnt << endl;
    for(string &x : res){
        cout << x << endl;
    }
}

int main(){
    testCase();
    return 0;
}