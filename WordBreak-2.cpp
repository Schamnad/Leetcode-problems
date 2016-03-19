// 140. Word Break II
//
// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
//
// Return all such possible sentences.
//
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
//
// A solution is ["cats and dog", "cat sand dog"].

class Solution {
public:
    void fillTable(vector<string> &result,vector<string> &temp, string &s,vector<vector<bool>> &dp,int start){
    	if(start == s.size()){
    		string meh;
    		for(auto it : temp){
    			meh += it;
    		}

    		result.push_back(meh.substr(0,meh.size()-1));
    		return;
    	}

    	for(int i = start; i < s.size(); i++){
    		if(dp[start][i]){
    			temp.push_back(s.substr(start,i-start+1)+' ');
    			fillTable(result,temp,s,dp,i+1);
    			temp.pop_back();
    		}
    	}
    }


    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<bool> > dp(s.size(),vector<bool>(s.size(),false));

        for(int i = 0; i <s.size();i++){
        	for(int j = i; j < s.size();j++){
        		if(wordDict.find(s.substr(i,j-i+1)) != wordDict.end()){
        			dp[i][j] = true;
        		}
        	}
        }

        bool flag =false;
        for (int i=0;i<s.size();i++){
            if (dp[i][s.size()-1]){
                flag = true; break;
            }
        }

        std::vector<string> result;
        if(!flag)
            return result;

        vector<string> temp;
        fillTable(result,temp,s,dp,0);


        return result;
    }
};
