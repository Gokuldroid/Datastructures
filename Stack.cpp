/* author gokul
 * dev c++ v 4.9.9.2
 * Stack using linked list
 */
 
 #include<iostream>
 #include<string>
 
 using namespace std;
 
 template <class Datatype> class Stack
 {
       private:
               //node 
               struct node{
                      Datatype val;
                      node * nextptr;
               };
               //List header
               node * header;
               
              void createnode(Datatype val)
              {
                     node *temp=new node;
                     temp->val=val;
                     temp->nextptr=header;
                     header=temp;
                     cout<<val<<"\tpushed into stack"<<endl;
              }  
              
               
       public:
              //intialize header pointer to null...
              Stack()
              {
                     header=NULL;
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
                          cout<<del->val<<"\tpopped from stack"<<endl;
                          delete del;
                          
                   }
                   else{
                        cout<<"stack empty"<<endl;
                   }
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
              void join(Stack *ob)
              {
               
                  if(ob->header!=NULL)
                  {
                       if(header!=NULL)
                       {
                             node *itr=ob->header;
                             while(itr->nextptr!=NULL)
                             {
                                   itr=itr->nextptr;
                             }      
                             itr->nextptr=header;
                             header=ob->header;
                             cout<<"list joined"<<endl;
                       }
                       else
                       {
                           cout<<"first list was empty"<<endl;
                       }
                             
                  }
                  else{
                       cout<<"second list was empty"<<endl;
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
              void reverse()
              {
                  if(header == NULL) return;

                  node *prev = NULL, *current = NULL, *next = NULL;
                  current = header;
                  while(current != NULL){
                        next = current->nextptr;
                        current->nextptr = prev;
                        prev = current;
                        current = next;
                  }
                   // now let the head point at the last node (prev)
                   header = prev;
               
               }
              
              ~Stack()
              {
                 
              }
 };
 
 
 int main()
 {
     //int type list
     Stack<int> ob1,ob2;
     ob1.push(1);
     ob1.push(2);
     ob1.push(3);
     ob1.push(4);
     cout<<"size is "<<ob1.getsize()<<endl;
     ob2.push(5);
     ob2.push(6);
     ob2.push(7);
     ob2.push(8);
     ob1.join(&ob2);
     cout<<"size is "<<ob1.getsize()<<endl;
     ob1.pop();
     ob1.display();
     ob1.reverse();
     ob1.display();
     
     //string type list
     Stack<string> strob1,strob2;
     strob1.push("lorem");
     strob1.push("ipsum");
     strob1.push("doler");
     strob1.push("sit");
     strob2.push("amet");
     strob2.push("ivdium");
     strob1.join(&strob2);
     strob1.display();
     int a;
     cin>>a;
 }

