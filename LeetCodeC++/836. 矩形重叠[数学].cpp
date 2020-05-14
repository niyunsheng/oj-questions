
class Solution {
public:
    bool intersect(int x1,int x2,int x3,int x4){
        if(x1<=x3)return x3<x2;
        else return x1<x4;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return intersect(rec1[0],rec1[2],rec2[0],rec2[2])&&intersect(rec1[1],rec1[3],rec2[1],rec2[3]);
    }
};
//更简便方法：仅一行
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
{
    return max(rec1[0],rec2[0])<min(rec1[2],rec2[2])&&max(rec1[1],rec2[1])<min(rec1[3],rec2[3]);
}
