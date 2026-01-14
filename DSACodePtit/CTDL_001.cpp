#include <iostream>

using namespace std;

int a[10];
int n;

bool check(){
    for(int j = 0 ; j < n/2 ; j++){
        if(a[j] != a[n-j-1]) return false;
    }
    return true;
}

bool sinh(){
    int i = n-1;
    while(i>=0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i < 0) return false;
    a[i]++;
    return true;
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        a[i] = 0;
    }
    do{
        if(!check()){
            continue;
        }        
        for(int i = 0 ; i < n ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }while(sinh());
    return 0;
}