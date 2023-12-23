#include <stdio.h>
#include <stdlib.h>

typedef struct TTree{
    int data;
    struct TTree *l;
    struct TTree *m;
    struct TTree *r;
}ttree;


void add(ttree **t, int new_data){
    ttree *new_ttree = (ttree*)malloc(sizeof(ttree));
    new_ttree->data = new_data;
    new_ttree->l = NULL;
    new_ttree->m = NULL;
    new_ttree->r = NULL;
    *t = new_ttree;
}

void delete(ttree **t){
    (*t)->l = NULL;
    (*t)->m = NULL;
    (*t)->r = NULL;
    (*t) = NULL;
}

void display(ttree *t){
    if(!t){
        printf("No Element Found.\n");
        return;
    }
    ttree *l = t->l;
    ttree *m = t->m;
    ttree *r = t->r;
    if(l == NULL){
        if(m == NULL){
            if(r == NULL){
                printf("%d (0,0,0)",t->data);
            }else{
                printf("%d (0,0,%d)",t->data,r->data);
            }
        }else if(r == NULL){
            printf("%d (0,%d,0)",t->data,m->data);
        }else{
            printf("%d (0,%d,%d)",t->data,m->data,r->data);
        }
    }else if(m == NULL){
        if(r == NULL){
            printf("%d (%d,0,0)",t->data,l->data);
        }else{
            printf("%d (%d,0,%d)",t->data,l->data,r->data);
        }
    }else if(r == NULL){
        printf("%d (%d,%d,0)",t->data,l->data,m->data);
    }else{
        printf("%d (%d,%d,%d)",t->data,l->data,m->data,r->data);
    }
    printf("\n");
}

void inorderTraversal(ttree *root){
    if(root){
        display(root);
        inorderTraversal(root->l);
        inorderTraversal(root->m);
        inorderTraversal(root->r);
    }
}

void main(){
    ttree *t1 = NULL;
    add(&t1,1);
    add(&t1->l,2);
    add(&t1->m,3);
    add(&t1->r,4);
    add(&t1->l->l,5);
    add(&t1->l->m,6);
    add(&t1->l->r,7);
    add(&t1->m->l,8);
    add(&t1->m->m,9);
    add(&t1->m->r,10);
    add(&t1->r->l,11);
    add(&t1->r->m,12);
    add(&t1->r->r,13);
    add(&t1->r->r,13);
    inorderTraversal(t1);
}

/*
OUTPUT
PS S:\WorkSpace\CollegeWork\DataStructure> gcc .\tinary-tree-using-linked-list.c
PS S:\WorkSpace\CollegeWork\DataStructure> ./a
1 (2,3,4)
2 (5,6,7)
5 (0,0,0)
6 (0,0,0)
7 (0,0,0)
3 (8,9,10)
8 (0,0,0)
9 (0,0,0)
10 (0,0,0)
4 (11,12,13)
11 (0,0,0)
12 (0,0,0)
13 (0,0,0)
PS S:\WorkSpace\CollegeWork\DataStructure>
*/