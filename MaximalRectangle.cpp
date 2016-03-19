// 85. Maximal Rectangle
//
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        	return 0;

        int area = 0;

        std::vector<vector<int> > ones(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int i =0; i < matrix.size();i++){
        	ones[i][0] = int(matrix[i][0] - '0');

        	for(int j = 1; j < matrix[0].size(); j++){
        		if(matrix[i][j] == '0')
        			ones[i][j] = 0;
        		else
        			ones[i][j] = 1 + ones[i][j-1];
        	}
        }


        for(int i = 0 ; i < matrix.size(); i++){
        	for(int j = 0; j < matrix[0].size();j++){
        		if(ones[i][j] != 0){
        			int h = i-1;
        			int minLen = ones[i][j];
        			int temp = ones[i][j];
        			while( h >=0){
        				if(ones[h][j] == 0)
        					break;
        				else{
        					if(ones[h][j] < minLen)
        						minLen = ones[h][j];
        					if(temp < (minLen*(i-h+1)))
        						temp = minLen*(i-h+1);
        				}
        				h--;
        			}
        			//cout << "here " << temp << " " << i << "\n";
        			area = max(area,temp);
        		}
        	}
        }

        return area;
    }
};
