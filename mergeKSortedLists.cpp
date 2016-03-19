// 23. Merge k Sorted Lists
//
// Merge k sorted linked lists and return it as one sorted list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        if(l1==NULL)return l2;
        else if(l2==NULL)return l1;

        else if(l1->val <= l2->val){
            l1->next = mergeTwo(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwo(l1,l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        int length = lists.size();
        while(length>1){
            for(int i = 0 ; i < length/2; i++){

                lists[i] = mergeTwo(lists[i],lists[length-1-i]);
            }
            length = (length+1)/2;
        }
        return lists[0];
    }
};
