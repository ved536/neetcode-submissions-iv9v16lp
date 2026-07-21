/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* leftpre = &dummy;
        ListNode* curr = head;
        for( int i = 1; i < left; i++){
            leftpre = leftpre->next;
            curr = curr->next;
        }    
        ListNode* subhead = curr;
        ListNode* prev = nullptr;
        ListNode* nextNode = curr->next;
        for( int i = left; i <= right; i++){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        subhead->next = nextNode;
        leftpre->next = prev;
        return dummy.next; 
    }
};