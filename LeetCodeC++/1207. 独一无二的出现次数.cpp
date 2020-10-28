class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int bucket[2005]={0};
        int shift = 1000;
        for(int i=0;i<arr.size();i++)
            bucket[shift+arr[i]] += 1;
        sort(bucket,bucket+2005);
        int i=0;
        while(bucket[i]==0)i++;
        for(;i<2005-1;i++)
            if(bucket[i]==bucket[i+1])return false;
        return true;
    }
};