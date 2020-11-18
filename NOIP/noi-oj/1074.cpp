#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string ans;
void DFS(int n){
    // cout<<ans<<"#"<<n<<endl;
    if(n==0){
        ans += "0";
    }else{
        vector<int> tmp;
        int cnt = 0;
        while(n!=0){
            if(n%2==1){
                tmp.push_back(cnt);
            } 
            n /= 2;
            cnt++;
        }
        bool flag=true;
        for(int i=tmp.size()-1;i>=0;i--){
            if(!flag)ans += "+";
            if(tmp[i]==1){
                ans += "2";
            }else{
                ans += "2(";
                DFS(tmp[i]);
                ans += ")";
            }
            flag = false;
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    DFS(n);
    cout << ans << endl;
    return 0;
}
