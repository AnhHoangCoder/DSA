// Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ. 

// Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi ít nhất để đưa bảng đến trạng thái đích.

// Input:

// Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:
// Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
// Dòng thứ hai chứa 6 số là trạng thái bảng đích (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
// Output: 

// Với mỗi test, in ra một số nguyên là đáp số của bài toán.
// Ví dụ:

// Input

// Output

// 1

// 1 2 3 4 5 6

// 4 1 2 6 5 3

 

// 2

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define Max 1000000

vector<int> numToVector(int u){
    vector<int> res(7);
    for(int i=6;i>=1;i--){
        res[i] = u % 10;
        u /= 10;
    }
    return res;
}

int vectorToNum(vector<int> &a){
    int res = 0;
    for(int i=1;i<=6;i++){
        res = res * 10 + a[i];
    }
    return res;
}

int leftRotate(int u){
    vector<int> a = numToVector(u); 
    vector<int> b(7);
    
    b[1] = a[4] , b[2] = a[1] , b[3] = a[3];
    b[4] = a[5] , b[5] = a[2] , b[6] = a[6];

    int res = vectorToNum(b);
    return res;
}

int rightRotate(int u){
    vector<int> a = numToVector(u);
    vector<int> b(7);
    b[1] = a[1] , b[2] = a[5] , b[3] = a[2];
    b[4] = a[4] , b[5] = a[6] , b[6] = a[3];

    int res = vectorToNum(b);
    return res;
}

int solve(int start , int end){
    queue<int> q;
    unordered_map<int,int> dist;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == end) return dist[u];

        int l = leftRotate(u);
        int r = rightRotate(u);

        if(!dist.count(l)){
            dist[l] = dist[u] + 1;
            q.push(l);
        }

        if(!dist.count(r)){
            dist[r] = dist[u] + 1;
            q.push(r);
        }
    }
    return -1;
}

void nhap(int &s){
    for(int i=0;i<6;i++){
        int x;
        cin >> x;
        s = s * 10 + x;
    }
}

void testCase(){
    int start = 0 , end = 0;

    nhap(start);
    nhap(end);
    
    cout << solve(start , end) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}