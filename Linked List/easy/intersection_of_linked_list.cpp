/*
Question - https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/

Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Your Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

*/

/*
Approach - Store all the elements of the list into a hashmap, iterate list 1 if any element of list 1 is present in map, put it into intersection list.
*/

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *intersection = nullptr;
    Node *intersectionTail = nullptr;
    unordered_map<int, bool> check;

    Node *curr = head2;

    while (curr != nullptr)
    {
        check[curr->data] = true;
        curr = curr->next;
    }

    curr = head1;

    while (curr != nullptr)
    {
        if (check[curr->data] == true)
        {
            insertAtTail(intersection, intersectionTail, curr->data);
        }
        curr = curr->next;
    }

    return intersection;
}