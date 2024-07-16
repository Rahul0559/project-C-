#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Define the linked list class
class LinkedList {
private:
    Node* head; // Pointer to the first node in the list

public:
    // Constructor initializes head to NULL
    LinkedList() {
       head =(nullptr) ; 
    } 
        int countnum(){
        Node*temp=head;
        int i = 0;
        while(temp != NULL){
            temp=temp->next;
            i++;
        }
        return i;

    }

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head==NULL) {
            head = newNode; // If the list is empty, update the head
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Update the last node's next to the new node
    }
   void positionInsert(int postin, int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = nullptr;

    Node* temp = head;
    int listLength = countnum();

    if (listLength < postin) {
        cout << "Invalid position" << endl;
    } else {
        int i = 1;
        while (i < postin - 1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }
        if (temp != nullptr) {
            newnode->next = temp->next;
            temp->next = newnode;
        } else {
            cout << "Invalid position" << endl;
        }
    }
}


    // Function to print the elements of the list
    void printList() {
        Node* temp = head;
        int i =1;
        while (temp != NULL) {
            cout<<i<<" element of linkedlist: " << temp->data <<endl;
            temp = temp->next;
            i++;
        }
        cout << endl;
    }
    void counelement(){
        int num = countnum();
        cout<<"element of  linked list is: "<<num<<endl;
    }
   void deletnode(int pos) {
    Node* ptr1;
    Node* ptr2;
    int num = countnum();
    if (num == 0) {
        cout << "list is empty; ";
    } else if (pos == 1) {
        head = head->next;
    }
    if (pos > 0 && pos <= num) {
        ptr1 = head;
        for (int i = 0; i <= pos; i++) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
    }
}
void bubbleSort() {
    if (head == nullptr || head->next == nullptr) {
        cout<<"list empty; "; // No need to sort an empty list or a list with only one element
    }

    bool swapped;
    Node* current;
    Node* tail = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != tail) {
            if (current->data > current->next->data) {
                // Swap data values
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        tail = current; // Mark the last sorted element
    } while (swapped);
}

};

int main() {
    LinkedList list;
    list.insertAtBeginning(98);
    list.insertAtEnd(97);
    list.insertAtEnd(96);
    list.insertAtEnd(95);
    list.insertAtEnd(97);
    list.insertAtEnd(93);
    list.insertAtEnd(90);
    list.positionInsert(4,94);   
    list.positionInsert(1,974);
    list.positionInsert(6,964);   
    list.positionInsert(10,9674);
    list.deletnode(1);
    list.deletnode(5);
    list.bubbleSort();
    cout<< "Elements of the list are: "<<endl;
    list.printList();
    list.counelement();

    return 0;
}
