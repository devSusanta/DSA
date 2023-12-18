#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int data;
    struct Tree *l;
    struct Tree *r;
}tree;

tree *lChild(tree *t){
    return t->l;
}
tree *rChild(tree *t){
    return t->r;
}

void add(tree **t, int new_data){
    tree *new_tree = (tree*)malloc(sizeof(tree));
    new_tree->data = new_data;
    new_tree->l = NULL;
    new_tree->r = NULL;
    *t = new_tree;
}

void delete(tree **t){
    (*t)->r = NULL;
    (*t)->l = NULL;
    (*t) = NULL;
}

void display(tree *t){
    if(!t){
        printf("No Element Found\n");
        return;
    }
    tree *l = t->l;
    tree *r = t->r;
    if(l == NULL){
        if(r == NULL){
            printf("%d (0,0)",t->data);
        }else{
            printf("%d (0,%d)",t->data,r->data);
        }
    }else if(r == NULL){
        printf("%d (%d,0)",t->data,l->data);
    }else{
        printf("%d (%d,%d)",t->data,l->data,r->data);
    }
    printf("\n");
    return;
}

void inorderTraversal(tree* root) {
    if (root) {
        display(root);
        inorderTraversal(root->l);
        inorderTraversal(root->r);
        // display(root);
    }
}

void main(){
    tree *t1 = NULL;
    add(&t1,1);
    add(&t1->l,2);
    add(&t1->r,3);
    add(&t1->l->l,4);
    add(&t1->r->l,5);
    add(&t1->l->r,6);
    add(&t1->r->r,7);
    add(&t1->l->l->r,8);
    add(&t1->r->r->l,9);
    // delete(&t1->r);
    // display(t1);
    // display(t1->r);
    // display(t1->r);
    // display(t1->l->l);
    // display(t1->l->r);
    // display(t1->r->l);
    // display(t1->r->r);
    inorderTraversal(t1);
}
