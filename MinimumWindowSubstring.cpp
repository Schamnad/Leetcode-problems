// 76. Minimum Window Substring
//
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
//
// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".
//
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string s, string t) {
    	if (s.empty() || t.empty())
        {
            return "";
        }

    	bool charSet[128]={false};
    	int require[128] = {0};
    	int count = t.size();

    	for(int i = 0 ; i < count ; i++){
    		require[t[i]]++;
    		charSet[t[i]] = true;
    		//cout << t[i];
    	}

    	int i = -1;
    	int j =0;
    	int minLen = INT_MAX;
    	int minIdx = 0;
    	int inCount = s.length();

    	while((i < inCount) && (j < inCount)){
    		//cout << "here";
    		if(count){
    			i++;
    			require[s[i]]--;
    			//cout << require[s[i]] << " " << charSet[s[i]];
    			if((charSet[s[i]]) && (require[s[i]]>=0)){
    				count--;
    				//cout << count;
    			}
    		}else{
    			cout << " here";
    			if(minLen > i-j+1){
    				minIdx = j;
    				minLen = i-j+1;
    			}

    			require[s[j]]++;
    			if(charSet[s[j]] && require[s[j]] > 0)
    				count++;
    			j++;
    		}
    	}

    	if(minLen == INT_MAX){
    		return "";
    	}
    	return s.substr(minIdx,minLen);
    }
};
