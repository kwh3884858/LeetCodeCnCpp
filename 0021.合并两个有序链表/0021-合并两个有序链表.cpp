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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = new ListNode(-1);
        ListNode* left = list1;
        ListNode* right = list2;
        if(left == nullptr && right == nullptr) return nullptr;
        ListNode* current = root;

        while(left != nullptr && right != nullptr)
        {
            if(left->val < right->val)
            {
                current->next = left;
                current = current->next;
                left = left->next;
            }
            else
            {
                current->next = right;
                current = current->next;
                right = right->next;
            }
        }

        if(left)
        {
            while(left != nullptr)
            {
                current->next = left;
                current = current->next;
                left = left->next;
            }
        }
        if(right)
        {
            while(right != nullptr)
            {
                current->next = right;
                current = current->next;
                right = right->next;
            }
        }
        return root->next;
    }
};