#ifndef TreeNode_H
#define TreeNode_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class TreeNode{
public:
  TreeNode(T d);
  virtual ~TreeNode();
  T& getData();

  template <typename S>
  friend class BST;

private:
  T m_data;
  TreeNode<T>* m_left;
  TreeNode<T>* m_right;
  int m_depth;
  double m_maxDepth;
  double m_minDepth;
};

template <typename T>
TreeNode<T>::TreeNode(T d){
  m_data = d;
  m_left = NULL;
  m_right = NULL;
  m_depth = 0;
  m_maxDepth = -1;
  m_minDepth = -1;
}

template <typename T>
TreeNode<T>::~TreeNode(){
  if(m_left != NULL){
    delete m_left;
  }
  if(m_right != NULL){
    delete m_right;
  }
}

template <typename T>
T& TreeNode<T>::getData(){
  return m_data;
}

#endif