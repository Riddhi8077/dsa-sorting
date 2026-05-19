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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kthNode = getKthNode(groupPrev, k);
            if (kthNode == nullptr) {
                break; 
            }

            ListNode* nextGroup = kthNode->next;
            ListNode* groupStart = groupPrev->next;
            
            kthNode->next = nullptr;

            groupPrev->next = reverseList(groupStart);
            groupStart->next = nextGroup;

            groupPrev = groupStart;
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
