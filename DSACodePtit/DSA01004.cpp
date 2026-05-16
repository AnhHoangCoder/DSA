#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

bool sinh(){
    int i = k;
    while(i > 0 && a[i] == n-k+i) i--;
    if(i == 0) return false;
    a[i]++;
    for(int j=i+1;j<=k;j++){
        a[j] = a[j-1]+1;
    }
    return true;
}

void test_case(){
    cin >> n >> k;
    a.assign(k+1,0);
    for(int i=1;i<=k;i++){
        a[i] = i;
    }
    do{
        for(int u=1;u<=k;u++){
            cout << a[u];
        }
        cout << " ";
    }while(sinh());
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}