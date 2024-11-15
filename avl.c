#include<stdlib.h>
#include<stdio.h>
#include "avl.h"
#include <assert.h>

int max(int a, int b){
  return (a > b) ? a : b;
}

int abs(int a){
  return (a < 0) ? -a : a;
}

struct AVL* newNode(int data){
  struct AVL* node = malloc(sizeof(struct AVL));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}

struct AVL* insert(struct AVL* node, int data){
  if(node){
    if(data <= node->data){
      node->left = insert(node->left, data);
      node->left->parent = node;
    } else {
      node->right = insert(node->right, data);
      node->right->parent = node;
    }
  }else
    return newNode(data);
  return node;
}

int height(struct AVL* node){
  if(!node) return -1;
  return 1 + max(height(node->left),
      height(node->right));
}

int balanceFactor(struct AVL* node){
  if(node)
    return height(node->right) -
      height(node->left);
  return 0;
}
int isAVL(struct AVL* node){
  if(!node) return 1;
  return abs(balanceFactor(node)) <= 1 &&
    isAVL(node->left) &&
    isAVL(node->right);
}

struct AVL* leftRotation(struct AVL* X){
  assert(X != NULL);
  struct AVL* Y = X->right;
  struct AVL* parentX = X->parent;//padre de x
  assert(Y != NULL);


  struct AVL* B = Y->left; //hijo izquierdo de y

  //cambios de los enlaces

  Y->left = X;
  X->parent = Y;

  X->right = B;
  if(B)
    B->parent = X;
  //cambiando enlaces con el padre
  if(parentX){
    if(parentX->left == X)
      parentX->left = Y;
    else
      parentX->right = Y;
  }
  Y->parent = parentX;
  return Y;
}

struct AVL* rightRotation(struct AVL* X){
  assert(X != NULL);
  struct AVL* Y = X->left;
  struct AVL* parentX = X->parent;
  assert(Y != NULL);
  struct AVL* B = Y->right; 
  //cambios de los enlaces
  Y->right = X;
  X->parent = Y;
  
  X->left = B;
  if(B)
    B->parent = X;
  //cambiando enlaces con el padre
  if(parentX){ //verificamos si el nodo es root
    if(parentX->left == X)
      parentX->left = Y;
    else
      parentX->right = Y;
  }
  Y->parent = parentX;
  return Y;
}
