/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-22
 */
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ans,ans1;
		int n1=nums1.size(),n2=nums2.size();
		int n=n1+n2;
		int i=0,j=0;
		if(n%2){
			while(i+j<=n/2){
				while(i+j<=n/2&&(j==n2||(i<n1&&nums1[i]<=nums2[j]))){ans=nums1[i++];}
				while(i+j<=n/2&&(i==n1||(j<n2&&nums2[j]<=nums1[i]))){ans=nums2[j++];}
			}
			return ans;
		}else{
			while(i+j<=n/2-1){
				while(i+j<=n/2-1&&(j==n2||(i<n1&&nums1[i]<=nums2[j]))){ans=nums1[i++];}
				while(i+j<=n/2-1&&(i==n1||(j<n2&&nums2[j]<=nums1[i]))){ans=nums2[j++];}
			}
			if(i+j<=n/2&&(j==n2||(i<n1&&nums1[i]<=nums2[j]))){ans1=nums1[i++];}
			if(i+j<=n/2&&(i==n1||(j<n2&&nums2[j]<=nums1[i]))){ans1=nums2[j++];}
			return (double)(ans+ans1)/2;
		}
	}
};
//答案写的更加简洁一点
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3;
		int p1 = 0;
		int p2 = 0;
		int p3 = 0;
		int length1 = nums1.size();
		int length2 = nums2.size();
		double anwser;
		while (p1 < length1 || p2 < length2) {
			if(p1<length1&&p2<length2)
			{
				if (nums1[p1] <= nums2[p2])
				{
					nums3.push_back(nums1[p1]);
					p1++;
					p3++;
				}
				else {
					nums3.push_back(nums2[p2]);
					p2++;
					p3++;
				}
			}
			else if (p1 >= length1)
			{
				nums3.push_back(nums2[p2]);
				p2++;
				p3++;
			}
			else
			{
				nums3.push_back(nums1[p1]);
				p1++;
				p3++;
			}
		}
		if (nums3.size() % 2 == 0) {
			anwser = nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2];
			anwser = anwser / 2;
			return anwser;
		}
		else {
			anwser = nums3[(nums3.size() + 1) / 2 - 1];
			return anwser;
		}
	}
};
