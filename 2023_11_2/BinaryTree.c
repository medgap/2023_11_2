#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

void createTree(TreeNode** t,char* data,int* index){
    char ch = data[*index];
    *index += 1;
    if(ch == '#'){
        *t = NULL;
        return;
    }
    else{
        *t = (TreeNode*)malloc(sizeof(TreeNode));
        (*t)->data = ch;
        createTree(&((*t)->lchild),data,index);
        createTree(&((*t)->rchild),data,index);
    }
}

void preOrder(TreeNode* t){
    if(t == NULL){
        return;
    }
    else{
        printf("%c ",t->data);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

void inOrder(TreeNode* t){
    if(t == NULL){
        return;
    }
    else{
        preOrder(t->lchild);
        printf("%c ",t->data);
        preOrder(t->rchild);
    }
}

void postOrder(TreeNode* t){
    if(t == NULL){
        return;
    }
    else{
        preOrder(t->lchild);
        preOrder(t->rchild);
        printf("%c ",t->data);
    }
}

int main(int argc,char* argv[]){
    TreeNode* t;
    int index = 0;
    createTree(&t,"ABD##E##CF##G##",&index);
    preOrder(t);
    printf("\n");
    inOrder(t);
    printf("\n");
    postOrder(t);
    printf("\n");
    return 0;
}