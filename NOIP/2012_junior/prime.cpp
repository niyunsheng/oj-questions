#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long i=2;
    if(n%i==0){
        cout << n/i << endl;
        return 0;
    }
    for(i=3;i*i<n;i+=2){
        if(n%i==0)break;
    }
    cout << n/i << endl;
    return 0;
}