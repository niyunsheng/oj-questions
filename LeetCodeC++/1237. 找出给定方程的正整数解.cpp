/***

自己的解法也是基于二分，本以为会快很多，其实却很慢。和最快的答案不同的地方就在于自己时二维二分，而答案是对每一列分别二分。

***/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> cal(CustomFunction& customfunction, int z,int x1,int y1,int x2,int y2){
        vector<vector<int>> ans;
        if(x1>=x2||y1>=y2)return ans;
        int mx = (x1+x2)/2,my=(y1+y2)/2;
        int t=customfunction.f(mx,my);
        // printf("%d,%d,%d,%d\n",mx,my,t,z);
        if(t>z){
            vector<vector<int>> t1 = cal(customfunction,z,x1,y1,x2,my);
            vector<vector<int>> t2 = cal(customfunction,z,x1,my,mx,y2);
            ans.insert(ans.end(),t1.begin(),t1.end());
            ans.insert(ans.end(),t2.begin(),t2.end());
        }else if(t<z){
            vector<vector<int>> t1 = cal(customfunction,z,mx+1,y1,x2,y2);
            vector<vector<int>> t2 = cal(customfunction,z,x1,my+1,mx+1,y2);
            ans.insert(ans.end(),t1.begin(),t1.end());
            ans.insert(ans.end(),t2.begin(),t2.end());
        }else{
            vector<int> t={mx,my};
            ans.push_back(t);
            
            vector<vector<int>> t1 = cal(customfunction,z,x1,y1,mx,y2);
            vector<vector<int>> t2 = cal(customfunction,z,mx+1,y1,x2,y2);
            vector<vector<int>> t3 = cal(customfunction,z,mx,y1,mx+1,my);
            vector<vector<int>> t4 = cal(customfunction,z,mx,my+1,mx+1,y2);
            ans.insert(ans.end(),t1.begin(),t1.end());
            ans.insert(ans.end(),t2.begin(),t2.end());
            ans.insert(ans.end(),t3.begin(),t3.end());
            ans.insert(ans.end(),t4.begin(),t4.end());
        }
        return ans;
    }
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        return cal(customfunction,z,1,1,1001,1001);
    }
};


///标准答案

int binary_search_range(int low, int high, int val, function<int(int)> func) {
    int ret = low - 1;
    while(low < high) {
        auto x = (low + high) >> 1, y = func(x);
        if(y < val) low = x + 1;
        else if(y > val) high = x;
        else return x;
    }
    return ret;
}
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;
        for(int x = 1; x <= 1000; ++x) {
            auto func = [&](int y) {return customfunction.f(x, y);};
            auto y = binary_search_range(1, 1001, z, func);
            if(y > 0) ret.push_back({x, y});
        }
        
        
        
        return ret;
    }
};