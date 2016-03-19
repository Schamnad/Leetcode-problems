// 32. Longest Valid Parentheses
//
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

class Solution {
public:
    int longestValidParentheses(string s) {
    	if(s.empty()){
    		return 0;
    	}

    	vector<int> longest(s.size(),0);
    	int curMax = 0;

    	for(int i = 1; i <s.size();i++){
    		if(s[i] == '('){
    			longest[i] = 0;
    		}else{
    			if(s[i-1] == '('){
    				longest[i] = longest[i-2] + 2;
    				curMax = max(curMax,longest[i]);
    			}
    			else if(i-longest[i-1] - 1 >= 0 && s[i-longest[i-1] -1] == '('){
    				longest[i] = longest[i-1] + 2 + (i-longest[i-1] -2 !=0 ? longest[i-longest[i-1] - 2]:0);
    				curMax = max(curMax, longest[i]);
    			}
    		}
    	}

    	return curMax;
    }
};
