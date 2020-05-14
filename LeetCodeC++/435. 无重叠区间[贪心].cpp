/**
 * @Date:   2018-08-18
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-18
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval& a,Interval& b){
        if(a.start!=b.start)return a.start>b.start;
        else return a.end<b.end;
    }
    //典型贪心问题，按左端点排序，左端点相同的，右端点小的在前面，然后依次选取左端点最大者,即从左到右依次选取，改变左侧临界值，与该临界值相交的边不选,
    //这种策略不对，排序和选择的差错，忽略了包含区间先把大区间选择了，而我们的策略是优先选小区间。
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int right=0x7fffffff;
        int sum=0;
        sort(intervals.begin(),intervals.end(),cmp);
        //for(int i=0;i<intervals.size();i++)cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].end<=right){
                sum++;right=intervals[i].start;
            }
        }
        return intervals.size()-sum;
    }
};
