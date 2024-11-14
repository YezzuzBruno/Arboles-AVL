#ifndef AVL_H
#define AVL_H

struct AVL {
  int data;
  struct AVL* left;
  struct AVL* right;
  struct AVL* parent;
};

struct AVL* insert(struct AVL* node, int data);
int height(struct AVL* node);
int balanceFactor(struct AVL* node);
int isAVL(struct AVL* node);
struct AVL* leftRotation(struct AVL* node);
#endif

