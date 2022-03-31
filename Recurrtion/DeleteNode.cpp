#include<iostream>
using namespace std;


class node{
public :
    double value;
    node *next;
};

void print(node *head){
    cout<<"printing : ";
    while (head != NULL) {
        cout << head->value<<" ";
        head = head->next;
    }
}

int number_ofElements = 3;

void Firstinsert(node * &head){
    cout<<endl;
    cout<<"to insert in the first position of the linked list: "<<endl;
    cout<<"enter value : ";
    node * newnode = new node();
    cin>>newnode->value;
    newnode->next = head;
    head = newnode;

    return;
}

void Lastinsert(node * &head){
    if(head == NULL){
        Firstinsert(head);
        return;
    }
    cout<<endl;
    cout<<"to insert in the last position of the linked list: "<<endl;
    cout<<"enter value: ";
    node * temp = new node();
    cin>>temp->value;
    if(head == NULL){
        head = temp;
    }
    while(head->next != NULL){
        head = head->next;
    }
    head->next = temp;
    temp->next = NULL;
}

void middleinsert(node * &head, int index){
    
   if(number_ofElements<index){
       cout<<"not valid position "<<endl;
       return;
   }
    int count = 0;
    while(count != (index-2)){
        head = head->next ;
        count++;
    }
    node * newnode  = new node();
    cout<<"enter value : ";
    cin>>newnode->value;
    newnode->next = (head->next);
    head->next = newnode;
}

void reverse(node * &head){
        
        node * current = head;
        node * temp_1 = NULL;
        node * temp_2 = NULL;
  
        while (current != NULL) {

            temp_2 = current->next;
            current->next = temp_1;
            temp_1 = current;
            current = temp_2;
        }
        head = temp_1;
    }
  
void sort(node * &head){
    node * i,*j;
    double temp;

    for(i= head ; i->next != NULL ; i=i->next){
        for(j=i->next ; j != NULL ; j=j->next){
            if(i->value > j->value){
                temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }
}

void removeDuplicates(node* &head){

    node * temp_head, *temp_head2;
    node * toDelete;
    temp_head = head;
 
    while (temp_head != NULL && temp_head->next != NULL) {

        temp_head2 = temp_head;
 
        while (temp_head2->next != NULL) {

            if (temp_head->value == temp_head2->next->value) {
                toDelete = temp_head2->next;
                temp_head2->next = temp_head2->next->next;
                delete (toDelete);
            }
            else{
                temp_head2 = temp_head2->next;
            }
        }
        temp_head = temp_head->next;
    }
}

void deleteNode(node * &head, int value, node * pre){
    node * temp_head = head;
    node * todelete;
    node * prev = pre;
    if(temp_head == NULL){
        delete todelete;
        return;
    }
    else if(temp_head->value == value){
        todelete = temp_head;
        prev->next = temp_head->next->next;
        delete todelete;
    }
    cout<<"okhe"<<endl;
    deleteNode(temp_head->next,value,temp_head);
}

int main(){

    cout<<"choose any function: "<<endl;
    int n = 0;

    node *head = NULL; 

    
    while(n!=-1){
        cout<<endl;
        cout<<"option 1 , 2 , 3 for creating a list: ";
        cout<<endl;
    cout<<"enter at the first     : 1"<<endl
        <<"enter at the last      : 2"<<endl
        <<"insert at any location : 3"<<endl
        <<"print the list         : 4"<<endl
        <<"reverse the list       : 5"<<endl
        <<"sort the list          : 6"<<endl
        <<"remove duplicate       : 7"<<endl
        <<"delete a node          : 8"<<endl
        <<"exit:                  : 9"<<endl;

        cin>>n;

        if(n == 1){
            Firstinsert(head);
            number_ofElements++;
        }
        else if(n == 2){
            Lastinsert(head);
            number_ofElements++;
        }
        else if(n == 3){
            cout<<endl;
            cout<<"enter position where do you want to insert: ";
            int d;
            cin>>d;
            middleinsert(head,d);
            number_ofElements++;
        }
        else if(n == 4){
            print(head);
        }
        else if(n == 5){
            cout<<"reversing the list: ";
            reverse(head);
        }
        else if(n == 6){
            cout<<"sorting the List: "<<endl;
            cout<<"print the list to see the sorted list ....."<<endl;
            sort(head);
        }
        else if(n == 7){
            removeDuplicates(head);
        }
        else if(n == 8){
            int x;
            cout<<"enter the value u want to delete: ";
            cin>>x;
            deleteNode(head,x,NULL);
        }
        else if(n == 9){
            n = -1;
            break;
        }
        else{
            cout<<"choose a correct option: "<<endl;
            continue;
        }

    }

    return 0;
}