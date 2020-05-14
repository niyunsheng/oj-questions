 #include<iostream>
 #include<vector>
 #include<map>
 #include<string>
 #include<queue>
 using namespace std;

 //1034 Head of a Gang (30)
 /*需要注意的是：
 1邻接表的表示方法
 2名字与节点的对应关系map，最后答案要求按照字母序，显然用map
 3注意在BFS的过程中，对节点元素的处理以确定节点总数和最大元素
 **9月4日更：又用了DFS来写，但是有一个两分的case出现段错误，真是没救了,估计是要写bfs的形式，可能栈溢出了。
 */
int main(){
    //freopen("D:\\input.txt","r",stdin);
    int N,K;
    scanf("%d %d",&N,&K);
    //定义邻接表的最简单方法，最多有2*N个节点
    vector<int> grid[2*N];//这个写法就是邻接表的另外一种表达
    vector<int> weight(2*N,0);

    //名字与节点序号的对应关系用map和向量实现
    map<string,int> str2num;int hashrank=0;//记录成员的个数
    vector<string> num2str;
    //记录答案
    map<string,int> ans;

    string name1,name2;
    int time;
    //初始化
    for(int i=0;i<N;i++){
        cin>>name1>>name2>>time;//这里用cin也是没问题的
        //下面写为getID更好
        if(str2num.count(name1)==0){
            str2num[name1]=hashrank++;num2str.push_back(name1);
        }
        if(str2num.count(name2)==0){str2num[name2]=hashrank++;num2str.push_back(name2);}
        int t1=str2num[name1],t2=str2num[name2];
        grid[t1].push_back(t2);weight[t1]+=time;
        grid[t2].push_back(t1);weight[t2]+=time;
   }
    vector<bool> finded(hashrank,false);
    //BFS图遍历，在图遍历的过程中记录权值最大的点、成员个数和通话时间总和
    //和一般的BFS不同之处就是就加入了对于图中节点的处理
    int gangnum=0;//满足题意的连通域总数
    int sub_sum,sub_id,sub_p;//分别记录连通域的权值\最大值的id\成员个数
    for(int i=0;i<hashrank;i++){
        if(!finded[i]){//发现新连通域
            queue<int> q;//DFS队列
            q.push(i);
            finded[i]=true;sub_sum=weight[i];sub_id=i;sub_p=1;
            int cur;
            while(!q.empty()){
                cur=q.front();q.pop();
                for(int j=0;j<grid[cur].size();j++){
                    if(!finded[grid[cur][j]]){
                        finded[grid[cur][j]]=true;
                        sub_sum+=weight[grid[cur][j]];
                        if(weight[grid[cur][j]]>weight[sub_id])sub_id=grid[cur][j];
                        sub_p++;
                        q.push(grid[cur][j]);
                    }
                }
            }
            //cout<<num2str[i]<<" "<<weight[i]<<" "<<sub_p<<" "<<sub_sum<<endl;
            if(sub_p>2&&sub_sum/2>K){
                gangnum++;//连通域个数
                ans[num2str[sub_id]]=sub_p;
            }
        }
    }
    printf("%d\n",gangnum);
    for(map<string,int>::iterator it=ans.begin();it!=ans.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
//DFS 版本，有一个段错误

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int cnt=0;//连通域个数
vector<bool> vis(1005,false);
vector<int> weight(1005,0);
map<string,int> str2int;
vector<string> int2str;
int n=0;//总人数
vector<vector<int> > grid(1005);
//DFS的过程中记录最大节点
vector<int> ans;
int maxw,maxid;

void DFS(int x,int& sum,int& mem){
	sum+=weight[x];
	if(weight[x]>maxw){maxid=x;maxw=weight[x];}
	_for(i,0,grid[x].size()){
		if(!vis[grid[x][i]]){
			mem++;
			vis[grid[x][i]]=true;
			DFS(grid[x][i],sum,mem);
		}
	}
}
map<string,int> ans2;
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,K,c1,c2,w;
	string s1,s2;
	cin>>N>>K;
	_for(i,0,N){
		cin>>s1>>s2>>w;
		if(str2int.count(s1)==0){
			int2str.push_back(s1);
			str2int[s1]=n;
			n++;
		}
		if(str2int.count(s2)==0){
			int2str.push_back(s2);
			str2int[s2]=n;
			n++;
		}
		c1=str2int[s1];c2=str2int[s2];
		weight[c1]+=w;
		weight[c2]+=w;
		//cout<<s1<<weight[c1]<<" "<<s2<<weight[c2]<<endl;
		grid[c1].push_back(c2);
		grid[c2].push_back(c1);
	}
	_for(i,0,n){
		if(!vis[i]){
			vis[i]=true;
			maxw=0;
			int sum=0;//总边权
			int mem=1;//成员数
			DFS(i,sum,mem);
			if(mem>2&&sum>2*K){ans.push_back(maxid);ans.push_back(mem);}
		}
	}
	printf("%d\n",ans.size()/2);

	for(int i=0;i<ans.size();i+=2){
		ans2[int2str[ans[i]]]=ans[i+1];
	}
	for(map<string,int>::iterator it=ans2.begin();it!=ans2.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
