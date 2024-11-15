#include <stdio.h>
#include "avl.h"

int main(int argc, char* argv[]){
  struct AVL* root = insert(NULL, 41);
  root = insert(root, 20);
  root = insert(root, 11);
  root = insert(root, 29);
  root = insert(root, 26);
  root = insert(root, 65);
  root = insert(root, 50);
  printf("bf(%d) = %d\n", root->data, balanceFactor(root));

  root = insert(root, 23);
  printf("bf(%d) = %d\n", root->data, balanceFactor(root));

  struct AVL* pivot = root->left->right;

  pivot = rightRotation(pivot);
  printf("bf(%d) = %d\n", pivot->data, balanceFactor(pivot));
  printf("bf(%d) = %d\n", root->data, balanceFactor(root));

}
