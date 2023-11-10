class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Find the meeting point of the slow and fast pointers
    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // If the slow and fast pointers meet, there is a cycle
        if (slow == fast) {
            fast = head;  // Move the fast pointer back to the head

            // Move the slow and fast pointers at the same pace until they meet again
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }

            return fast;  // Return the node where the cycle begins
        }
    }

    return nullptr;  // Return null if there is no cycle
    }
};