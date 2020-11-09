// 用异或运算交换两数的位置

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
};