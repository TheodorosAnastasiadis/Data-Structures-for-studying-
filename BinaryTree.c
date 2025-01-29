#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node { //Δομη για την υλοποιηση ενος κομβου του δενδρου
    int key;
    struct Node* right;
    struct Node* left;
    struct Node* parent;
} Node; /* Κάθε κόμβος (Node) θα έχει δείκτες προς τον πατρικό του,
αλλά και προς τον αριστερό και τον δεξιό θυγατρικό του!*/

typedef struct BST 
{
    Node *root;
}BST;/*Θα φτιάξουμε ένα struct που θα αντιστοιχεί στο δένδρο
Το struct αυτό θα περιέχει μόνο τη ρίζα του δένδρου*/

void preorder(Node*x){
    if (x != NULL){ 
        printf("%d",x->key);
        preorder(x->left);
        preorder(x->right);
    }
}

void postorder(Node*x){
    if(x != NULL){
        postorder(x->left);
        postorder(x->right);
        printf("%d",x->key);
    }
}

void inorder(Node*x){
    if(x != NULL){
        inorder(x->left);
        printf("%d",x->key);
        inorder(x->right);
    }
}

Node* tree_search (Node*x, int k){
    if(x==NULL || x->key==k){
        return x;
    }
    if(k<x->key){
        return tree_search(x->left,k);
    }
    return tree_search(x->right,k);
}

Node* iterative_tree_search(Node*x, int k){
    Node* current=x;
    while(x!=NULL && k != x->key){
        if(k<x->key){
            current= current->left;
        }else{
            current = current->right;
        }
    }
    return current;
}

Node* TreeMIN(Node*x){
    Node* current=x;
    while (x->left!=NULL){
        current=current->left;
    }
    return current;
}

Node* TreeMAX(Node* x){
    Node *current=x;
    while(current->right!=NULL){
        current= current->right;
    }
    return current;
}

Node* treeSuccessor(Node* x){
    if(x->right != NULL){
        return TreeMIN(x->right);
    }
    Node* y = x->parent;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->parent;
    }
    return y;
}
Node* tree_predecessor(Node*x){
    if (x->left != NULL){
        return TreeMAX(x->left);
    }
    Node* y = x->parent;
    while(y!=NULL && x==y->left){
        x=y;
        y=y->parent;
    }
    return y;
}

//Εισαγωγη σε δεντρο
void tree_insert(Node** T, Node*z){
    Node* y =NULL;
    Node* x= *T;

    while (x!=NULL){
        y=x;
        if(z->key < x->key){
            x=x->left;
        }else{
            x->right;
        }
    }
    z->parent=y;
    if(y==NULL){
        *T =z;
    }else if(z->key < y->key){
        y->left=z;
    }else{
        y->right=z;
    }
    
}

//Δημιουργια νεου Κομβου

Node* new_node(int val){
    Node *temp_node = (Node*)malloc(sizeof(Node));
    temp_node->key=val;
    temp_node->left = temp_node->right= temp_node->parent=NULL;
    return temp_node;
}

Node* tree_insert_recursive(Node* T, Node* z) {
    if (T == NULL)
        return z;
    if (z->key < T->key)
        T->left = tree_insert_recursive(T->left, z);
    else if (z->key > T->key)
        T->right = tree_insert_recursive(T->right, z);
    return T;
}

void transplant(Node** T, Node* u, Node* v) {
    if (u->parent == NULL)
        *T = v;
    else if (u == (u->parent)->left)
        (u->parent)->left = v;
    else (u->parent)->right = v;
        if (v != NULL)
            v->parent = u->parent;
}

void tree_delete(Node** T, Node* z) {
    Node* y = NULL;
    if (z->left == NULL) 
        transplant(T, z, z->right);
    else if (z->right == NULL) 
        transplant(T, z, z->left);
    else {
        y = TreeMIN(z->right);
        if (y!= z->right) {
            transplant(T, y, y->right);
            y->right = z->right;
            (y->right)->parent = y;
        }       
        transplant(T, z, y);
        y->left = z->left;
        (y->left)->parent = y;
}
free(z);
}

Node* tree_delete_recursive(Node* T, int key) {
    if (T == NULL)
        return T;
    if (key < T->key)
        T->left = tree_delete_recursive(T->left, key);
    else if (key > T->key)
        T->right = tree_delete_recursive(T->right, key);
    else if (T->left == NULL) {
        Node *temp = T->right;
        free(T);
        return temp;
    }else if (T->right == NULL) {
        Node *temp = T->left;
        free(T);
        return temp;
    }
    Node* temp = TreeMIN(T->right);
    T->key = temp->key;
    T->right =
    tree_delete_recursive(T->right,temp->key);
    return T;
}

//main
int main(void) {
    BST T;
    T.root = NULL;
    tree_insert(&T.root, new_node(35));
    inorder(T.root);
    Node* temp = tree_search(T.root,35);
    int key = tree_predecessor(temp)->key;
    tree_delete(&T.root, temp);
    return 0;
}
//change