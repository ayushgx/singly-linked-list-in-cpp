#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

class list{
    private:
        node *head, *tail;
    public:
        list(){
            head = NULL;
            tail = NULL;
        }
        
        void createNode(int x){
            
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            
            //tail keeps record of last node
            if(head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            } else {
                //once the head is specified we only need to use the tail to carry out further operations
                tail->next = temp;
                //update the tail
                tail = temp;
            }
        }
        
        void display(){
            node *temp;
            temp = head;

            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
        
        void insertNodeStart(int val){
            node *temp = new node;
            temp->data = val;
            temp->next = head;
            //update head
            head = temp;
        }
        
        //position is zero based
        void insertNodePosition(int pos, int val){
            node *pre;
            node *cur;
            node *temp = new node;
            cur = head;
            
            while(pos--){
                pre = cur;
                cur = cur->next;
            }
            
            temp->data = val;
            pre->next = temp;
            temp->next = cur;
        }
        
        void delFirst(){
            node *temp = head;
            head = head->next;
            delete temp;
        }
        
        void delPos(int pos){
            node *pre;
            node *cur;
            cur = head;
            while(pos--){
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
            delete cur;
        }
        
        void delLast(){
            node *pre;
            node *cur;
            cur = head;
            
            while(cur->next!=NULL){
                pre = cur;
                cur = cur->next;
            }
            
            pre->next = NULL;
            tail = pre;
            delete cur;
        }
        
        //zero based index
        void search(int x){
            int pos = 0;
            int flag = 0;
            node *temp;
            temp = head;

            while(temp != NULL){
                if (temp->data==x){
                    cout<<"Element found at node index: "<<pos;
                    flag=1;
                } else {
                    pos++;    
                }
                temp = temp->next;
            }
            if(flag==0) cout<<"Element not found!";
            cout<<"\n";
        }
};

int main(){
    
    list obj;
    
    obj.createNode(1);
    obj.createNode(2);
    obj.createNode(3);
    obj.createNode(4);
    obj.createNode(5);
    obj.display();
    
    obj.insertNodeStart(6);
    obj.display();
    
    obj.insertNodePosition(3,12345);
    obj.display();
    
    obj.delPos(3);
    obj.display();
    
    obj.delFirst();
    obj.display();
    
    obj.delLast();
    obj.display();
  
    obj.search(4);
    
    return 0;
}
