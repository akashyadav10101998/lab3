#include <iostream>
using namespace std;
//defining a class node

class Node{
    public:
    //it has two parts ,data and address 
    int data;
    //make a pointer which has address of next node
    Node * next;
    Node*prev;
    // initially address in node is null
    Node(){
        next = NULL;
        prev=NULL;
    }

};
//making a class linked list which will join the circles
class dll{
    // linking the circles to one another
    public:
//declaring head and tail as pointer
    Node * head;
   

    dll(){
//initially both has value null
        head = NULL;
      
    } 

    //defining a class named Insert which will insert a circle at the end of list
    void insert(int value){
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
//using if else loop so that last value gets inserted at last that is tail which is done by by making head and tail both equal to temp
       if(head == NULL){
            head = temp;
       }
       else{
Node*current=head;
while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
        }
    }
     
// making a class which can insert a circle in between the linked list
    void insertAt(int pos, int value){
        // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
            current->next->prev=current;
        }

        // we have to make a new node that will at last gets inserted between two circles
        Node * temp = new Node;
        temp -> data = value;
        temp->next = current->next;
        current->next = temp;
        temp->prev=current;
        current->next->prev=temp;

    }

    // make a class delet that will delete value of last element
    void delet(){
       Node*last;
        Node * current = head;
        while(current->next !=NULL){
            current = current->next;
        }
        last=current->next;
        current->next = NULL; 
        
         delete last;
    }
//making a class count which will tell total elements in linked list
 int countitems()
{	if(head!=NULL)
	{	int count=1;
		 Node* current=head;
		while(current->next!=NULL)
		{count++;current=current->next;}
		return count;
	}
	else 
	return 0;


};
//making a class named Display
   void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
           
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
 
};
int main(){
    dll l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(576);
    l1.insert(34);
l1.insert(36);
l1.insert(31);
l1.insert(32);
l1.insert(39);
l1.insert(56);
    l1.display();
    l1.delet();
    l1.display();
    cout<<l1.countitems()<<endl;
    l1.insertAt(2,8);
    l1.display();
    return 0;
}

