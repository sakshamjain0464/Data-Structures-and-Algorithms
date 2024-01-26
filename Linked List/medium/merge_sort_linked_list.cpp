/*
https://www.geeksforgeeks.org/problems/sort-a-linked-list/1?page=2&category=Linked%20List&sortBy=submissions
Question:
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.

*/

/*
Approach:
1.) Divide the list into two halves recursively.
2.) Merge Both lists.
*/

void insertAtTail(Node *&head, Node *&tail, Node *&dataNode)
{ // For inserting the node to the merged list
    dataNode->next = nullptr;
    if (head == nullptr)
    {
        head = dataNode;
        tail = dataNode;
    }
    else
    {
        tail->next = dataNode;
        tail = tail->next;
    }
}

Node *findMid(Node *head)
{ // Find Mid
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *fast = head->next;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{ // Merge two sorted lists
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }

    Node *merged = nullptr;
    Node *mergedTail = nullptr;

    while (left != nullptr && right != nullptr)
    {
        if (left->data <= right->data)
        {
            Node *next = left->next;
            insertAtTail(merged, mergedTail, left);
            left = next;
        }
        else
        {
            Node *next = right->next;
            insertAtTail(merged, mergedTail, right);
            right = next;
        }
    }

    if (left != nullptr)
    {
        mergedTail->next = left;
    }

    if (right != nullptr)
    {
        mergedTail->next = right;
    }

    return merged;
}

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    { // Recursion
        return head;
    }

    else
    {
        Node *mid = findMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = nullptr;

        left = mergeSort(left);
        right = mergeSort(right);

        Node *merged = merge(left, right);
        return merged;
    }
}