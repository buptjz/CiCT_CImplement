////
////  main.c
////  CiCT
////
////  Created by Wang JZ on 13-8-25.
////  Copyright (c) 2013年 Wang JZ. All rights reserved.
////
//
//#include <stdio.h>
//#include "arrayAndString.h"
//
//
//int main(int argc, const char * argv[])
//{
//    //char a[] = "wordar";
//    //int is = isUnique3(a);
//    //printf("%d",is);
//    char p[] = "aa";
//    //stringInverse(p);
//    //charReplace(p);
//    //testPointer(p);
//    char *a = stringCompress(p);
//    //printf("%s",a);
//    return 0;
//}

/*《数据结构与算法分析-c语言描述版》
 *二叉查找树
 *插入、删除、中序遍历、置空
 * */

#include "stdio.h"
#include <stdlib.h>
/*定义二叉查找树的数据结构*/
struct BSTreeNode{
    struct BSTreeNode *left;
    struct BSTreeNode *right;
    struct BSTreeNode *parent;
    int key;
};

/*判断TN2和TN1是不是一样*/
int is_same_tree(struct BSTreeNode *TN1,struct BSTreeNode *TN2){
	if(TN1 == NULL && TN2 == NULL) return 1;
    else if (TN1 != NULL && TN2 == NULL) return 0;
    else if (TN1 == NULL && TN2 != NULL) return 0;
	else if(TN1->key == TN2->key)
		return is_same_tree(TN1->left,TN2->left) && is_same_tree(TN1->right,TN2->right);
	else return 0;
}

/*先序遍历*/
int preorder_search(struct BSTreeNode *TN1,struct BSTreeNode *TN2){
	int result = 0;
	if(TN1->key == TN2->key) result = is_same_tree(TN1,TN2);
	if(result!=1 && TN1->left !=NULL)
		result = preorder_search(TN1->left,TN2);
	if(result!=1 && TN1->right != NULL)
		result = preorder_search(TN1->right,TN2);
    
	return result;
}

/*判断TN2是不是TN1的子树*/
int is_subtree(struct BSTreeNode *TN1,struct BSTreeNode *TN2){
	if(TN1 == NULL && TN2 == NULL) return 1;
	//empty tree is always the subtree
	if(TN1 != NULL && TN2 == NULL) return 1;
	return preorder_search(TN1,TN2);
}


/*插入节点*/
struct BSTreeNode* insert(int key,struct BSTreeNode *T){
	if(T != NULL){
		if(key < T->key){
			T->left = insert(key,T->left);
            T->left->parent = T;
		}else{
			T->right = insert(key,T->right);
            T->right->parent = T;
		}
	}else{
		struct BSTreeNode *new_node = malloc(sizeof(struct BSTreeNode));
		if (new_node == NULL){
			//FatalError("Out of space");
			printf("Out of space");
		}else{
			new_node->left = new_node->right = new_node->parent = NULL;
			new_node->key = key;
            T = new_node;
		}
	}
	return T;
}

int main(){
	struct BSTreeNode *tree1 = NULL,*tree2 = NULL;
    int a[] = {9,4,7,3,2,8,6,5,1};
	int i;
    tree1 = insert(a[0],tree1);
	for(i = 1;i < 9;i++){
        insert(a[i],tree1);
	}
    //delete(root->left->right);
	//inorder_treewalk(root);
	//
	tree2 = insert(6,tree2);
	//insert(6,tree2);
	insert(5,tree2);
	//insert(8,tree2);
    
	int result;
	result = is_subtree(tree1,tree2);
	printf("is subtree %d",result);
	return 1;
}