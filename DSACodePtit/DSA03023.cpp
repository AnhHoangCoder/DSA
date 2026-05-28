// Cho một dãy N viên bi gồm 3 màu xanh, trắng, đỏ xếp lẫn lộn. Bằng cách đổi chỗ từng cặp viên bi cho nhau có thể xếp lại dãy bi trên sao cho các viên bi xanh đứng trước, sau đó đến các viên bi trắng và cuối cùng là các viên bi đỏ. Tìm số lượng ít nhất các phép đổi chỗ cần thực hiện

// Input

// Dòng đầu  tiên ghi N (N≤100)
// Dòng thứ hai ghi xâu ký tự mô tả dãy bi (T-trắng, X-xanh, D-đỏ).
// Output

// Một dòng duy nhất ghi số phép đổi chỗ tối thiểu cần thực hiện

 

// Ví dụ

 

// Input

// Output

// 9

// TTXDDDTDX

// 4

#include <iostream>

using namespace std;

int id(char c){
    if(c == 'X') return 0;
    else if(c == 'T') return 1;
    return 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n;
    cin >> s;

    int cntColor[3] = {};
    for(char c : s){
        cntColor[id(c)]++;
    }
    //mis[a][b]
    //mau a dang nam trung vung cua mau b
    int mis[3][3] = {};

    for(int i=0;i<n;i++){
        int region;

        if(i < cntColor[0]) region = 0;
        else if(i < cntColor[0] + cntColor[1]) region = 1;
        else region = 2;

        int cur = id(s[i]);
        mis[cur][region]++;
    }

    int ans = 0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            int t = min(mis[i][j] , mis[j][i]);

            ans += t;
            mis[i][j] -= t;
            mis[j][i] -= t;
        }
    }

    //Loi chu trinh 3 phan tu
    int remain = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i != j){
                remain += mis[i][j];
            }
        }
    }

    ans += 2 * (remain / 3);
    cout << ans << endl;
    return 0;
}