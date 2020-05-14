/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int k;
    cin>>k;
	char str[1005];
	vector<char> ans;
	int badkey[256],goodkey[256];
	memset(badkey,-1,sizeof(badkey));
	memset(goodkey,-1,sizeof(goodkey));
	scanf("%s",str);
	int len=strlen(str),lo=0,hi;
	while(lo<len){
		hi=lo;
		while(hi<len&&str[hi]==str[lo])hi++;
		if((hi-lo)%k==0){
			if(goodkey[str[lo]]!=1&&badkey[str[lo]]!=1){
				badkey[str[lo]]=1;
				ans.push_back(str[lo]);
			}
		}else{
			goodkey[str[lo]]=1;
		}
		lo=hi;
	}
	_for(i,0,ans.size()){
		if(goodkey[ans[i]]!=1){
			printf("%c",ans[i]);
		}
	}
	printf("\n");
	lo=0;
	while(lo<len){
		printf("%c",str[lo]);
		if(goodkey[str[lo]]==1){
			lo++;
		}else{
			lo+=k;
		}
	}
	return 0;
}
