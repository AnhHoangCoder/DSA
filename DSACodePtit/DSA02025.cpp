// Cho một dãy các xâu ký tự chỉ bao gồm các chữ cái in hoa từ A đến Z, trong đó các ký tự trong mỗi xâu đều đã được sắp xếp theo thứ tự từ điển và mỗi chữ cái chỉ xuất hiện nhiều nhất một lần (tức là độ dài xâu tối đa là 26). Nếu một ký tự xuất hiện trong hai xâu liên tiếp thì được coi là một lần lặp. Hãy tìm cách sắp xếp lại thứ tự các xâu sao cho số lần lặp là nhỏ nhất có thể. Ví dụ dưới đây là cùng một dãy xâu nhưng với cách sắp xếp lại thì số lần lặp chỉ còn 2.

// ABC
// ABEF
// DEF
// ABCDE
// FGH

// => Số lần lặp là 6

// ABEF
// DEF
// ABC
// FGH
// ABCDE

// => Số lần lặp là 2.

// Input

// Dòng đầu tiên ghi số N (2 ≤ N ≤ 10) là số xâu ký tự. N dòng tiếp theo, mỗi dòng ghi một xâu. 

// Output

// In ra trên một dòng số lần lặp nhỏ nhất có thể. 

// Ví dụ

// Input

// Output

// 5
// ABC
// ABEF
// DEF
// ABCDE
// FGH

// 2

// 6
// BDE
// FGH
// DEF
// ABC
// BDE
// ABEF

// 3

// 4
// XYZ
// XYZ
// ABYZ
// Z
 
// 4

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<string> a , hoanVi;
vector<bool> used;
int Min;

void backTrack(int pos , int count){
    if(pos > n){
        Min = min(Min , count);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]) {
            used[i] = true;
            hoanVi[pos] = a[i];

            vector<int> check(26);
            for(char c : hoanVi[pos]) check[c-'A']++;
            for(char c : hoanVi[pos-1]) check[c-'A']++;
            
            int dem = 0;
            for(int x : check){
                if(x == 2) dem++;
            }
            
            if(count + dem < Min){
                backTrack(pos + 1 , count + dem);
            }
            used[i] = false;
        }       
    }
}

void testCase(){
    cin >> n;
    a.clear();
    hoanVi.clear();
    a.resize(n+1);
    hoanVi.resize(n+1);
    used.assign(n+1 , false);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    Min = INT_MAX;
    backTrack(1 , 0);
    cout << Min << endl;
}

int main(){
    testCase();
    return 0;
}