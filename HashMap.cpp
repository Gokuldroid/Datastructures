/* author gokul
 * dev c++ v 4.9.9.2
 * basic Hashmap to reduce time complexity 
 * collision handling with seperate chaining (Queue) 
 */
 #include<iostream>
 #include<string>
 #include<string>
 
 using namespace std;
 
 class HashMap
 {
       private:
               struct node
               {
                      string key;
                      string value;
                      node * nextptr;
               };
               
               static const int BUCKET_SIZE=10;
               node *bucketheader[BUCKET_SIZE];
               
               void createnode(string key,string val,int index)
               {
                     node *temp=new node;
                     temp->key=key;
                     temp->value=val;
                     temp->nextptr=bucketheader[index];
                     bucketheader[index]=temp;
                     cout<<key<<"\tpushed into hashmap ,bucket index="<<index<<"\n"<<endl;
               }  
               void searchnode(int index,string key)
               {
                    node *itr=bucketheader[index];
                    bool found =false;
                    if(itr!=NULL)
                    {
                        while(itr!=NULL)
                        {
                             if(itr->key==key)
                             {
                                 found =true;
                                 break;
                             }
                             itr=itr->nextptr;
                        }
                           
                    }
                    if(found)
                    {
                        cout<<"key,value found"<<endl;
                        cout<<"key     ="<<itr->key<<endl;
                        cout<<"value   ="<<itr->value<<"\n"<<endl;
                    }
                    else
                    {
                        cout<<"key,value not found\n"<<endl;
                    }
               }
               
               void deletenode(int index,string key)
               {
                    node *itr=bucketheader[index];
                    bool found=false;
                    if(itr!=NULL)
                    {
                       if(itr->key==key)
                       {
                           node *temp=itr;
                           bucketheader[index]=itr->nextptr;
                           temp->nextptr=NULL;
                           found =true;
                           delete temp;
                       }      
                       else
                       {
                          while(itr!=NULL)
                          {
                             if(itr->nextptr->key==key)
                             {
                                 found =true;
                                 node * temp=itr->nextptr;
                                 itr->nextptr=itr->nextptr->nextptr;
                                 temp->nextptr=NULL;
                                 delete temp;
                                 //do not break handling duplicate cases;
                             }
                             itr=itr->nextptr;
                          }  
                       }
                    }
                    if(found)
                    {
                        cout<<key<<"  deleted form  "<<index<<" bucket\n"<<endl;
                    }
                    else
                    {
                        cout<<"can't be deleted.key,value not found\n"<<endl;
                    }
               }
              
       public :
              
              HashMap()
              {
                   for(int i=0;i<BUCKET_SIZE;i++)
                   {
                           bucketheader[i]=NULL;
                   }
              }             
               
              int hash(string key)
              {
                  //modify hash function to increase performance and to reduce collision and load factor;
                  int temp=0;
                  for(int i=0;i<key.length();i++)
                  {
                          temp +=key[i]-'a';
                  }
                  
                  return temp%BUCKET_SIZE;
              }
              
              void push(string key,string value,int index)
              {
                   createnode(key,value,index);
              }
              
              void search(string key)
              {
                   searchnode(hash(key),key);
              }
              
              void deletenode(string key)
              {
                   deletenode(hash(key),key);
              }
 };

int main()
{
    HashMap obj;
    obj.push("gokul","lorem ipsum doloer ",obj.hash("gokul"));
    obj.push("jk","future IAS :P",obj.hash("jk"));
    obj.push("dj","waste fellow",obj.hash("dj"));
    obj.push("bosee","masss da :)",obj.hash("bosee"));
    obj.search("gokul");
    obj.deletenode("gokul");
    obj.search("gokul");
    obj.search("jk");
    obj.deletenode("jk");
    obj.search("jk");
    obj.deletenode("jk");
    int a;
    cin>>a;
}
