/*
* Module 6 Assignment
* 
* Diana Guerrero
* Professor Zhao
* BCS 370
* 10/26/20
* 
* Partner: Patrick Adams
*/

#include <iostream>
using std::cout;


template <typename T>
struct Node
{
    T data, first, last;
    Node* link;

    // This constructor combines both default and parameterized constructors
    Node(int data = 0, Node* p = nullptr)
    {
        this->data = data;
        link = p;
    }
};

template <typename T>
class linked_list
{
    Node<T>* head, * current, * last;
    int count;

    public:

    // Default Constructor
    linked_list() 
    {
        // Head Pointer
        head = nullptr;
        // Acts as the Tail of the List
        current = nullptr;
    }

    // Deconstructor
    ~linked_list() 
    {
        current = head;
        // Loop Stops When Both Current and Head are NULL
        while (current != nullptr) 
        {
            head = head->link;
            delete current;
            current = head;
        }
    }

    void addLast(int n) 
        // Add a Node at the End of the List
    {
        if (head == nullptr) 
        {
            head = new Node<T>(n);
            current = head;
        }

        else 
        {
            if (current->link != nullptr)
                current = current->link;
            current->link = new Node<T>(n);
            current = current->link;
        }
    }

    // Display All Nodes in the List
    void print() 
    { 
        Node<T>* tmp = head;
        while (tmp != nullptr) 
        {
            cout << tmp->data << "\n";
            tmp = tmp->link;
        }
    }

    // Adds a Node with Data at the Beginning of the List
    void addFirst(T data) 
    {
        // Pointer to Create the New Node
        Node<T>* newNode; 

        // Creates New node
        newNode = new Node<T>; 

        // Store the Data in the Node
        newNode->info = data; 

        // Insert newNode Before Head
        newNode->link = head; 

        // Nake First Point to the Actual First Node
        head = newNode; 

        // Increment Count by 1
        count++; 

        // If List is Empty, newNode is also the Last Node
        if (current == nullptr) 
            current = newNode;
    }

    // Removes the First Node of the List
    void pop() 
    { 
        current = head;
        head = head->link;
        count--;

        // If the List Only has One Node
        if (head == nullptr)
            current = nullptr;

        delete current;
    }

    // Returns T or F If a Node Contains the Data Exists in the List
    bool contatins(T data) 
    { 
        // Pointer to Traverse the List
        Node<T>* search; 
        bool found = false;
        // Set Pointer to Point to the First Node in the List
        search = head; 

        // Search the List
        while (search != nullptr && !found)
            if (search->info == data) 
                // Data is Found
                found = true;
    }

    // Updates the oldData of a Node in the List with newData
    void update(T oldData, T newData) 
    { 
        current = head;
        while (current->next != nullptr) 
        {
            if (current->data == oldData) 
            {
                current->data == newData;
                cout << oldData << " was replaced by " << newData;
            }
        }
    }

    int size() { // Returns the number of nodes int the list
        return count;
    }

    void remove(T data) 
    {
        // Pointer to Traverse List
        Node<T>* current; 
        bool found;
        // Pointer to Follow Bool Found
        Node<T>* followCurrent; 

        // If List is Empty
        if (head == nullptr) 
            cout << "Empty list." << std::endl;

        else 
        {
            if (head->info == data) 
            {
                current = head;
                head = head->link;
                count--;

                // If List Only Has One Node
                if (head == nullptr) 
                    last == nullptr;

                delete this->current;

            }

            // Search the List for the Node with the Given Info
            else { 
                found = false;
                followCurrent = head;
                current = head->link;

                while (current != nullptr && !found) 
                {
                    if (current->info != data) 
                    {
                        followCurrent = current;
                        current = current->link;
                    }
                    else found = true;
                } 

                // If Found, Delete Node
                if (found) 
                {
                    followCurrent->link = current->link;
                    count--;

                // Node to be Deleted was Last
                    if (last == current) 
                        last == followCurrent;
                    delete current;
                }
                else
                    cout << "The item is not in the list" << std::endl;
            } 
        } 
    }


};

int main() 
{
    linked_list<int> a;
    a.addLast(1);
    a.addLast(2);

    a.print();

    return 0;
}