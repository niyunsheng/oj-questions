/* 全排列算法

算法1：STJ算法
    思路和要点
        * 每个元素都有移动的方向
        * 选择可移动元素中的最大元素进行移动
        * 移动该元素之后，比他大的元素要更新方向

算法2：字典序法
    思路和要点
        * 要求这一个与下一个有尽可能长的共同前缀，即将变化限制在尽可能短的后缀上
        * 从右往前找，找到第一个出现下降的位置
        * 将该下降元素与后面的比他大的最小的元素交换
        * 交换之后将其后元素从小到大排列，即翻转

算法3：递增进位制数法
    按照字典序可以给所有的全排列编号
        * 比如最小的全排列的序号是0，则按照字典序依次是1、2……
        * 可以用排列组合的方法计算任意一个排列的序号
        * 计算序号的过程中可以的得到中介数（康托展开）
    康托展开
        * 比如全排列839647521的序号可以计算为
        * 7×8!+2×7!+6×6!+ 4×5!+2×4!+3×3!+2×2!+1×1!
        * 中介数为72642321
        * **中介数记录了当前数字右边比当前数字小的数字的个数**
        * 由中介数也可以推算出原始的全排列
        * 可用归纳法证明\sum_{k=1}^{n-1}{k×k!}=n!-1
    递增进位制数
        * 不同数位的进制不同的一种计数方法
        * 递增进位制数(a9a8a7a6a5a4a3a2)换算成十进制为
        * a9*8!+a8×7!+a7×6!+a6×5!+a5×4!+a4×3!+a3×2!+a2×1!
        * 即a9*8+a8)×7)+a7)×6+a6)×5+a5)×4+a4)×3+a3)×2+a2)×1!
        * 即表示范围递增进位制数的87654321对应十进制的9!-1
        * 递增进位制数和序号一一对应
    序号转化为递增进位制数
        * 是除k取余法的改进版本
        * 首先找到一个比序号小的最大阶乘数，对齐进行整除得到第一位
        * 然后对其余数反复用该方法
    定义新的中介数
        * 字典序中介数求全排列比较麻烦
        * 定义新的中介数，(a9a8a7……a2)ai表示i的右边比i小的数字的个数
        * 如839647521的新中介数为(67342221)，第一个6表示9的右边比9小的数字有6个，第二个7表示8的右边比8小的数字有8个
    求新排列的方法：
        原排列->原中介数->新中介数->新排列

算法4：递减进位制数法
    思路和要点：
        * 递增进位制数中，中介数的最低位是逢2进1，进位频繁，这是一个缺点
        * 将递增进位制数翻转，就得到了递减进位制数
        * 递减进位制就是将递增进位制数翻转即可
        * 但是递增和递减进位制数对应的字典序的序号是不同的
        * 
    优缺点
        * 进位不频繁，中介数不进位的情况下，只要把最大数和左边相邻数交换即可
        * 但是进位的话，邻域性依然不能保证

算法5：邻位对换法
    思路和算法
        * 前面的四种算法中，SJT是邻域性最好的，但是其解决不了找某个全排列的之后的第k个这样的问题
        * 这里对于中介数的定义又有所不同
        * 2的方向一定向左
        * (b2b3b4……b9)表示每个元素的反方向，比该元素小的元素的个数
        * 这里模拟STJ算法，每个元素都有方向，规定如下
        * 如果i是奇数，其方向由b_(i-1)决定，奇向左，偶向右
        * 如果i是偶数，其方向由b_(i-1)+b_(i-2)决定，同样是奇向左，偶向右

*/
#include<cstdio>
#include<vector>
#include<stack>
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
    assert(carry==0);
}

// 算法2：字典序法
// 计算一个全排列的之后第k个排列，k可正可负
void permutation_dictorder(vector<int>& v,int k){
    // 计算字典序中介数（该元素右侧比该元素小的数字的个数）
    int n = v.size();
    vector<int> intermediary(n-1);//中介数
    // 暴力算法，双层循环
    for(int i=0;i<n-1;i++){
        int c=0;
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j])c++;
        }
        intermediary[i] = c;
    }
    /* 改进算法，但是暂没有办法证明复杂度是否更好
    stack<int> low_stack,high_stack;
    high_stack.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!high_stack.empty()&&high_stack.top()<v[i]){
            low_stack.push(high_stack.top());
            high_stack.pop();
        }
        while(!low_stack.empty()&&low_stack.top()>v[i]){
            high_stack.push(low_stack.top());
            low_stack.pop();
        }
        intermediary[i] = low_stack.size();
        low_stack.push(v[i]);
    }
    */
    // 计算第k个的中介数
    // print_vector(intermediary);
    calculate_increase_number(intermediary,k,true);
    // print_vector(intermediary);
    // 由中介数找到排列
    vector<bool> vis(v.size()+1,true);
    for(int i=0;i<v.size()-1;i++){
        v[i] = 1;
        while(intermediary[i]!=0){
            if(vis[v[i]]){
                intermediary[i]--;
            }
            v[i]++;
        }
        while(!vis[v[i]])v[i]++;
        vis[v[i]] = false;
    }
    for(int i=1;i<=v.size();i++)if(vis[i])v[v.size()-1]=i;
    // print_vector(v);
}

// 算法3：递增进位制法
// 算法4：递减进位制法
// increase为真时表示递增进位制
// 计算一个全排列的之后第k个排列，k可正可负
void permutation_increase(vector<int>& v,int k,bool increase=true){
    // 计算递增中介数(i的右边比i小的数字的个数)
    int n = v.size();
    vector<int> intermediary(n-1);//中介数
    for(int i=0;i<n-1;i++){
        int c=0;
        if(v[i]==1)continue;
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j])c++;
        }
        assert(n-v[i]<n-1);
        intermediary[n-v[i]] = c;
    }
    if(!increase){
        for(int i=0;2*i<n-1;i++)
            swap(intermediary[i],intermediary[n-2-i]);
    }
    // 计算k的中介数
    // print_vector(intermediary);
    calculate_increase_number(intermediary,k,increase);
    // print_vector(intermediary);
    // 由中介数找到排列
    if(!increase){
        for(int i=0;2*i<n-1;i++)
            swap(intermediary[i],intermediary[n-2-i]);
    }
    vector<bool> vis(n,true);//表示该位置没有元素
    for(int i=n;i>1;i--){
        int j=n-1;
        while(j>=0&&(intermediary[n-i]!=0)){
            if(vis[j])intermediary[n-i]--;
            j--;
        }
        while(j>=0&&!vis[j])j--;
        v[j] = i;
        vis[j] = false;
    }
    for(int i=0;i<v.size();i++)if(vis[i])v[i]=1;
}

// 算法5：邻位对换法
// 计算一个全排列的之后第k个排列，k可正可负
void permutation_ringing(vector<int>& v,int k){
    // 计算邻位对换法中介数（箭头后面小于该数的数字个数）
    // 首先判断箭头方向，求中介数(b2b3b4……)
    int n = v.size();
    vector<bool> arrow(n-1,true); // 元素箭头方向，true表示箭头向左，b2的箭头一定向左，所以为true
    vector<int> intermediary(n-1); // 中介数（箭头后面小于该数的数字个数）
    for(int b=2;b<=n;b++){
        if(b%2!=0){
            arrow[b-2] = (intermediary[b-3]%2==0);
        }else if(b!=2){
            arrow[b-2] = ((intermediary[b-3]+intermediary[b-4])%2==0);
        }
        int c=0;
        if(arrow[b-2]){
            for(int j=n-1;v[j]!=b;j--)if(v[j]<b)c++;
        }else{
            for(int j=0;v[j]!=b;j++)if(v[j]<b)c++;
        }
        intermediary[b-2]=c;
    }
    // 计算第k个的中介数
    // print_vector(intermediary);
    calculate_increase_number(intermediary,k,false);
    // print_vector(intermediary);
    // 由中介数找到箭头方向和排列
    vector<bool> vis(n,true);//表示该位置没有元素
    for(int b=n;b>=2;b--){
        if(b%2!=0){
            arrow[b-2] = (intermediary[b-3]%2==0);
        }else if(b!=2){
            arrow[b-2] = ((intermediary[b-3]+intermediary[b-4])%2==0);
        }
        int j; //放置b元素的位置
        if(arrow[b-2]){ // 箭头朝左
            for(j=n-1;intermediary[b-2]!=0;j--)
                if(vis[j])intermediary[b-2]--;
            while(!vis[j])j--;
        }else{
            for(j=0;intermediary[b-2]!=0;j++)
                if(vis[j])intermediary[b-2]--;
            while(!vis[j])j++;
        }
        v[j] = b;
        vis[j] = false;
    }
    for(int i=0;i<v.size();i++)if(vis[i])v[i]=1;
}

int main(){
    int n=8;
    vector<int> v(n);
    
    int cnt=1;
    clock_t start,finish;
    for(int i=1;i<=n;i++)cnt*=i;
    printf("字典序法\n");
    for(int i=0;i<n;i++)v[i]=i+1;
    print_vector(v);
    start = clock();
    for(int i=0;i<cnt-1;i++)
        permutation_dictorder(v,1);
    finish = clock();
    printf("运行时间：%.2f\n",1000*(float)(finish-start)/CLOCKS_PER_SEC);
    print_vector(v);
    printf("递增进位制法\n");
    for(int i=0;i<n;i++)v[i]=i+1;
    print_vector(v);
    start = clock();
    for(int i=0;i<cnt-1;i++){
        permutation_increase(v,1);
    }
        
        
    finish = clock();
    print_vector(v);
    printf("运行时间：%.2f\n",1000*(float)(finish-start)/CLOCKS_PER_SEC);
    printf("递减进位制法\n");
    for(int i=0;i<n;i++)v[i]=i+1;
    print_vector(v);
    start = clock();
    for(int i=0;i<cnt-1;i++)
        permutation_increase(v,1,false);
    finish = clock();
    print_vector(v);
    printf("运行时间：%.2f\n",1000*(float)(finish-start)/CLOCKS_PER_SEC);
    printf("邻位对换法\n");
    for(int i=0;i<n;i++)v[i]=i+1;
    print_vector(v);
    start = clock();
    for(int i=0;i<cnt-1;i++)
        permutation_ringing(v,1);
    finish = clock();
    print_vector(v);
    printf("运行时间：%.2f\n",1000*(float)(finish-start)/CLOCKS_PER_SEC);
    return 0;
}