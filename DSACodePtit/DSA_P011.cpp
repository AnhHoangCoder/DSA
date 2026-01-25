// Một mê cung được mô tả dưới dạng ma trận ký tự trong đó dấu ‘.’ là mô tả ô trống, không có vật cản, dấu ‘#’ mô tả một vật cản. Các vật cản sẽ ghép lại với nhau thành vật cản lớn hơn nếu nó liền kề theo hàng hoặc cột.

// Hãy đếm xem trong mê cung có bao nhiêu vật cản.

// Input

// Dong đầu ghi số hai số N, M (N, M <= 1000) là số hàng và số cột của mê cung.

// N dòng tiếp theo mô tả mê cung trong đó chỉ có các ký tự ‘.’ và ‘#’.

// Output

// Ghi ra số vật cản đếm được.

// Ví dụ

// Input

// 5 6

// .#....

// ..#...

// ..#..#

// ...##.

// .#....

// Output

// 5

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dem(vector<vector<char>> &a , int n , int m){
    //left -> up -> right -> down
    vector<int> dx = {0 , -1 , 0 , 1};
    vector<int> dy = {-1 , 0 , 1 , 0};

    int res = 0;
    stack<pair<int,int>> st;
    vector<vector<bool>> used(n,vector<bool> (m , false));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '#' && !used[i][j]){
                res++;
                st.push({i,j});
                used[i][j] = true;
                while(!st.empty()){
                    auto [x , y] = st.top();
                    for(int k=0;k<4;k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                            if(a[nx][ny] == '#' && !used[nx][ny]){
                                st.push({nx , ny});
                                used[nx][ny] = true;
                            }
                        }
                    }
                    st.pop();
                }
            }
        }
    }
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n , vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cout << dem(a,n,m) << endl;
    return 0;
}