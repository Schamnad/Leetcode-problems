// 212. Word Search II
//
// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
// For example,
// Given words = ["oath","pea","eat","rain"] and board =
//
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].

class TrieNode{
	public:
		int val;
		TrieNode * children[26];
		TrieNode(){
			val = 0;

			for(int i=0 ; i < 26; i++){
				children[i] = NULL;
			}
		}
};

class Trie{
private:
	TrieNode* root;
	int count;

public:
	Trie(){
		root = new TrieNode();
		count = 0;
	}

	void insert(string s){
		TrieNode* p = root;

		for(int i=0 ; i < s.size();i++){
			int temp = s[i] - 'a';

			if(!p->children[temp])
				p->children[temp] = new TrieNode();

			p = p->children[temp];
		}
		count++;
		p->val = count;
	}

	bool search(string s){
		TrieNode* p = root;
		int len = s.size();

		for(int i = 0; i < len;i++){
			int temp = s[i] - 'a';

			if(!p->children[temp])
				return false;

			p = p->children[temp];
		}

		if(p->val != 0){
			p->val = 0;
			return true;
		}
		else
			return false;
	}

	bool startsWith(string s){
		TrieNode* p = root;
		int len = s.size();

		for(int i =0; i < len;i++){
			int temp = s[i] - 'a';

			if(!p->children[temp])
				return false;

			p = p->children[temp];
		}
		return true;
	}
};



class Solution {
public:
	void dfs(vector<vector<char>>& board, vector<string>& result, string s, int i, int j, Trie &trie){
		if(i >= board.size() || i < 0 || j >= board[0].size() || j <0)
			return;

		if(board[i][j] == ' ')
			return;

		s += board[i][j];

		if(!trie.startsWith(s))
			return;

		if(trie.search(s))
			result.push_back(s);

		char temp = board[i][j];
		board[i][j] = ' ';
		dfs(board,result,s,i+1,j,trie);
		dfs(board,result,s,i-1,j,trie);
		dfs(board,result,s,i,j+1,trie);
		dfs(board,result,s,i,j-1,trie);
		board[i][j] = temp;
	}


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        vector<string> result;

        for(auto str: words){
        	trie.insert(str);
        }



        int m = board.size();
        int n = board[0].size();
        for(int i=0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		dfs(board,result,"",i,j,trie);
        	}
        }
        return result;
    }
};
