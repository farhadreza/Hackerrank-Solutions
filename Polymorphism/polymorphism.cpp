#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache:public Cache{
   // private:
  //  int key, val;
   // int capacity;
   // int node_count;
    
    public:
        
        LRUCache(){
		cp= 0;
		head=NULL;
                tail=NULL; 
	}
        
        LRUCache(int capacity)
        {
           // this->capacity=capacity;
            
             while(capacity<1 ||capacity>1000)
            {
                cin>>capacity;
            }
            
            cp=capacity;
            
            
          //  node_count=0;
            head=NULL;
            tail=NULL; 
            this->mp.clear();
        }
        
        void print()
        {
            cout<<"\nPrinting Linked List:\n";
            Node* current=head;
            while(current!=NULL)
            {
                cout<<current->key<<" "<<current->value<<endl;
                current=current->next;
            }
        }
        
        void set (int key, int val)
        {
         /*   while(key<1 ||key>20)
            {
                cin>>key;
            }
            
            while(val<1 ||val>2000)
            {
                cin>>val;
            }*/
            
            map<int,Node*>::iterator mp_it;
          
            mp_it=mp.find(key);
          //  cout<<"Map Size:"<<mp.size()<<endl;
           
            if(mp_it==mp.end())
            {    
            //   cout<<"Capacity:"<<cp<<endl;           
               Node* newNode= new Node(NULL, NULL,key,val);    
               mp_it=mp.begin();
               mp.insert(mp_it,pair<int, Node*>(key,newNode));                        
             //  cout<<"Map Size:"<<mp.size()<<endl;
               
               Node* temp=head;
               newNode->next=head;
               newNode->prev=NULL;               
               head=newNode;
               
               if(tail==NULL)
               {
                    tail=head;
                    tail->next=NULL;
                    tail->prev=NULL;
               }
            
               
                if(mp.size()>cp)
                     {
                          Node* current=head;
                        //  map<int,Node*>::reverse_iterator rit=mp.rbegin();                                                   
                          if(current->next==NULL)
                          {
                             
                              tail=head;
                              tail->next=NULL;                            
                          }
                          
                          
                          else
                          {
                             // tail=tail->prev;
                           while(current->next->next!=NULL)
                          {
                              current=current->next;                                                  
                          }
                           int temp_key=current->next->key;
                           tail=current;
                           tail->next=NULL;
                           if(!mp.empty()){
                              mp.erase(temp_key);
                           }
                          }
                         // mp.erase(rit->first);
                          
                       
                     }
               
            }
            else
            {
                Node* temp_node=mp_it->second;
                temp_node->value=val;
                Node* current=head;
                if(current==NULL)
                {
                  Node* newNode= new Node(NULL, NULL, key,val); 
                  head=newNode;
                  if(tail==NULL)
                      tail=head;
               
                   mp_it=mp.begin();
                   mp.insert(mp_it,pair<int, Node*>(key,newNode));
               
                if(mp.size()>cp)
                     {
                          Node* current=head;
                         // map<int,Node*>::reverse_iterator rit2=mp.rbegin();
                          if(current->next==NULL)
                          {
                              tail=head;
                              tail->next=NULL;
                              tail->prev=NULL;
                              //node_count--;
                          }
                          else
                          {                           
                           while(current->next->next!=NULL)
                            {
                              current=current->next;
                             
                              
                            //  node_count--;
                            }
                           int temp_key=current->next->key;
                           tail=current;
                           tail->next=NULL;
                           if(!mp.empty()){
                              mp.erase(temp_key);
                           }
                          }
                         
                     }
                }
                else
                {
                    //first delete the node, then insert
                    
                   Node* newNode= new Node(NULL, NULL,key,val);
                    
                   Node* current=head;
                    
                    if(head->key==key)
                    {
                       // do nothing if the set key is in the head of the list
                       // mp[key]=newNode;
                        head->value=val;
                    }
                    
                    else if(tail->key==key)
                    {
                       // Node* temp_tail=tail;
                        
                        
                       // tail=tail->prev; //modify here
                        //tail->next=NULL;
                        
                        // Node* current=head;
                         // map<int,Node*>::reverse_iterator rit2=mp.rbegin();
                   /*       if(current->next==NULL)
                          {
                              tail=head;
                              tail->next=NULL;
                              tail->prev=NULL;
                              //node_count--;
                          }
                          else
                          {
                             // tail=tail->prev;
                             // tail->next=NULL;
                             // node_count--;
                              while(current->next->next!=NULL)
                          {
                              current=current->next;
                             
                              
                            //  node_count--;
                          }
                          // int temp_key=current->next->key;
                           int temp_val=current->next->value;
                           tail=current;
                           tail->next=NULL;
                       // delete temp_tail;
                        
                      
                         Node* newNode= new Node(key,val);                                             
                        newNode->next=head;
                       // head->prev=newNode;
                        head=newNode;
                        if(tail==NULL)
                            tail=head;
                        
                      } */
                        tail->value=val;
                   }
                    
                    else{
                        
                    
                    while(current->next!=NULL)
                    {
                        if(current->next->key==key)
                        {
                        /*    Node* temp=current->next;
                            current->next=temp->next;
                           // temp->next->prev=current;
                          //  temp=NULL;
                            delete temp;*/
                            
                            current->next->value=val;
                        }
                        current=current->next;
                            
                    }
                    //insert the node in the front
             /*       Node* newNode= new Node(key,val);                 
                    newNode->next=head;                   
                    head=newNode;*/
                    
                    }                                                             
                }
                
            }
            
         /*   for(mp_it=mp.begin();mp_it!=mp.end();++mp_it)
               {
                   cout<<mp_it->first<<" "<<mp_it->second->value<<endl;
               }*/
        }
        
      int get(int key)
      {
            map<int,Node*>::iterator mp_it;
          
            mp_it=mp.find(key);
            if(mp_it!=mp.end())
            {    
                int temp_value=mp_it->second->value;
             /*   cout<<"Printing get value:"<<temp_value<<endl;
                for(mp_it=mp.begin();mp_it!=mp.end();++mp_it)
               {
                   cout<<mp_it->first<<" "<<mp_it->second->value<<endl;
               }
                */
                    Node* current=head;
                    
                    if(head->key==key)
                    {
                       // do nothing
                     //   return head->value;
                       // return temp_value;
                    }
                    
                    else if(tail->key==key)
                    {
                       // int temp_val=tail->value;
                   /*    
                        Node* temp=tail;
                        tail=tail->prev;
                        tail->next=NULL;
                        delete temp;                        
                        Node* newNode= new Node(key,temp_val);   
                        newNode->next=head;
                        head=newNode;
                        
                         if(tail==NULL)
                            tail=head;
                        */
                        
                         if(current->next==NULL)
                          {
                              tail=head;
                              tail->next=NULL;       
                          }
                          else
                          {
                              while(current->next->next!=NULL)
                              {
                              current=current->next;
                              }
                           tail=current;
                           tail->next=NULL;                                                
                       // delete temp_tail;
                        
                        Node* newNode= new Node(key,temp_value);  
                        newNode->next=head;
                       // head->prev=newNode;
                        head=newNode;
                        if(tail==NULL)
                            tail=head;
                      } 
                        
                      //  return temp_value;
                        
                    }
                    
                    else{
                        
                  /*  int temp_val2;
                    while(current->next!=NULL)
                    {
                        if(current->next->key==key)
                        {
                            Node* temp=current->next;
                            temp_val2=temp->value;
                            current->next=temp->next;
                            temp->next->prev=current;
                           // temp=NULL;
                            delete temp;
                            
                        }
                        current=current->next;
                            
                    }
                    //insert the node in the front
                    Node* newNode= new Node(key,mp[key]->value);  
                    newNode->next=head;
                    head=newNode;
                    return head->value;
                    */
                   
                //   int temp_val2;
                   Node* current=head;
                   while(current->next!=NULL)
                    {
                        if(current->next->key==key)
                        {
                            Node* temp=current->next;
                            current->next=temp->next;
                            temp=NULL;
                            delete temp;
                            
                            break;
                        }
                        current=current->next;
                            
                    }
                    //insert the node in the front
                    Node* newNode= new Node(key,temp_value);   
                    newNode->next=head;
                    head=newNode;                    
                    if(tail==NULL)
                        tail=head;
                                                
                    }                        
 
                 return temp_value;
               
            }
            else
            {
                
                return -1;
            }
                
        }
    
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
          l.print();
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
         l.print();
      }
   }
   return 0;
}
