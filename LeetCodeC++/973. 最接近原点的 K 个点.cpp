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

// 方法2：结构体加friend函数
struct node{
    int rank,norm;
    node(int rank, int norm):rank(rank),norm(norm){}
    friend bool operator<(node a, node b){
        return a.norm > b.norm;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<node> pq;
        for(int i=0;i<points.size();i++){
            node t = node(i,points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            pq.push(t);
        }
        vector<vector<int>> ans;
        for(int i=0;i<K&&!pq.empty();i++){
            node t = pq.top();
            ans.push_back(points[t.rank]);
            pq.pop();
        }
        return ans;
    }
};