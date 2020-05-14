/**
 * @Date:   2018-07-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-31
 */
 #include<iostream>
 #include<queue>
 using namespace std;
 /*
 本题思路:用数组建立队列和树
 */

 int *p,*lchild,*rchild;
 int* inorder;
 int inrank;
 void inorderTravel(int root){
     if(root==-1)return;
     inorderTravel(lchild[root]);
     inorder[inrank++]=root;
     inorderTravel(rchild[root]);
 }
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n;
     scanf("%d",&n);
     p=new int[n];for(int i=0;i<n;i++)p[i]=i;
     lchild=new int[n];
     rchild=new int[n];
     char a[2],b[2];
     for(int i=0;i<n;i++){
         scanf("%s %s",a,b);
         if(*a=='-')rchild[i]=-1;
         else {rchild[i]=*a-'0';p[rchild[i]]=i;}
         if(*b=='-')lchild[i]=-1;
         else {lchild[i]=*b-'0';p[lchild[i]]=i;}
     }
     int root=0;
     while(p[root]!=root)root=p[root];
     int levelorder[n],lo=0,hi=1;//建一个队列
     int cur=root;
     levelorder[0]=root;
     while(lo<n){
         //队首出队，其左右孩子入队
         cur=levelorder[lo++];
         if(lchild[cur]!=-1)levelorder[hi++]=lchild[cur];
         if(rchild[cur]!=-1)levelorder[hi++]=rchild[cur];
     }
     inorder=new int[n];
     inrank=0;
     inorderTravel(root);

     for(int i=0;i<n-1;i++)
         printf("%d ",levelorder[i]);
     printf("%d\n",levelorder[n-1]);
     for(int i=0;i<n-1;i++)
         printf("%d ",inorder[i]);
     printf("%d\n",inorder[n-1]);
     return 0;
 }
