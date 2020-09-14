#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>


#include <conio.h> 


using namespace std;

#include "../include/person.h"
#include "../include/stack.h"

typedef struct nodeTree
{
	int oldheightNode; // eski konum
	int data;
	int heightNode; //  konum
	int newheightNode; // yeni konum
	struct nodeTree *left,*right;
	stack *move; // hareketlerin olduğu stack
}nodeTree;
 

 
nodeTree *insert(nodeTree *,int); // ekleme
nodeTree *rotateRight(nodeTree *); 
nodeTree *rotateLeft(nodeTree *); 

nodeTree *rightRight(nodeTree *);
nodeTree *leftLeft(nodeTree *);
nodeTree *leftRight(nodeTree *);
nodeTree *rightLeft(nodeTree *);

int height( nodeTree *);
int getBalance(nodeTree *); // denge kontrolöü
void printPostorder(nodeTree *); // postorder ağaç yazma
 
void printStack(stack *); // stack yazma 
int getTreeHeight(nodeTree*); // ağaç yükseklik
void travelLevelOrder(nodeTree*,int); //level level ağaca girer
void setLevel(nodeTree*, int ,int ,int ); // bulunduğu levelde ki nodelere konum atar


int main()
{	
  		

	nodeTree *root=NULL; //avl ağaç oluşturma 
	int exit=1;
  printf("---Welcome to AVL TREE---\n");
  
  while(exit)
  {
    int input;
    int data;

    printf("If you want to add data, just press 1\n");
    printf("If you want to print tree, just press 2\n"); 
    printf("If you want to exit, just press 3\n");

    scanf("%d",&input);
    switch(input)
    {
      case 1 :
        printf("Enter the number you want to add : ");
        scanf("%d",&data);
	travelLevelOrder(root,1); // ağaç dolaşılır code 1 girdiği için her düğümün eski konumunu atar	
	root=insert(root,data); // avl ağacına ekleme yapar
	travelLevelOrder(root,0); // ağaç dolaşılır code 0 girdiği için her düğümün yeni konumunu bulur ve  atama yapmadan önce kontrol yapar değişikliklere göre move stackına ekleme yapar
 	printf("----Data Successfully Added----\n");
          break;
      case 2 :
	printPostorder(root);
        printf("---Tree Successfully Printed---\n");
          break;
      case 3 :
        exit=0;
          break;
    }
  }
	cout<<"Agac basari ile olusturuldu. Programi sonlandirmak icin bir tusa basin.";
	getch();
		return 1;
}

nodeTree * insert(nodeTree *node,int dataPerson)
{
	if(node==NULL)
	{
		node=(nodeTree*)malloc(sizeof(nodeTree));
		node->data=dataPerson;
		node->left=NULL;
		node->right=NULL;
		node->oldheightNode=-1;
		(node->move) = new stack();
	}
	else
	{
		if(dataPerson > node->data)	
		{
			node->right=insert(node->right,dataPerson);
			if(getBalance(node)==-2)
				if(dataPerson>node->right->data)
					node=rightRight(node);
				else
					node=rightLeft(node);
		}
		else
		{
			if(dataPerson<node->data || dataPerson==node->data)
			{
				node->left=insert(node->left,dataPerson);
				if(getBalance(node)==2)
					if(dataPerson < node->left->data || dataPerson == node->left->data )
						node=leftLeft(node);
					else
						node=leftRight(node);
			}
		}	
	}
		
	node->heightNode=height(node);
	return(node);
}
nodeTree * leftRight(nodeTree *node)
{
	node->left=rotateLeft(node->left);
	node=rotateRight(node);
	return(node);
}
nodeTree * leftLeft(nodeTree *node)
{
	node=rotateRight(node);
	return(node);
}
nodeTree * rightLeft(nodeTree *node)
{
	node->right=rotateRight(node->right);
	node=rotateLeft(node);
	return(node);
}
nodeTree * rightRight(nodeTree *node)
{
	node=rotateLeft(node);
	return(node);
} 

nodeTree * rotateLeft(nodeTree *node)
{
	nodeTree *temp=(nodeTree*)malloc(sizeof(nodeTree));;
	temp=node->right;
	node->right=temp->left;
	temp->left=node;
	
	node->heightNode=height(node);
	temp->heightNode=height(temp);
	return(temp);
} 
nodeTree * rotateRight(nodeTree *node)
{
	nodeTree *temp=(nodeTree*)malloc(sizeof(nodeTree));
	temp=node->left;
	node->left=temp->right;
	temp->right=node;

	node->heightNode=height(node);
	temp->heightNode=height(temp);
	return(temp);
}

void printStack(stack *s) 
{ 
	stack s1;
	s1=*s;
	cout<<"   Yigit : ";
    while (!s1.empty()) 
    { 
        cout <<' '<< s1.pop(); 
        
    } 
    cout << '\n'; 
}
void printPostorder(nodeTree* root) 
{ 
    if (root == NULL) 
        return; 
	
    printPostorder(root->left); 
    printPostorder(root->right); 
		(root->data);
		printStack(root->move);
	
	cout<<"\n";
} 
int getBalance(nodeTree *root)
{
	int leftHeight,rightHeight;
	if(root==NULL)
		return(0);
 
	if(root->left==NULL)
		leftHeight=0;
	else
		leftHeight=1+root->left->heightNode;
 
	if(root->right==NULL)
		rightHeight=0;
	else
		rightHeight=1+root->right->heightNode;
 
	return(leftHeight-rightHeight);
} 
int height(nodeTree *node)
{
	int leftHeight,rightHeight;
	if(node==NULL)
		return(0);
	
	if(node->left==NULL)
		leftHeight=0;
	else
		leftHeight=1+node->left->heightNode;
		
	if(node->right==NULL)
		rightHeight=0;
	else
		rightHeight=1+node->right->heightNode;
	
	if(leftHeight>rightHeight)
		return(leftHeight);
	
	return(rightHeight);
}
int getTreeHeight(nodeTree*  root)
{
  
    if (!root)
        return 0;
    else {
        int leftHeight = getTreeHeight(root->left);
        int rightHeight = getTreeHeight(root->right);
		
        if (leftHeight >= rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}
void travelLevelOrder(nodeTree* root,int code)
{
    if (!root)
        return;
    int height = getTreeHeight(root);
    for (int i=0; i<height; i++) {
        setLevel(root, i,i,code);
    }
}
void setLevel(nodeTree* root, int level_no,int level,int code)
{
	if(code==0)
	{
		if (!root)
			return;
		if (level_no == 0) 
		{
			int oldH,newH;
			oldH=root->oldheightNode;
			newH=level;
			
			if(oldH==-1)	
				(root->move)->push('O');
			else if(newH>oldH)
				(root->move)->push('A');
			else if(oldH>newH)
				(root->move)->push('Y');	
			else 
				(root->move)->push('D');				
				
			root->newheightNode=level;
		}
		else
		{
			setLevel(root->left, level_no - 1,level,code);
			setLevel(root->right, level_no - 1,level,code);
		}
	}
	else
	{	
		if (!root)
			return;
		if (level_no == 0)
			root->oldheightNode=level;
		else
		{
			setLevel(root->left, level_no - 1,level,code);
			setLevel(root->right, level_no - 1,level,code);
		}
	}
}
