#include<stdio.h>
#include<stdlib.h>
/**
 * @brief 全局静态指针变量用来传递参数的用法
 * 
 */

typedef struct TREE
{
    char* left;
    char* right;
}Tree;

static Tree* tree = (Tree*)NULL;

static Tree* allocateArray() {
    tree = (Tree*)malloc(sizeof(Tree));
    tree->left = "zhang";
    tree->right = "shi";
    return tree;
}
void print_tree() {
    if((Tree*)NULL == tree) {
        tree = (Tree*)malloc(sizeof(Tree));
    // tree2->left = (char*)NULL;
    // tree2->right = (char*)NULL;
        printf("L is %s, R is %s\n", tree->left, tree->right);
    }
}


int main() {
    Tree* tree_main = allocateArray();
    tree_main->left = "zhang";
    tree_main->right = "xuan";
    printf("left is %s, right is %s\n", tree_main->left, tree_main->right);
    print_tree();
    printf("Lmain is %s, Rmain is %s\n", tree->left, tree->right);
    return 0;
}