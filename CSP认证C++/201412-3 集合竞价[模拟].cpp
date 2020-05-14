/**
 * @Date:   2018-08-25
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-25
 */
//思路：首先是处理订单，将有效的购物订单存储到vector中，方便后面排序。（这里有个大坑，cancel i指的是第i行的数据，而不是第i个订单，起初把这个搞混了，只有30分，改了后就满分了）。然后对订单按照价格排列，之后采用了两个订单累积和的数据dp_buy[i]表示售价为buy[i]时愿意买的人的总数；dp_sell[i]表示售价为sell[i]时愿意卖的人的总数。
//题目整体思路还是很清晰的，CSP考试给的算例太简单了，这就需要对题目的每一句话都写一个算例出来，自己的测试数据可能不复杂，但是要覆盖到题目的各个情况。当然了，如果是题意理解不对的话，由于自己给的算例是没有标准答案的，所以，就难以发现错误了。还是避免先入为主，看清楚题目要求。
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

struct node{
    int flag;//0表示交易不存在，1表示买，2表示卖
    float p;
    long long s;//价格、股数
    node(){}
    node(int f,float pp,long long ss):flag(f),p(pp),s(ss){}
    bool operator<(node& b){
        return p<b.p;
    }
};
bool cmp(node& a,node& b){
    return a.p<b.p;
}
#define MAXN 5005
node deal[MAXN];

int main() {
    freopen("D:\\input.txt","r",stdin);
    char str[10];
    float p;
    long long s;
    int top=1;
    while(scanf("%s",str)!=EOF){
        if(str[0]=='b'){
            scanf("%f %lld",&p,&s);
            deal[top++]=node(1,p,s);
        }else if(str[0]=='s'){
            scanf("%f %lld",&p,&s);
            deal[top++]=node(2,p,s);
        } else{
            scanf("%lld",&s);
            deal[s].flag=0;
        }
    }
    //预处理，将有效的买卖分离并排序
    vector<node> buy,sell;
    _for(i,1,top){
        if(deal[i].flag==1){
            buy.push_back(deal[i]);
        }else if(deal[i].flag==2){
            sell.push_back(deal[i]);
        }
    }
    sort(buy.begin(),buy.end());
    sort(sell.begin(),sell.end());
    long long dp_buy[MAXN];//dp_buy[i]表示售价为buy[i]时愿意买的人的总数
    long long dp_sell[MAXN];//dp_sell[i]表示售价为sell[i]时愿意卖的人的总数
    dp_buy[buy.size()-1]=buy[buy.size()-1].s;
    for(int i=buy.size()-2;i>=0;i--){
        dp_buy[i]=dp_buy[i+1]+buy[i].s;
    }
    dp_sell[0]=sell[0].s;
    for(int i=1;i<sell.size();i++){
        dp_sell[i]=dp_sell[i-1]+sell[i].s;
    }

    //按照买卖价格从低到高枚举，直到买面双方一方到头，枚举结束，过程中记录最大交易量
    long long count=0;
    float tarP;
    int i=0,j=0;//双指针，分别指向买卖双方
    while(i<buy.size()&&j<sell.size()){
        long long t;
        if(buy[i].p<sell[j].p){
            t=min(j==0?0:dp_sell[j-1],dp_buy[i]);
            if(t>count){
                count=t;tarP=buy[i].p;
            }
            i++;
        }else{
            t=min(dp_sell[j],dp_buy[i]);
            if(t>count){
                count=t;tarP=buy[j].p;
            }
            j++;
        }
    }
    printf("%.2f %lld\n",tarP,count);
    return 0;
}
