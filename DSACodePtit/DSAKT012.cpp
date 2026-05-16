// Có n tờ tiền có giá trị t[1], t[2], …, t[n].

// Hãy tìm cách trả ít tờ tiền nhất với số tiền đúng bằng S

// Chú ý: Các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần.

// Input

// Mỗi bộ test gồm 2 số nguyên n và S (n ≤ 30; S  ≤  109).

// Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

// Output: 

// Ghi ra trên một dòng số tờ tiền ít nhất phải trả.

// Nếu không thể tìm được kết quả, in ra -1.

// Ví dụ

// Input

// 3 5

// 1 4 5

// Output

// 1

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n,s;
vector<int> a;
int cnt;
bool isOk;

void Try(int idx , int sum , int dem){
    if(sum > s || dem >= cnt) return;
    if(sum == s){
        isOk = true;
        cnt = min(cnt , dem);
        return;
    }
    for(int i=idx;i<n;i++){
        if(sum + a[i] <= s){
            Try(i+1 , sum + a[i] , dem+1);
        }
    }
}

void testCase(){
    cin >> n >> s;
    a.assign(n , 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    isOk = false;
    cnt = INT_MAX;
    Try(0 , 0 , 0);
    if(!isOk){
        cout << "-1" << endl;
        return;
    }
    cout << cnt << endl; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    testCase();    
    return 0;
}