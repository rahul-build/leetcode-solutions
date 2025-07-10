
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

// Recursive function to create linked list
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

// Function to print the list
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
