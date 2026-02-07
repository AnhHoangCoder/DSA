// Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận không nhất thiết phải khác nhau và đều không quá 100, K không quá 104). Hãy viết chương trình lấy mỗi hàng, mỗi cột duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.

// Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C. 

// Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn. 

// Ví dụ:

// INPUT

// 3 10

// 2 4 3

// 1 3 6

// 4 2 4

// OUTPUT

// 2

// 1 3 2

// 3 2 1

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<vector<int>> a;
vector<vector<int>> res;
vector<bool> used;
vector<int> num;

void backTrack(int pos , int sum){
    if(pos == n){
        if(sum == k){
            res.push_back(num);
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            num.push_back(i+1);
            used[i] = true;
            backTrack(pos + 1 , sum + a[pos][i]);
            used[i] = false;
            num.pop_back();          
        }
    }
}

void testCase(){
    cin >> n >> k;
    a.assign(n , vector<int> (n));
    used.assign(n , false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    backTrack(0 , 0);
    cout << res.size() << endl;
    for(auto &x : res){
        for(int y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}

int main(){
    testCase();
    return 0;
}