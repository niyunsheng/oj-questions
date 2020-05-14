/**
 * @Date:   2018-09-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
51. N皇后
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<string> > strans;
    vector<int> tmp;
    vector<bool> vis;
    bool conflicted(vector<int>& tmp,int x){
        for(int i=0;i<tmp.size();i++){
            if(x==tmp[i])return false;
            if(tmp.size()+x==i+tmp[i])return false;//斜对角线
            if(tmp.size()-x==i-tmp[i])return false;//正对角线
        }
        return true;
    }
    void solve(int step,int n){
        if(step==n){
            ans.push_back(tmp);
            //cout<<ans[0][0]<<endl;
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(conflicted(tmp,i)){
                    vis[i]=true;
                    tmp.push_back(i);
                    solve(step+1,n);
                    tmp.pop_back();
                    vis[i]=false;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vis.resize(n,false);
        fill(vis.begin(),vis.end(),false);
        int step=0;
        solve(step,n);
        for(int i=0;i<ans.size();i++){
            vector<string> strtmp;
            for(int j=0;j<ans[i].size();j++){
                string s;
                for(int k=0;k<n;k++){
                    if(ans[i][j]==k)s+="Q";
                    else s+=".";
                }
                strtmp.push_back(s);
            }
            strans.push_back(strtmp);
        }
        return strans;
    }
};

//思路相同，但是相对更加简单点的方法
//8皇后问题
#define N 8
vector<int> v(N,0);//表示每一行中皇后的位置
int cnt=0;
bool conflict(int step){
	_for(i,0,step){
		if(v[i]==v[step]||v[i]-i==v[step]-step||v[i]+i==v[step]+step)
			return true;
	}
	return false;
}
void DFS(int step){
	if(step==N){
		_for(i,0,N){
			printf("%d ",v[i]);
		}
		printf("\n");
		cnt++;
		return;
	}
	_for(i,0,N){
		v[step]=i;
		if(!conflict(step))
			DFS(step+1);
	}
}
int main(int argc, char** argv) {
	int step=0;
	DFS(step);
	cout<<cnt<<endl;
	return 0;
}
