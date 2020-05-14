/**
 * @Date:   2018-08-26
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-26
 */
//某大神算法
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> mp;
        for(auto &s : A){
            string even, odd;
            for(int i=0;i<s.size();i+=2) even.push_back(s[i]);
            for(int i=1;i<s.size();i+=2) odd.push_back(s[i]);
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            ++mp[even+odd];
        }
        return mp.size();
    }
};
//自己的麻烦方法

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int n=A.size();
        if(n==0)return 0;
        int mmap[4][26],cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                for(int k=0;k<26;k++){mmap[0][k]=0;mmap[1][k]=0;}
                for(int k=0;k<A[i].size();k++){
                    if(k%2)mmap[0][A[i][k]-'a']++;
                    else mmap[1][A[i][k]-'a']++;
                }
                for(int j=i+1;j<n;j++){
                    for(int k=0;k<26;k++){mmap[2][k]=0;mmap[3][k]=0;}
                    for(int k=0;k<A[j].size();k++){
                        if(k%2)mmap[2][A[j][k]-'a']++;
                        else mmap[3][A[j][k]-'a']++;
                    }
                    bool flag=true;
                    for(int k=0;k<26;k++){
                        if(mmap[0][k]!=mmap[2][k]||mmap[1][k]!=mmap[3][k]){
                            flag=false;break;
                        }
                    }
                    if(flag)vis[j]=1;
                }
            }
        }
        return cnt;
    }
};
