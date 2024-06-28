#include <bits/stdc++.h>
using namespace std;
class Node 
{
    public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList 
{
    private:
        Node* head;

    public:
        LinkedList() 
        {
            head = nullptr;
        }

        // Function to insert a new node at the end of the list
        void insert(int data) 
        {
            Node* newNode = new Node(data);
            if(head == nullptr){
                head=newNode;   }
            else {
                Node* temp=head;
                while(temp->next != nullptr)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=nullptr;
            }
        }
        // Function to display the linked list
        void display() 
        {
            Node* current=head;
            while(current!=nullptr)
            {
                cout<<current->data<<" -> ";
                current=current->next;
            }
            cout<<"null"<<endl;
        }

        // Count the size
        int listLength()
        {
            Node* current=head;
            int size=0;
            if(current==nullptr)
            {
                cout<<size<<endl;
            }
            while(current!=nullptr)
            {
                size++;
                current=current->next;
            }
            return size;
        }

        //Function to REVERSE a list
        Node* reverseList()
        {
            Node* prev=nullptr;
            Node* current=head;
            while(current!=nullptr)
            {
                Node* fwd=current->next;
                current->next=prev;
                prev=current;
                current=fwd;
            }
            head=prev;
            return head;
        }
        

        // function to insert a node at the given position
        Node* insertAtPosition(int i,int data)
        { 
            Node* temp=head;
            int j=1;
            while(j<i-1)
            {
                temp=temp->next;
                j++;
            }
            Node* newNode=new Node(data);
            newNode->next=temp->next;
            temp->next=newNode;
            return head;
        }


        // function to DELETE the LAST NODE
        Node* deleteLastNode()
        {
            Node* prev=head;
            Node* current=prev->next;
            while(current->next!=nullptr)
            {
                prev=current;
                current=current->next;
            }
            prev->next=nullptr;
            return head;
        }


        // function to DELETE the specified element 
        Node* deleteNodeElement(int x)
        {
            
            int pos=positionToBeDeleted(x);
            int q=1;
            Node* temp=head;
            while(q<pos-1)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
            return head;
        }

        int positionToBeDeleted(int x)
        {
            int i=0;
            Node* temp=head;
            while(temp->next!=nullptr)
            {
                if(temp->data==x)
                temp=temp->next;
                i++;
            }
            return i;        
        }

        // function to reverse in pairs

        Node* reverseInPairs()
        {
            Node* dummy = new Node(0);
            dummy->next=head;
            Node* point=dummy;

            while(point->next!=nullptr && point->next->next!=nullptr)
            {
                Node* a=point->next;
                Node* b=point->next->next;

                // perform swaps
                a->next=b->next;
                b->next=a;

                // for further pairs
                point->next=b;
                point=a;
            }
            head=dummy->next;
            return head;
        }

        

        // Reverse LL in Blocks of k nodes
/*
        Node* ReverseBlockOfKNodes(int k)
        {
Q
        }*/

        Node* getKPlusOneThNode(int k)
        {
            Node* KthNode;
            int i=0;
            if(!head)
            {
                return head;
            }
            for(i=0,KthNode=head;KthNode!=nullptr && (i<k);i++,KthNode=KthNode->next);
            if(i==k && KthNode!=nullptr)
            {
                return KthNode;
            }
            return head->next;
        }
        int hasKNodes(int k)
        {
            int i=0;
            Node* current=head;
            for(i=0; current && (i<k);i++,current=current->next);
            if(i==k)
                return 1;
            return 0;
        }

        // Find Nth node from the end
        Node* NthElementFromEnd(int n)
        {
            Node* behind=head;
            Node* ahead=head;
            for(int i=0;i<n;i++)
            {
                ahead=ahead->next;
            }
            while(ahead!=nullptr)
            {
                behind=behind->next;
                ahead=ahead->next;
            }
            return behind;
        }

        // Delete the Nth node from the end
        Node* DeleteNthFromTheEnd(int n)
        {
            // the Nth node from the end is (length-N+1)th element from the start
            // so, generalizing it to remove Kth element from the begininning, assume k = length-N+1
            
            Node* temp=head;
            int length=0;
            while(temp!=nullptr)
            {
                temp=temp->next;
                length++;
            }
            int k=length-n+1;
            int i=1;
            temp=head;
            while(i<k-1)
            {
                temp=temp->next;
                i++;
            }
            temp->next=temp->next->next;
            return head;
        }

        // PALINDROME check : TIME: O(n) | SPACE: O(n)
        bool checkForPalindromeApproach1()
        {
            Node* temp=head;
            vector<int> v;          
            while(temp!=nullptr)
            {
                v.push_back(temp->data);
                temp=temp->next;        
            }

            int i=0;
            int j=v.size()-1;
           
            while(i<j && v.at(i)==v.at(j))
            {
                i++;
                j--;
            }
            return i>=j;
        }

        // PALINDROME check : TIME: O(n) | SPACE: O(1)  ||| also includes reversing the 2nd part of a LL
        bool checkForPalindromeApproach2()
        {

return 1;

        }

        Node* rotateLinkedList(int k)
        {
            int i=1;
            int n=1;
            Node* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
                n++;
            }
            temp->next=head;
            Node* ptr=head;
            //temp=head;
            while(i<n-k)
            {
                ptr=ptr->next;
                i++;
            }
            head=ptr->next;
            ptr->next=nullptr;
            return head;
        }

        // All even numbers appear before all the Odd numbers in the modified LL

        Node* exchangeEvenOddList()
        {
            Node* oddList=nullptr;
            Node* evenList=nullptr;
            Node* oddListEnd=nullptr;
            Node* evenListEnd=nullptr;

            Node* itr=head;
            while(itr!=nullptr)
            {
                if(itr->data%2==0)
                {
                    if(evenList==nullptr)
                    {
                        evenList=evenListEnd=itr;
                    }
                    else
                    {
                        evenListEnd->next=itr;
                        evenListEnd=itr;
                    }
                }
                else
                {
                    if(oddList==nullptr)
                    {
                        oddList=oddListEnd=itr;
                    }
                    else
                    {
                        oddListEnd->next=itr;
                        oddListEnd=itr;
                    }
                }
                itr=itr->next;
            }
            evenListEnd->next=oddList;
            return head;
        }

};

int main() 
{
    LinkedList list;
    int choice;
    while(1){
    cout<<"MENU:-"<<endl<<"1. Insert an Element\n"<<"2. Display current list\n"<<"3. Current List length\n"<<"4. Reverse list\n"<<"5. Insert at position k\n"<<"6. Delete the last node\n"<<"7. Delete a node with given DATA\n"<<"8. Reverse in pairs\n"<<"9. Nth element from the end\n"<<"10. Remove Nth from the end\n"<<"11. Check if a linked list is Palindrome\n"<<"12. Rotate linked list by k elements\n"<<"13. Separate all even numbers to be before odd numbers\n"<<"14. ";
    
    cout<<"Enter choice no.: ";
    cin>>choice;
    switch(choice)
    {
        case 1: //insert end
            {int x;
            cout<<"\nEnter element: ";
            cin>>x;
            list.insert(x);
            break;}

        case 2: //display
            {cout<<"\nLinked List: ";
            list.display();
            break;}

        case 3: //length
            {int length=list.listLength();
            cout<<"\nCurrent length: "<<length<<endl;
            break;}

        case 4: //reverse
            {list.reverseList();
            cout<<"\nReversed list: ";
            list.display();
            break;}

        case 5: //insert at position k
            {int x,k;
            cout<<"Enter the position: ";
            cin>>k;
            cout<<"\nEnter element: ";
            cin>>x;
            list.insertAtPosition(k,x);
            cout<<"\nNew list: ";
            list.display();
            break;}

        case 6: // delete the last node
            {list.deleteLastNode();
            cout<<"\nNew list: ";
            list.display();
            break;}

        case 7: // delete the node with specified element
            {
                int d;
                cout<<"Enter element to be deleted: ";
                cin>>d;
                list.deleteNodeElement(d);
                cout<<"\nNew list: ";
                list.display();
                break;
            }
        case 8: // reverse in pairs
            {
                list.reverseInPairs();
                list.display();
                break;
            }
        case 9: // Nth element from the end
            {
                int n;
                cout<<"Enter N: ";
                cin>>n;

                Node* NthFromEnd = list.NthElementFromEnd(n);
                cout<<NthFromEnd->data<<endl;
                break;
            }
        case 10: // Remove the Nth element from the end
            {
                int n;
                cout<<"Enter N: ";
                cin>>n;
                list.DeleteNthFromTheEnd(n);
                list.display();  
                break; 
            }
        case 11:
            {
                bool palindrome=list.checkForPalindromeApproach1();
                if(palindrome)
                    cout<<"The given list is a PALINDROME !";
                break;
            }

        case 12:
            {
                int k;
                cout<<"Enter k: ";
                cin>>k;
                list.rotateLinkedList(k);
                list.display();
                break;
            }
        
        case 13:
            {
                list.exchangeEvenOddList();
                list.display();
                break;
            }
        default:
            {cout<<"Invalid choice !"<<endl;
            break;}
    

    
    }
    
    }   //while ends here
    
    return 0;
}
