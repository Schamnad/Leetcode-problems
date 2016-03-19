// 97. Interleaving String
//
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        if(m+n != s3.length())
        	return false;

        vector<bool>dp(n+1,false);

        dp[0] = true;
        for(int i =1 ; i <=n ; i++){
            dp[i] = (dp[i-1] && s2[i-1] == s3[i-1]);
        }

        for(int i = 1; i <=m; i++){
        	dp[0] = (s1.substr(0,i) == s3.substr(0,i));

        	for(int j = 1; j <=n;j++){
        		dp[j] = (dp[j] && s1[i-1] == s3[i+j-1] || dp[j-1] && s2[j-1] == s3[i+j-1]);
        	}
        }

        return dp[n];
    }
};
