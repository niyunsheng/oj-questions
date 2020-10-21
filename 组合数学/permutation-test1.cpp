/* 全排列算法
测试递增和递减进位制数的时间
*/
#include<cstdio>
#include<vector>
#include<time.h>
using namespace std;

void print_vector(vector<int>& v){
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    printf("\n");
}
// 计算递增和递减进位制数的加减法，increase为真时表示递增进位制
void calculate_increase_number(vector<int>& num,int k,bool increase){
    if(k==0)return;
    bool positive=(k>0);
    k = positive?k:-k;
    int base; // 进位制
    // 将k转化为递增或递减进位制数
    vector<int> k_num(num.size());
    for(int i=num.size()-1;i>=0;i--){
        if(increase)
            base = num.size()+1-i;
        else
            base = i+2;
        k_num[i] = k%base;
        k /= base;
    }
    // print_vector(k_num);
    assert(k==0);
    // 加减法
    int carry=0;//上一级的进位
    for(int i=num.size()-1;i>=0;i--){
        if(increase) //切换递增递减进制
            base = num.size()+1-i;
        else
            base = i+2;
        if(positive){  // 加减法的不同处理
            num[i] = num[i]+k_num[i]+carry;
            carry = num[i]/base;
            num[i] = num[i]%base;
        }else{
            num[i] = num[i]-carry-k_num[i];
            if(num[i]<0){
                carry = 1;
                num[i] += base;
            }else{
                carry = 0;
            }
        }
    }
    // print_vector(num);
    assert(carry==0);
}

int main(){
    int n=8;
    vector<int> v(n-1,0);
    int cnt=1;
    clock_t start,finish;
    for(int i=1;i<=n;i++)cnt*=i;
    for(int i=0;i<n-1;i++)v[i]=0;
    printf("测试递增进位制数\n");
    start=clock();
    for(int i=0;i<cnt-1;i++)
        calculate_increase_number(v,1,true);
    for(int i=0;i<n-1;i++)v[i]=0;
    finish=clock();
    printf("运行时间：%.5f\n",(float)(finish-start)/CLOCKS_PER_SEC);
    printf("测试递减进位制数\n");
    start=clock();
    for(int i=0;i<cnt-1;i++)
        calculate_increase_number(v,1,false);
    finish=clock();
    printf("运行时间：%.5f\n",(float)(finish-start)/CLOCKS_PER_SEC);
    return 0;
}