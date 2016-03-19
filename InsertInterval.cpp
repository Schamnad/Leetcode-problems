// 57. Insert Interval
//
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> result;
        int i;

        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }

        if(newInterval.end < intervals[0].start){
        	result.push_back(newInterval);

        	for(int i =0 ; i<intervals.size();i++){
        	    result.push_back(intervals[i]);
        	}

        	return result;
        }

        for(i =0 ; i<intervals.size(); i++){
        	result.push_back(intervals[i]);
        	if(intervals[i].end >= newInterval.start){
        		break;
        	}
        }

        if(i == intervals.size()){
	 		result.push_back(newInterval);
        	return result;
        }

        /*else if(result.back().end < newInterval.end){
        	Interval temp(min(result.back().start,newInterval.start),max(result.back().end,newInterval.end));
        	result.pop_back();
        	result.push_back(temp);
        }*/
        if(result.back().start > newInterval.end){
            Interval temp(result.back().start,result.back().end);
        	result.pop_back();
        	result.push_back(newInterval);
        	result.push_back(temp);
        }else{
        	Interval temp(min(result.back().start,newInterval.start),max(result.back().end,newInterval.end));
        	result.pop_back();
        	result.push_back(temp);
        }

        for(int j = i+1; j<intervals.size();j++){
        	if(result.back().end >= intervals[j].start){
        		Interval temp(result.back().start,max(result.back().end,intervals[j].end));
        		result.pop_back();
        		result.push_back(temp);
        	}else{
        		result.push_back(intervals[j]);
        	}
        }

        return result;
    }
};
