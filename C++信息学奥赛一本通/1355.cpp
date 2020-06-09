#include<iostream>
#include<stack>
using namespace std;
int main(){
    string t;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        cin>>t;
        stack<char> s;
        bool flag=true; //表示可以匹配
        int level[4]={0}; // 分别记录栈中四种括号的个数
        for(int j=0;j<t.size();j++){
            switch(t[j]){
                case '{':
                    if(level[1]==0&&level[2]==0&&level[3]==0) s.push(t[j]);
                    else flag=false;
                    break;
                case '[':
                    if(level[2]==0&&level[3]==0) s.push(t[j]);
                    else flag=false;
                    level[1]++;
                    break;
                case '(':
                    if(level[3]==0) s.push(t[j]);
                    else flag=false;
                    level[2]++;
                    break;
                case '<':
                    s.push(t[j]);
                    level[3]++;
                    break;
                case '}':
                    if(!s.empty()&&s.top()=='{')s.pop();
                    else flag=false;
                    break;
                case ']':
                    if(!s.empty()&&s.top()=='[')s.pop();
                    else flag=false;
                    level[1]--;
                    break;
                case ')':
                    if(!s.empty()&&s.top()=='(')s.pop();
                    else flag=false;
                    level[2]--;
                    break;
                case '>':
                    if(!s.empty()&&s.top()=='<')s.pop();
                    else flag=false;
                    level[3]--;
                    break;
                
            }
            if(!flag)break;
        }
        if(flag&&s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
