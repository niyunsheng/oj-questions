int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ans;
    ans=(int *)malloc(2*sizeof(int*));
    *returnSize=2;
    int i,j;
    for(i=0;i<numbersSize-1;i++)
        for(j=i+1;j<numbersSize;j++)
            if(*(numbers+i)+*(numbers+j)==target){*ans=i+1,*(ans+1)=j+1;}
    return ans;
}
//这种解法复杂度是O(n2)，不行，可以通过改进变成O(n)
while(j!=i){
	if(numbers[i]+numbers[j]==target){ans[0]=i+1;ans[1]=j+1;break;}
	else if(numbers[i]+numbers[j]>target)j--;
	else i++;
}
