/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
//这个题目含义写的好不清楚，开头一句“where D is in [0, 9] except 1. ”，我还以为D不能取1呢，然后算例给的D=1，看了好久才明白这个字符串是怎么描述的，明白了题目就不难了。 
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int D,N;
	scanf("%d %d",&D,&N);
	vector<vector<int> > vec(N);
	vec[0].push_back(D);
	_for(i,1,N){
		int lo=0,hi;
		while(lo<vec[i-1].size()){
			hi=lo;
			while(hi<vec[i-1].size()&&vec[i-1][hi]==vec[i-1][lo])hi++;
			vec[i].push_back(vec[i-1][lo]);
			vec[i].push_back(hi-lo);
			lo=hi;
		}
		//printvec(vec[i]);
	}
	_for(i,0,vec[N-1].size())printf("%d",vec[N-1][i]);
	printf("\n");
    return 0;
}
