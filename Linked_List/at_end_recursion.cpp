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
        return NULL;
    Node *temp = new Node(arr[index]);
    temp->next = createLinkedList(arr, index + 1, size);
    return temp;
}

Node *deleteFirstNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head->next;
    delete head;
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

    Node *head = createLinkedList(arr, 0, 5); // step 1
    head = deleteFirstNode(head);             // step 2
    printList(head);                          // step 3

    return 0;
}
