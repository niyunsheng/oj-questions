/**
 * @Date:   2018-08-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-14
 */
#include<iostream>
#include<vector>
#include<set>
#include"string.h"
using namespace std;

//1021 Deepest Root (25)
 /*
 本题难点：1如果有两个以上的连通域，可以用DFS或者并查集求出
		   2一个连通域的情况下，得证明第一次任一节点遍历得到的最大深度节点为最深节点的子集，然后从这些子集再一次遍历，得到的最深节点加入结合，即可得到最深节点的全集。
           ***两次遍历即可，第二次只需要从第一次选出的节点中任选一个遍历一次即可
		   这个两次遍历之所以正确，重要的中间证明为：从任一节点遍历，得到的最深节点必然是最深节点的子集；所有直径必然有一段公共重合区域或者交于一公共点，
 */
vector<vector<int>> grid(10001);//节点标号为1-N
bool finded[10001];
int depth;//记录树的深度
int mxdepth;//记录树的最大深度
int connected;//记录连通域个数
set<int> mxset,tmpset;//最大节点集合
void DFS(int i,int depth){
    for(int j=0;j<grid[i].size();j++){
        if(!finded[grid[i][j]]){
            finded[grid[i][j]]=true;
			//cout<<"find:"<<grid[i][j]<<endl;
			if(depth+1>mxdepth){
				mxset.clear();
				mxdepth=depth+1;
				mxset.insert(grid[i][j]);
				//cout<<"mxset.clear+insert"<<grid[i][j]<<"  depth:"<<depth<<endl;
			}else if(depth+1==mxdepth){
				mxset.insert(grid[i][j]);
				//cout<<"mxset.insert"<<grid[i][j]<<"  depth:"<<depth<<endl;
			}
            DFS(grid[i][j],depth+1);
        }
    }
}

int main(){
    //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
    int N;
    scanf("%d",&N);
	if(N==1){printf("1\n");return 0;}//边界情况，特殊处理
    int c1,c2;
    for(int i=1;i<N;i++){
        scanf("%d %d",&c1,&c2);
        grid[c1].push_back(c2);
        grid[c2].push_back(c1);
    }
    int r;

    //首先计算连通域个数，当构成树的条件下再计算最大深度,不妨从节点1开始，并且记录节点的深度，与第一次遍历结合起来
    connected=0;
	mxdepth=0;
    memset(finded,false,sizeof(finded));
    for(int i=1;i<=N;i++){
        if(!finded[i]){
            finded[i]=true;
            connected++;
            DFS(i,1);//从1节点开始遍历，设初始节点即1的深度为1
        }
    }
    if(connected!=1){
        printf("Error: %d components\n",connected);
        return 0;
    }
    //以下可保证连通域只有一个

    tmpset=mxset;
	//第二次遍历，依次从首次遍历的结果点开始遍历
    mxdepth=0;
	memset(finded,false,sizeof(finded));
	for(set<int>::iterator it=tmpset.begin();it!=tmpset.end();it++){
		//cout<<"tmpset:"<<*it<<endl;
		finded[*it]=true;
		DFS(*it,1);

	}
	for(set<int>::iterator it=tmpset.begin();it!=tmpset.end();it++){
		mxset.insert(*it);
	}

    for(set<int>::iterator it=mxset.begin();it!=mxset.end();it++){
        printf("%d\n",*it);
    }
    return 0;
}

//9月4日更新：两次遍历即可，第二次只需要从第一次选出的节点中任选一个遍历一次即可

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int cnt=0;//连通域个数
vector<bool> vis(10001,false),ans(10001,false);
vector<int> tmp,tmp1;
vector<vector<int> > grid(10001);
int maxh=0;
void DFS(int x,int h){
	bool flag=false;
	_for(i,0,grid[x].size()){
		if(!vis[grid[x][i]]){
			flag=true;
			vis[grid[x][i]]=true;
			DFS(grid[x][i],h+1);
		}
	}
	if(!flag){
		if(h>maxh){
			maxh=h;
			tmp.clear();
			tmp.push_back(x);
		}else if(h==maxh)tmp.push_back(x);
	}
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,c1,c2;
	cin>>N;
	_for(i,0,N-1){
		cin>>c1>>c2;
		grid[c1].push_back(c2);
		grid[c2].push_back(c1);
	}
	cnt=0;
	_for(i,1,N+1){
		if(!vis[i]){
			cnt++;
			vis[i]=true;
			DFS(i,0);
		}
	}

	if(cnt!=1){
		printf("Error: %d components\n",cnt);
		return 0;
	}
	tmp1=tmp;

	_for(i,0,tmp.size()){ans[tmp[i]]=true;}
	fill(vis.begin(),vis.end(),false);

	tmp.clear();
	vis[tmp1[0]]=true;
	DFS(tmp1[0],0);
	_for(i,0,tmp.size()){ans[tmp[i]]=true;}
	_for(i,1,N+1){
		if(ans[i])
			printf("%d\n",i);
	}
	return 0;
}
