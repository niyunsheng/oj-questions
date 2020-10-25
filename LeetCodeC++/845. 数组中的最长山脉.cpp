/*双指针算法

*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i=1,c=0;
        while(i<A.size()){
            while(i<A.size()&&A[i]<=A[i-1])i++;
            int j=i;
            while(j+1<A.size()&&A[j]<A[j+1])j++;
            int k=j;
            while(k+1<A.size()&&A[k]>A[k+1])k++;
            if(j==k){
                i=k+1;
            }else{
                c = max(k-i+2,c);
                // printf("%d %d %d\n",i,j,k);
                i=max(k+1,i+1);
            }
            
        }
        return c;
    }
};