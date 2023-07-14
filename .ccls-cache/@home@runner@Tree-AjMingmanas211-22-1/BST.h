#include "node.h"
#include <iostream>
#include <iomanip>
using namespace std;

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all(int = 0);
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr, int);
};

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  if (new_node) {
    if (!rootPtr) {
      rootPtr = new_node;
    } else {
      t = rootPtr;
      while (inserted == 0) {
        if (value <= t->get_value()) {
          if (t->move_left() != NULL) {
            t = t->move_left();
          } else {
            t->set_left(new_node);
            inserted++;
          }
        } else {
          if (t->move_right() != NULL) {
            t = t->move_right();
          } else {
            t->set_right(new_node);
            inserted++;
          }
        }
      }
    }
    ++size;
  }
}

BST::BST() {
  rootPtr = NULL;
  size = 0;
}

BST::~BST() {
  cout << "Kill BST" << endl;
  kill(rootPtr);
}

void BST::inOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    inOrder(treePtr->move_left());
    cout << setw(3) << treePtr->get_value();
    inOrder(treePtr->move_right());
  }
}

void BST::printTree(TreeNodePtr treePtr, int level) {
  if (treePtr) {
    printTree(treePtr->move_right(), level + 1);
    for (int i = 0; i < level; i++)
      cout << "    ";
    cout << setw(3) << treePtr->get_value() << endl;
    printTree(treePtr->move_left(), level + 1);
  }
}

void BST::postOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    postOrder(treePtr->move_left());
    postOrder(treePtr->move_right());
    cout << setw(3) << treePtr->get_value();
  }
}

void BST::kill(TreeNodePtr treePtr) {
  if (treePtr) {
    kill(treePtr->move_left());
    kill(treePtr->move_right());
    delete treePtr;
  }
}

void BST::preOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    cout << setw(3) << treePtr->get_value();
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }
}

void BST::print_all(int option) {
  switch (option) {
    case 0:
      inOrder(rootPtr);
      cout << endl;
      break;
    case 1:
      preOrder(rootPtr);
      cout << endl;
      break;
    case 2:
      postOrder(rootPtr);
      cout << endl;
      break;
    default:
      cout << "inOrder" << endl;
      inOrder(rootPtr);
      cout << endl;
      cout << "preOrder" << endl;
      preOrder(rootPtr);
      cout << endl;
      cout << "postOrder" << endl;
      postOrder(rootPtr);
      cout << endl;
      cout << "Tree" << endl;
      printTree(rootPtr, 0);
      cout << endl;
  }
}
