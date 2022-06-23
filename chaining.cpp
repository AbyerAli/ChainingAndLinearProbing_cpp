#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class LinkedList
{
    node *head;
    node *tail;

    void setHead(node *head)
    {
        this->head = head;
    }
    void setTail(node *tail)
    {
        this->tail = tail;
    }
    bool isEmpty()
    {
        return head == NULL;
    }

public:
    LinkedList()
    {
        setHead(NULL);
        setTail(NULL);
    }
    node *getHead()
    {
        return head;
    }
    node *getTail()
    {
        return this->tail;
    }
    void addOnTail(int data)
    {
        node *newNode = new node(data);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            getTail()->next = newNode;
            setTail(newNode);
        }
    }
    void addOnHead(int data)
    {
        node *newNode = new node(data);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            if (getHead()->next == NULL)
            {
                setTail(newNode);
            }
            newNode->next = getHead()->next;
            getHead()->next = newNode;
        }
    }

    void display()
    {
        node *tempNode = getHead();
        while (tempNode != NULL)
        {
            cout << tempNode->data << endl;
            tempNode = tempNode->next;
        }
    }
};

// [1,23,34,44,55]

class Chaining{
    const int size = 10;
    LinkedList arr[10];
    unsigned int hashingFunc(int key){
        return key % size;
    }

public:
    void insertData(int data){
        int index = hashingFunc(data);
        arr[index].addOnTail(data);
    }
    void print(){
        for (int i = 0; i < size; i++)
        {
            arr[i].display();
            cout << "\n================================\n";
        }
    }
};

int main()
{
    Chaining obj;
    obj.insertData(13);
    obj.insertData(14);
    obj.insertData(15);
    obj.insertData(16);
    obj.insertData(17);
    obj.insertData(18);
    obj.insertData(19);
    obj.insertData(20);
    obj.insertData(30);
    obj.print();
}












