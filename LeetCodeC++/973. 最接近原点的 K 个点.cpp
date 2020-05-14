//本题考查优先级队列的构造函数，以及自定义cmp函数对象
class cmp {
public:
	bool operator()(vector<int> &a, vector<int> &b)const { return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1]; }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int> >, cmp> pq(points.begin(),points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K && !pq.empty(); i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
