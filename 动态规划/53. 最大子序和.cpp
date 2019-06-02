/**
题目描述 : 
给定一个整数数组 `nums` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
**示例:**
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
找到一个最优的子数组

执行用时 : 8 ms, 在Maximum Subarray的C++提交中击败了98.12% 的用户
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int len = nums.size();
        if(!len) return 0;
        //找到以该点为结尾的子序列的最大和
        //整个序列的最大和就是子序列最大的和数组的最大值
		// init		
        int max_ending_here = nums[0];
        int max_so_far = nums[0];

        for(int i=1; i<len;i++){
        	int curt_value = nums[i];
        	int sum = curt_value + max_ending_here;
        	max_ending_here = sum > curt_value? sum : curt_value;
        	max_so_far = max_ending_here > max_so_far ? max_ending_here : max_so_far;
        }
        return max_so_far;   
    }
};