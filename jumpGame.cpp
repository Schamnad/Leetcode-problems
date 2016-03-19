// 45. Jump Game II
//
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// For example:
// Given array A = [2,3,1,1,4]
//
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

class Solution {
public:
    int jump(vector<int>& nums) {
    	if(nums.size() ==0 || nums.size() == 1){
    		return 0;
    	}

        int curMax = nums[0];
        int AbsoluteMax = nums[0];
        int count = 1;
        int temp = nums.size()-1;

        for(int i = 1; i <=min(temp,AbsoluteMax); i++){
        	curMax = max(curMax, i + nums[i]);

        	if(i == nums.size()-1)
        		return count;

        	if(i == AbsoluteMax){
        		AbsoluteMax = curMax;
        		count++;
        	}
        }

        return 0;
    }
};
