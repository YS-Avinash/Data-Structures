#include<iostream.h>
class node{
	public:
	  int data;
	  node *left,*right;
};
class BinarySearchTree{
	node *root,*p;
	public:
	void design();
	BinarySearchTree();
	void Leaf(node*,node*);
    void Inorder(node*);
    void Preorder(node*);
    void Postorder(node*);
    void Disp(int);
    void search(node*,node*,int,int);
    void delet(node*,node*,int);
    node* find(node*,node*);
};
BinarySearchTree::BinarySearchTree(){
	root=NULL;//Empty Tree
}
void BinarySearchTree::design(){
	int x;
	do{
	cout<<"\n**OPERATIONS**\n";
	cout<<"1.Insert\n2.Delete\n3.Display\n4.Quit\n";
	cout<<"Enter your choice:";
	cin>>x;
	switch(x){
		case 1:	p=new (node);
            	cout<<"Enter element:";
	            cin>>(p->data);
                p->right=p->left=NULL;
				Leaf(root,p);
                break;
  		case 2:cout<<"Enter Element:";cin>>x;
		       search(root,root,x,0);
		       x=2;
		       break;
        case 3:cout<<"\n1.In order\n2.Pre order\n3.Post order\n";
               cout<<"Enter choice:";cin>>x;
				Disp(x);
				x=3;
				break;
	   }
	}while(x!=4);
}
void BinarySearchTree::Leaf(node *x,node *y){
	if(root==NULL)
		root=y;
	else{
	int a,b;
	a=x->data;
	b=y->data;
	if(a>b){
		if(x->left!=NULL){
			x=x->left;
			Leaf(x,y);
		}
		else
		  x->left=y;
	}
	else{
		if(x->right!=NULL){
			x=x->right;
			Leaf(x,y);
		}
		else
		  x->right=y;
	}
	}
}
void BinarySearchTree::Disp(int x){
	if(x==1)
		Inorder(root);
	else if(x==2)
		Preorder(root);
	else
	    Postorder(root);
}
void BinarySearchTree::search(node *x,node *y,int k,int n){
   int m;
	m=x->data;
	if(x==NULL)
	  cout<<"Element not found!\n";
	else if(k==m){
	  cout<<"Element "<<k<<" found!\n";
	  delet(x,y,n);
	}
	else if(m>k){
	   y=x;
	   x=x->left;
	   n=0;
	   search(x,y,k,n);
	}
	else{
		y=x;
		x=x->right;
		n=1;
		search(x,y,k,n);
	}
}
void BinarySearchTree::delet(node *x,node *y,int n){
    node *k;
    if(x->left==NULL && x->right==NULL){
    	if(n==0){
		k=y->left;
		y->left=NULL;
		delete(k);
    	}
    	else{
    		k=y->right;
    		y->right=NULL;
    		delete(k);
    	}
    }
    else if(x->left==NULL){
    	k=x->right;
    	if(n==1)
        	y->right=k;
    	else
    	    y->left=k;
    	delete(x);
    }
    else if(x->right==NULL){
    	k=x->left;
    	if(n==1)
    	y->right=k;
    	else
    	 y->left=k;
     	delete(x);
    }
    else{	
     k=find(x->right,x);     
     x->data=k->data;
    delete(k);
    }
}
void BinarySearchTree::Inorder(node *x){
	if(x!=NULL){
		Inorder(x->left);
		cout<<x->data<<" ";
		Inorder(x->right);
	}
}
void BinarySearchTree::Preorder(node *x){
	if(x!=NULL){
		cout<<x->data<<" ";
		Preorder(x->left);
		Preorder(x->right);
	}
}
void BinarySearchTree::Postorder(node *x){
	if(x!=NULL){
		Postorder(x->left);
		Postorder(x->right);
		cout<<x->data<<" ";
	}
}
node* BinarySearchTree::find(node *x,node *y){
    node *p=x,*q;
    if(x->left!=NULL){
        while(p->left!=NULL)
		    p=p->left;
	     q=x;
		while(q->left->left!=NULL)
			    q=q->left;
		if(p->right!=NULL){
			q->left=p->right;
			return p;
		}
		q->left=NULL;
		return p;
    }
    else{
    	y->right=p->right;
    	return p;
    }
}
int main(){
	BinarySearchTree tree;
        tree.design();
}
