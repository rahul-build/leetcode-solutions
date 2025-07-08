#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *createLinkedList(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = createLinkedList(arr, index + 1, size);
    return temp;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *Head = createLinkedList(arr, 0, 5);
    printList(Head);
    return 0;
}
// | Approach | Time Complexity | Space Complexity |
//     | -- -- -- -- -| -- -- -- -- -- -- -- -| -- -- -- -- -- -- -- -- -|
//     | Recursive | O(n) | O(n)(call stack) |
//     | Iterative | O(n) | O(1) |
// If asked in an interview :
// “What’s the drawback of your recursive linked list function ?”

//     "It uses O(n) stack space, which can lead to stack overflow for large inputs. An iterative solution avoids this and is preferred in production systems."