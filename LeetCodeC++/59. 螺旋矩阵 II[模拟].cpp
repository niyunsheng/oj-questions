/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */
//只要注意换方向的写法即可，细心点，与54题螺旋矩阵I同
class Solution {
public:
    int _x[4]={1,0,-1,0},_y[4]={0,1,0,-1};
    bool is_legal(int x,int y,int n, vector<vector<bool> >& vis){
        return x>=0&&x<n&&y>=0&&y<n&&!vis[y][x];
    }
    vector<vector<int>> generateMatrix(int n) {
        int cnt=1,x=0,y=0,dir=0;
        vector<vector<int> > ans(n,vector<int>(n));
        vector<vector<bool> > vis(n,vector<bool>(n,false));
        while(1){
            if(cnt>n*n)break;
            while(is_legal(x,y,n,vis)){
                //cout<<dir<<"Hi"<<y<<x<<cnt<<endl;
                ans[y][x]=cnt++;
                vis[y][x]=true;
                x+=_x[dir];y+=_y[dir];
            }
			//注意这里换方向的写法
            x-=_x[dir];y-=_y[dir];
            dir=(dir+1)%4;
            x+=_x[dir];y+=_y[dir];
            //cout<<dir<<"ij"<<y<<x<<cnt<<endl;
        }
        return ans;
    }
};
