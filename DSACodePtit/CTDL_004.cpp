// Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100). Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử trong dãy đó thỏa mãn tính chất tăng dần. Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số AN. Ví dụ :

// Input:  5    3

// 2    5    15   10    20  

// Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc của dãy con.
// Dòng kế tiếp : N số của dãy số AN, các số trong dãy không lớn hơn 100. 
// thì Output : 7 (số các dãy con tăng dần bậc 3 của dãy số AN)

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;
vector<int> res;
int cnt = 0;

void backTrack(int pos , int start){
    if(res.size() == k){
        cnt++;
        return;
    }
    for(int i=start;i<n;i++){
        res.push_back(a[i]);
        if(pos > 0 && a[i] <= res[pos-1]){
            res.pop_back();
            continue;
        }
        backTrack(pos+1 , i);
        res.pop_back();
    }
}

void testCase(){
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    backTrack(0 , 0);
    cout << cnt << endl;
}

int main(){
    testCase();
    return 0;
}