/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//> 思路：先用map将输入的点去重（这里要自定义比较函数），然后对于每一个点，遍历其后面的每一个点，记录在一条直线上的点的数目，在记录的过程中维护最大值。
//> 开始时在map的自定义比较函数上面卡了壳，为此还得到codeblock这种IDE调试才看的出来，用VS的话比较函数少了const照样能运行
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class cmp{
public:
    //特别注意map的比较函数的写法，这里的const不能去掉
    bool operator()(const Point& a,const Point& b)const{
        if(a.x!=b.x)
            return a.x<b.x;
        else
            return a.y<b.y;
    }
};

class Solution {
public:
    //遍历，用unordered_map存个数，只有这样O(n^2)的算法了，对于每个点，求其所形成的的直线的点数最大值

    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    int maxPoints(vector<Point>& points) {
        int maxn=1,r;
        int n=points.size();
        if(n==0)return 0;
        map<Point,int,cmp> pointsmap;//去重
        for(int i=0;i<n;i++){
            if(pointsmap.count(points[i])==0)pointsmap[points[i]]=1;
            else pointsmap[points[i]]++;
        }
        map<pair<int,int>,int> mmap;//记录该定点开始的斜率为pair的直线的数目
        for(auto it_i=pointsmap.begin();it_i!=pointsmap.end();it_i++){
            mmap.clear();
            if(it_i->second>maxn)maxn=it_i->second;
            int a,b;
            auto it_j=it_i;
            it_j++;

            for(;it_j!=pointsmap.end();it_j++){
                a=it_j->first.x-it_i->first.x,b=it_j->first.y-it_i->first.y;
                if(a==0)b=1;
                else if(b==0)a=1;
                else {
                    int c=gcd(a,b);
                    a/=c;b/=c;
                }

                if(mmap.count(make_pair(a,b))==0){
                    mmap[make_pair(a,b)]=it_j->second+it_i->second;
                    if(maxn<mmap[make_pair(a,b)])maxn=mmap[make_pair(a,b)];
                }else{
                    mmap[make_pair(a,b)]+=it_j->second;
                    if(mmap[make_pair(a,b)]>maxn)maxn=mmap[make_pair(a,b)];
                }
                //printf("a=%d b=%d %d\n",a,b,mmap[make_pair(a,b)]);
            }
        }
        return maxn;
    }
};
