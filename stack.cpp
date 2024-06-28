#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
            int top;
            unsigned capacity;
            int* array;
};

Stack* createStack(unsigned size)
{
    Stack* stack=new Stack();
    stack->capacity=size;
    stack->top=-1;
    stack->array=new int[stack->capacity*sizeof(int)];
    return stack;
}

bool isFull(Stack* s)
{
    return s->top == s->capacity-1;
}

bool isEmpty(Stack* s)
{
    return s->top==-1;
}

void push(Stack* s, int item)
{
    if(isFull(s))
        return;
    s->array[++s->top]=item;
}

auto peek(Stack* s)
{
    return s->array[s->top];
}

auto pop(Stack* s)
{
    if(isEmpty(s))
        return -1;
    return s->array[s->top--];
}



// function to reverse an array using stack
void reverseArray(int arr[], int n)
{
    Stack* s=createStack(n);
    for(int i=0;i<n;i++)
    {
        push(s,arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=pop(s);
    }
    cout<<"Reversed Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

string reverseString(string str)
{
    Stack* s = createStack(str.length());
    for(int i=0;i<str.length();i++)
    {
        push(s,str[i]);
    }
    for(int i=0;i<str.length();i++)
    {
        str[i]=pop(s);
    }
    return str;
}

// function to reverse each word in a string

void reverseWords(string str)
{
    int n=str.length();
    Stack* s=createStack(n);
    for(int i=0;i<n;i++)
    {
        if(str[i]!=' '){
            push(s,str[i]);
            cout<<str[i]<<" pushed"<<endl;
            
        }
        cout<<char(peek(s));
        /*
        else{
            cout<<peek(s);
            while(!isEmpty(s))
            {
                cout<<peek(s);
                pop(s);
            }

        }*/

    }
    //cout<<"Reversed words: "<<str;
}

int main()
{
    cout<<"1. Reverse an array\n2. Reverse a String\n3. Reverse each word in a string\n"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: // reverse an integer array
        {
            int n;
            cout<<"Enter the size of array: ";
            cin>>n;
            cout<<"Enter "<<n<<" elements: ";
            int array[n];
            for(int i=0;i<n;i++)
            {
                cin>>array[i];
            }
            reverseArray(array,n);
            break;
        }
        case 2: // reverse a string
        {
            string s;
            cout<<"Enter a string: ";
            cin>>s;
            cout<<"Reversed string: ";
            s=reverseString(s);
            cout<<s;
            break;
        }
        case 3: // reverse words of a string
        {
            string str;
            cout<<"Enter a string: ";
            cin>>str;
            reverseWords(str);
            break;
        }
        default:
        {
            cout<<"Invalid choice !"<<endl;
            break;
        }

    } 
    return 0;
}