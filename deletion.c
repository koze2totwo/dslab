#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left,*right;
	
}Node;
  Node* root = NULL;
void inorder(Node* temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    printf("%d->",temp->data);
    inorder(temp->right);
}
void preorder(Node* temp){
    if(temp==NULL){
        return;
    }
    
    printf("%d->",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(Node* temp){
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d->",temp->data);
}
Node* createnode(int val){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

Node* insertbst(Node* temp,int val){
if(temp == NULL){
   return createnode(val);

}
else if(temp->data>val){
    temp->left=insertbst(temp->left,val);
}
else{
    temp->right=insertbst(temp->right,val);
}

}

Node* inorderpred(Node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
 
    return root;
}

Node* inordersuccc(Node* root){
    root=root->right;
    while(root->left!=NULL){
        root=root->left;
    }
   
    return root;
}

Node* prev=NULL;
Node* delete(Node* root, int v){
    if(root==NULL){
        return root;
    }
  
    if(root->data < v){
        root->right = delete(root->right,v);
    }
    else if( root->data>v){
        root->left = delete(root->left,v);
    }
    else{
        if(root->left ==NULL){
            Node* temp= root->right;
            free(root);
            return temp;
        }
         else if(root->right ==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderpred(root);
        root->data = temp->data;
        root->left = delete(root->right,temp->data);
    }
    return root;
}


















int main(){
  
   
    root = insertbst(root,40);
    insertbst(root,20);
    insertbst(root,70);
    insertbst(root,10);
    insertbst(root,30);
    insertbst(root,50);
    insertbst(root,80);
    insertbst(root,25);
    insertbst(root,35);
    insertbst(root,60);
	printf("Inorder:\n\t");
	inorder(root);
	
    Node* pred =inorderpred(root);
    Node* succ=inordersuccc(root);
    printf("\nThe inorder successor is %d\n",succ->data);
 
    root = delete(root,30);
    printf("\nPreorder; %d\n\t",root->data);
    printf("\n\n");
	inorder(root);
    
    root = delete(root,40);
    
    

    
    printf("\nPreorder; %d\n\t",root->data);
    printf("\n\n");
	inorder(root);
   
  
	
	

	return 0;
}
