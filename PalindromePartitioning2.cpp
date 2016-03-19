// 132. Palindrome Partitioning II
//
// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        vector<vector<bool> > dp(size, vector<bool>(size,false));

            for(int i =s.size()-1; i>=0 ; i--){
                for(int j=i; j < size; j++){
                    if(s[i] == s[j] && (j-i<2 || dp[i+1][j-1])){
                        dp[i][j] = true;
                    }
                }
            }

        vector<int> Palin(size,0);


        for(int i = 0; i < size; i++){
            int count = size;
            if(dp[0][i]){
                Palin[i] = 0;
            }else{
                for(int j = 0; j < i;j++){
                    if(dp[j+1][i]){
                        count = min(count,Palin[j]+1);
                    }
                }
                Palin[i] = count;
            }
        }
        return Palin[size-1];
    }
};
