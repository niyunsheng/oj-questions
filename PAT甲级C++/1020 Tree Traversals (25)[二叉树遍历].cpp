/**
 * @Date:   2018-07-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-31
 */
 #include<iostream>
 #include<queue>
 using namespace std;
 /*
 本题思路：虽然之前做过，但是还是做了一个小时左右，还是不够熟悉啊
 主要是递归函数的写法，因为最后要输出层次遍历的结果
 所以，没有去构造二叉树，因为这样还学要用队列写一个层次遍历的函数，虽然也没几行
 本题采用数组去存储元素的层次，然后循环判断层次输出，这样的效率应该不是很高
 所以，还是用构造二叉树节点，用队列实现二叉树层次遍历的方法更加通用！
 */
 int n;
 int* postorder;
 int* inorder;
 int* levelorder;
 int* level;
 int _find(int& e,int* inorder,int inlo,int inhi){
     for(int i=inlo;i<inhi;i++)
         if(e==inorder[i])return i;
     return 0;
 }
 void fun(int postlo,int posthi,int inlo,int inhi,int r){
     if(postlo>=posthi)return;//递归基

     int inmi=_find(postorder[posthi-1],inorder,inlo,inhi);
     level[inmi]=r;
     fun(postlo,postlo+inmi-inlo,inlo,inmi,r+1);
     fun(posthi-inhi+inmi,posthi-1,inmi+1,inhi,r+1);
 }
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     scanf("%d",&n);
     //这里要注意，虽然把这四个指针定义为了全局指针，但是分配内存的时候必须在n的值确定之后!
     postorder=new int[n];
     inorder=new int[n];
     levelorder=new int[n];
     level=new int[n];
     for(int i=0;i<n;i++)scanf("%d",postorder+i);
     for(int i=0;i<n;i++)scanf("%d",inorder+i);
     int r=1;
     fun(0,n,0,n,r);
     int i=0;
     r=1;
     while(i<n){
         for(int j=0;i<n&&j<n;j++)
             if(level[j]==r){levelorder[i]=inorder[j];i++;}
         r++;
     }
     for(int i=0;i<n-1;i++)
         printf("%d ",levelorder[i]);
     printf("%d",levelorder[n-1]);
     return 0;
 }
