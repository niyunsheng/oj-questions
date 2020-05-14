/**
 * @Date:   2018-08-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
//1009 Product of Polynomials (25)
#include <iostream>
#include<vector>
#include"string.h"
using namespace std;
//其实没必要把两个vector都存下来之后再计算，可以只存一个，然后第二个，边计算
struct node{
    int a;
    float b;
    node(int aa,float bb):a(aa),b(bb){}
    node operator*(node& y){
        return node(a+y.a,b*y.b);
    }
};
int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
    float coef[2001];memset(coef,0,sizeof(coef));
    vector<vector<node>> vec(2);

    int n,a;
    float b;

    for(int j=0;j<2;j++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %f",&a,&b);
            vec[j].push_back(node(a,b));
        }
    }

    for(int i=0;i<vec[0].size();i++)
        for(int j=0;j<vec[1].size();j++){
            node t=vec[0][i]*vec[1][j];
            coef[t.a]+=t.b;
        }
    int sum=0;
    for(int i=0;i<2001;i++)
        if(coef[i]!=0)sum++;
    printf("%d",sum);
    for(int i=2000;i>=0;i--){
        if(coef[i]!=0)printf(" %d %.1f",i,coef[i]);
    }

    return 0;
}
