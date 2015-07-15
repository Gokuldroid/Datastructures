/* author gokul
 * dev c++ v 4.9.9.2
 * Binary tree 
 * traversing ref http://datastructuresnotes.blogspot.in/2009/02/binary-tree-traversal-preorder-inorder.html
 */

#include<iostream>
#include<string>
 
using namespace std;

class Binarytree
{
      private:
              struct node{
                     int key;
                     node * left;
                     node *right;
              };
              
              
             node *root;
             void createleaf(node * parent,int key)
             {
                    node * temp=new node;
                    temp->key=key;
                    temp->right=temp->left=NULL;
                    //for first time
                    if(root==NULL)
                    {
                          root=temp;
                          return;
                    }
                    //if less than look into right sub tree else look into left sub tree
                    if(parent->key<key)
                    {
                          //if right sub tree is empty insert leaf node
                          if(parent->right==NULL)
                          {
                                parent->right=temp;
                                return;
                          }
                          //continue with right sub tree
                          createleaf(parent->right,key);
                    }
                    else
                    {
                          //if left sub tree is empty insert leaf node
                          if(parent->left==NULL)
                          {
                                parent->left=temp;
                                return;
                          }
                           //continue with left sub tree
                          createleaf(parent->left,key);   
                    }
             }
             
             void inorder(node * parent)
             {
                  //traverse left sub tree
                  if(parent->left!=NULL)
                  {
                        inorder(parent->left);
                  }
                  //display root
                  cout<<parent->key<<"->";
                  //traverse right sub tree
                  if(parent->right!=NULL)
                  {
                         inorder(parent->right);
                  }
             }
              void preorder(node * parent)
             {
                  //display root
                  cout<<parent->key<<"->";
                  //traverse left sub tree
                  if(parent->left!=NULL)
                  {
                        preorder(parent->left);
                  }
                  //traverse right sub tree
                  if(parent->right!=NULL)
                  {
                         preorder(parent->right);
                  }
                 
             }
              void postorder(node * parent)
             { 
                  //traverse left sub tree
                  if(parent->left!=NULL)
                  {
                        postorder(parent->left);
                  }
                  //traverse right sub tree
                  if(parent->right!=NULL)
                  {
                         postorder(parent->right);
                  }
                  //display root
                  cout<<parent->key<<"->";
                  
             }
             //finding element using divide and conquer method
             void haselement(node * parent,int key)
             {
                  if(parent==NULL)
                  {
                         cout<<"list doesn't contain "<<key<<endl;
                  }
                  else
                  {   
                      if(parent->key==key)
                      {
                         cout<<"list contains "<<key<<endl;
                      }
                      else
                      {
                          if(parent->key<key)
                          {
                               haselement(parent->right,key);
                          }
                          else
                          {
                               haselement(parent->left,key);
                          }
                      }
                  }
             }
             void removerootnode()
             {
                  //if tree contains only root element;
                  if(root->right==NULL&&root->left==NULL)
                  {
                        cout<<root->key<<" was deleted"<<endl; 
                        delete root;
                        root=NULL;
                  }                 
                  else if(root->left!=NULL&&root->right==NULL)
                  {
                       node * delptr=root;
                       root=root->left;
                       delptr->left=NULL;
                       delete delptr;
                  }
                  else if(root->left==NULL&&root->right!=NULL)
                  {
                       node * delptr=root;
                       root=root->right;
                       delptr->right=NULL;
                       delete delptr;
                  }
                  else
                  {
                      node *itr=root->right;
                      node *parent=root;
                      while(itr->left!=NULL)
                      {
                            parent=itr;
                            itr=itr->left;
                      }
                      root->key=itr->key;
                      parent->left=itr->right;
                      delete itr;
                  }
             }
             void removeleftmatch(node *parent,node * leftchild)
             {
                  //if tree contains only one element;
                  if(leftchild->right==NULL&&leftchild->left==NULL)
                  { 
                        delete leftchild;
                        parent->left=NULL;
                  }                 
                  else if(leftchild->left!=NULL&&leftchild->right==NULL)
                  {
                       node * delptr=leftchild;
                       parent->left=leftchild->left;
                       delptr->left=NULL;
                       delete delptr;
                  }
                  else if(leftchild->left==NULL&&leftchild->right!=NULL)
                  {
                       node * delptr=leftchild;
                       parent->left=leftchild->right;
                       delptr->right=NULL;
                       delete delptr;
                  }
                  else
                  {
                      node *itr=leftchild->right;
                      node *ancestor=leftchild;
                      while(itr->left!=NULL)
                      {
                            ancestor=itr;
                            itr=itr->left;
                      }
                      ancestor->key=itr->key;
                      ancestor->left=itr->right;
                      delete itr;
                  }
             }
             void removerightmatch(node *parent,node * rightchild)
             {
                   //if tree contains only one element;
                  if(rightchild->right==NULL&&rightchild->left==NULL)
                  { 
                        delete rightchild;
                        parent->right=NULL;
                  }                 
                  else if(rightchild->left!=NULL&&rightchild->right==NULL)
                  {
                       node * delptr=rightchild;
                       parent->right=rightchild->left;
                       delptr->left=NULL;
                       delete delptr;
                  }
                  else if(rightchild->left==NULL&&rightchild->right!=NULL)
                  {
                       node * delptr=rightchild;
                       parent->right=rightchild->right;
                       delptr->right=NULL;
                       delete delptr;
                  }
                  else
                  {
                      node *itr=rightchild->right;
                      node *ancestor=rightchild;
                      while(itr->left!=NULL)
                      {
                            ancestor=itr;
                            itr=itr->left;
                      }
                      ancestor->key=itr->key;
                      ancestor->left=itr->right;
                      delete itr;
                  }    
             }     
             
             void deleteleaf(node * parent,int key)
             {
                  //removeleftmatch and removerightmatch cam be combined as single function
                  if(root==NULL)
                  {
                         cout<<"tree is empty"<<endl;
                  }
                  else
                  {   
                      if(root->key==key)
                      {
                            removerootnode();
                      }
                      else
                      {
                          if(parent->key>key&&parent->left!=NULL)
                          {
                                 parent->left->key==key?removeleftmatch(parent,parent->left):deleteleaf(parent->left,key);       
                          }
                          else if(parent->key<key&&parent->right!=NULL)
                          {
                                 parent->right->key==key?removerightmatch(parent,parent->right):deleteleaf(parent->right,key);
                          }else
                          {
                                 cout<<"tree doesn't have"<<key<<endl;
                          }     
                          
                      }
                  }
             } 
             
             
      public:
             enum displayoption{INORDER,PREORDER,POSTORDER};
             Binarytree()
             {
                root=NULL;            
             }
             
             void insert(int key)
             {
                  createleaf(root,key);      
             }
             
             void displaydepthfirst(displayoption option)
             {
                  if(root==NULL)
                  {
                       cout<<"tree is empty";
                       return;
                  }
                  switch(option)
                  {
                      case INORDER: cout<<"inorder"<<endl<<"----------------"<<endl;
                                    inorder(root);
                                    cout<<"end"<<endl<<"----------------"<<endl;
                                    break;
                      case PREORDER: cout<<"preorder"<<endl<<"----------------"<<endl;
                                     preorder(root);
                                     cout<<"end"<<endl<<"----------------"<<endl;
                                     break;
                      case POSTORDER: cout<<"postorder"<<endl<<"----------------"<<endl;
                                      postorder(root);
                                      cout<<"end"<<endl<<"----------------"<<endl;
                                      break;
                  }
                  
             }
             
             void findelement(int key)
             {
                  haselement(root,key);
             }
             
             void deleteelement(int key)
             {
                   deleteleaf(root,key);     
             }
             
}; 

int main()
{
    Binarytree obj;
    obj.insert(7);
    obj.insert(1);
    obj.insert(9);
    obj.insert(0);
    obj.insert(3);
    obj.insert(2);
    obj.insert(5);
    obj.insert(4);
    obj.insert(6);
    obj.insert(8);
    obj.insert(10);
    obj.displaydepthfirst(obj.INORDER);
    obj.displaydepthfirst(obj.PREORDER);
    obj.displaydepthfirst(obj.POSTORDER);  
    obj.findelement(1);
    obj.findelement(11);
    obj.deleteelement(7);
    obj.deleteelement(11);
    obj.displaydepthfirst(obj.INORDER);
    obj.deleteelement(0);
    obj.displaydepthfirst(obj.INORDER);
    obj.deleteelement(4);
    obj.deleteelement(2);
    obj.displaydepthfirst(obj.INORDER);
    int a;
    cin>>a;
    
    
}
