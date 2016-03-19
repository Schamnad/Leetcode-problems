// 84. Largest Rectangle in Histogram
//
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty())
        	return 0;

        stack<int> temp;
        int maxArea = 0;
        int i;

        for( i = 0; i < height.size();i++){
    		while(!temp.empty() && height[i] < height[temp.top()]){
        		int num = temp.top();
        		temp.pop();
        		int rindex = i;
        		int lindex = 0;
        		if(!temp.empty())
        			lindex = temp.top()+1;
        		maxArea = max(maxArea,(height[num]*(rindex-lindex)));
    		}
    		temp.push(i);
        }

        cout << "here " << maxArea << " " << i << "\n";
        while(!temp.empty()){
        	int num = temp.top();
        	temp.pop();
        	int lindex = 0;
        	if(!temp.empty())
                lindex = temp.top()+1;
        	maxArea = max(maxArea,(height[num]*(i-lindex)));
        }

        return maxArea;
    }
};
