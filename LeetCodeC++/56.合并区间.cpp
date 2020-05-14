/*
答案的代码就是如此简洁，12ms，而自己的代码用了72ms。
原因在于：对vector进行删除操作，这耗费了大量时间
教训：自己编写的quicksort虽然也能使用，但是因为不知道如何在已经定义好的结构体中加入大小判断，就不会用stl的sort函数
*/
//自定义类型排序，用STL中的sort函数，有两种方法
//1是在自定义类型中重载操作符<
//2是自定义比较函数
struct Point{
	int x;
	int y;
	Point(int a=0,int b=0):x(a),y(b){}
	bool operator<(Point& tmp){return x<tmp.x;}//即重载操作符，此时用sort(a.begin(),a.end());
};
bool comp(Point& a,Point& b){return a.x<b.x;}//自定义比较函数，此时用sort(a.begin(),a.end(),comp);
int main(){
	vector<Point> a(5);
	for(int i=0;i<5;i++){a[i].x=i;a[i].y=5-i;}
	sort(a.begin(),a.end());
	for(int i=0;i<5;i++)cout<<a[i].x<<endl;
	return 0;
}
//另外，善于利用std命名空间中的基本函数，如max，swap等（查资料补全）先上答案代码:
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
    vector<Interval> merge(vector<Interval>& m) {
        vector<Interval> ret;

        int len = m.size();
        if (len == 0)
        {
            return ret;
        }

        sort(m.begin(), m.end(), [](Interval &a, Interval& b) {
           return a.start < b.start;
        });

        Interval& last = m[0];

        for (int i = 1; i < len; i++)
        {
            if (m[i].start >= last.start && m[i].start <= last.end)
            {
                // merge
                m[i].start = last.start;
                m[i].end = max(last.end, m[i].end);

            }
            else
            {
                ret.push_back(last);
            }

            last = m[i];
        }

        ret.push_back(last);

        return ret;
    }
};

//在来自己渣代码
int partition(vector<Interval>& str,int lo,int hi){//语义规定：对[lo,hi]两头闭区间进行就地重拍
	int i=lo-1,j=lo;//i表示第一个比尾数大的数，j表示最后一个比尾数大的数
	while(j<hi){
		if(str[j].start<=str[hi].start){
			i++;
			if(j>i)swap(str[i].start,str[j].start);swap(str[i].end,str[j].end);
            j++;
		}else{
            j++;
        }
	}
	swap(str[i+1].start,str[hi].start);swap(str[i+1].end,str[hi].end);
	return i+1;
}
void quicksort(vector<Interval>& str,int lo,int hi){
	if(lo>=hi)return;
	int q=partition(str,lo,hi);
	quicksort(str,lo,q-1);
	quicksort(str,q+1,hi);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    if(!intervals.empty()){


        quicksort(intervals,0,intervals.size()-1);
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i].end>=intervals[i+1].start){
                intervals[i].end=max(intervals[i].end,intervals[i+1].end);
                intervals.erase(intervals.begin()+i+1);
                i--;
            }
        }
    }
        return intervals;
    }
};
