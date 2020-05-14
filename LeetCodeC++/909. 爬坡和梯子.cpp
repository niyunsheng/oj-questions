//contest 103
//未完成，结果有错，暂时搁置
class Solution {
public:
    int funrank(int n,int i,int j){return ((n-1-i)%2==0?(n-1-i)*n+j+1:(n-1-i)*n+n-j);}
    int funranki(int n,int k){return n-1-(k-1)/n;}
    int funrankj(int n,int k){return ((k-1)/n%2)==0?(k-(k-1)/n*n-1):(n-k+(k-1)/n*n);}
    int snakesAndLadders(vector<vector<int>>& board) {
        int N=board.size();
        vector<vector<bool> > vis(N,vector<bool>(N,false));
        vis[funranki(N,1)][funrankj(N,1)]=true;
        int step=1;
        int start=1,end=N*N;
        queue<int> q;
        q.push(start);q.push(0);
        while(!q.empty()){
            int cur=q.front();q.pop();
            if(cur==0){
                if(q.empty())break;
                else{
                    q.push(0);step++;continue;
                }
            }
            bool flag=false;
            for(int i=1;i<=6;i++){
                int nx;
                if(cur+i<=N*N&&!vis[funranki(N,cur+i)][funrankj(N,cur+i)]){
                    printf("i=%d j=%d\n",funranki(N,cur+i),funrankj(N,cur+i));
                    vis[funranki(N,cur+i)][funrankj(N,cur+i)]=true;
                    int nk=board[funranki(N,cur+i)][funrankj(N,cur+i)];
                    if(nk==-1){
                        nx=cur+i;
                    }else{
                        if(!vis[funranki(N,nk)][funrankj(N,nk)]){
                            printf("ni=%d nj=%d\n",funranki(N,nk),funrankj(N,nk));
                            vis[funranki(N,nk)][funrankj(N,nk)]=true;
                            nx=nk;
                        }
                    }
                    printf("nk=%d nx=%d step=%d\n",nk,nx,step);
                    if(nx==N*N){flag=true;break;}
                    q.push(nx);
                }

            }
            if(flag)break;
        }
        int ans;
        if(vis[funranki(N,end)][funrankj(N,end)])ans=step;
        else ans=-1;
        //cout<<ans;
        return ans;
    }
};
