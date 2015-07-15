/* author gokul
 * dev c++ v 4.9.9.2
 * Stack using linked list
 */
 
 #include<iostream>
 #include<string>
 
 using namespace std;
 
 template <class Datatype> class Queue
{
          private:
               //node 
               struct node{
                      Datatype val;
                      node * nextptr;
               };
               //List header
               node * header,*tail;
               
              void createnode(Datatype val)
              {
                     node *temp=new node;
                     temp->val=val;
                     temp->nextptr=NULL;
                     if(header==NULL||tail==NULL)
                     {
                           header=tail=temp;
                     }
                     else
                     {
                         tail->nextptr=temp;
                         tail=temp;
                     }
                     cout<<val<<"\tpushed into queue"<<endl;
              }  
              
               
         public:
                Queue()
                {
                       header=tail=NULL;       
                }
                void push(Datatype val)
                {
                    createnode(val);
                }
                void pop()
                {
                   if(header!=NULL)
                   {
                          node *del=header;
                          header=header->nextptr;
                          cout<<del->val<<"\tpopped from queue"<<endl;
                          delete del;
                          
                   }
                   else{
                        cout<<"queue empty"<<endl;
                   }
                }
                 void display()
                 {
                      node *itr=header;
                      while(itr!=NULL)
                      {
                            cout<<itr->val<<"--->";
                            itr=itr->nextptr;
                         
                       }
                       cout<<"end"<<endl;
                }
                
                int getsize()
                {
                    int count=0;
                    node *itr=header;
                   while(itr!=NULL)
                    {
                         itr=itr->nextptr;
                         count++;
                    }
                    return count;
                }
                
                ~Queue()
                {
                        
                }
                //reverse function same as stack
 
};

int main()
{
    Queue<int> ob;
    ob.push(1);
    ob.push(2);
    ob.push(22);
    ob.push(25);    
    ob.push(26);    
    ob.pop();
    ob.pop();
    ob.pop();
    ob.display();
    int a;
    cin>>a;
}
