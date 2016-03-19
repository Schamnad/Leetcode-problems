// 135. Candy
//
// There are N children standing in a line. Each child is assigned a rating value.
//
// You are giving candies to these children subjected to the following requirements:
//
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size ==0)
            return 0;
        std::vector<int> left(size,1);
        std::vector<int> right(size,1);

        for(int i = 1; i < size; i++){
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }


        for(int i = size-2; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
        }

        int res = 0;

        for(int i = 0; i < size; i++){
            res += max(left[i],right[i]);
        }

        return res;
    }
};
