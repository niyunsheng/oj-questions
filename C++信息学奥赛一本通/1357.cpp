#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    int n,t[1005];
    cin >> n;
    for(int i=0;i<n;i++)cin>>t[i];
    for (int i = 1,cur=0;i <= n;++ i){//i进站车辆
        s.push(i);
        while(!s.empty()&&t[cur]==s.top()){
            cur++;
            s.pop();
        }
    }
    if(s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
