#include <iostream>
//#include <concepts>
//#include <iomanip>
//#include <ios>
//#include <compare>

using namespace std;


//implementing a linked list in cpp using copy constructor 
class Node
{
    public:
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

class LinkedList
{
    private:
    Node *head=NULL, *tail=NULL;

    public:
        LinkedList()
        {
            head=tail=NULL;
        }

        //introducing the copy constructor 
        LinkedList(const LinkedList& sample)
        {
            if(sample.head==NULL)
            {
                head=tail=NULL;
                return;
            }
            Node* temp=sample.head;

            while(temp!=NULL)
            {
                Node *newNode=new Node(temp->data);
                if(head==NULL)
                {
                    head=newNode;
                    tail=newNode;
                }
                else {
                tail->next = newNode;
                tail = newNode;
            }
             temp = temp->next;
            }
        }
    void insert(int x)
        {
            Node *temp= new Node(x);
            if(head==NULL)
            {
                head=temp;
                return;
            }
            else{
                Node* t=head;
                while( t->next != NULL)
                {
                    t=t->next;
                }
                t->next =temp;
            }
        }

        void print()
        {
            if(head==NULL)
            {
                cout<<" The list is empty"<<endl;
                return;
            }
            Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        }

};

int main()
{
    LinkedList l1,l2,l5;
 
    l1.insert(1);
    l1.insert(9);
    l1.insert(5);
    l1.insert(7);
    l1.insert(456);
    l1.insert(556);
    l1.insert(-67);
    l1.insert(-457);

 
    cout << "linked list l1 are: ";
    l1.print();
 
    // Copying l1 into l2
    l2 = l1;
    cout << "linked list l2 are: ";
    l2.print();
    l5=l2;
    cout << "linked list l5 are: ";
    l5.print();
 
    return 0;
}