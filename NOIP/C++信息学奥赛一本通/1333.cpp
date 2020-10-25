#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long q[1000005];
    int b,n;
    while(cin>>b>>n){
        int tail=0,two=0,three=0; // 队尾
        q[tail]=b;tail++;
        while(tail<n){
            long long t1=q[two]*2+1,t2=q[three]*3+1;
            long long t=min(t1,t2);
            if(t1<t2)two++;
            else three++;
            if(t==q[tail-1])continue;
            q[tail]=t;
            tail++;
        }
        cout<<q[tail-1]<<endl;
    }
}
