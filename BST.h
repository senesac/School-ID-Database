#ifndef BST_H
#define BST_H

#include <algorithm>
#include "TreeNode.h"
#include "Student.h"

template <typename T>
class BST{
    public:
        BST();
        virtual ~BST();
        bool iterContains(T d); 
        bool contains(T d); // recursive version that uses recContainsHelper
        void printInOrder(); // least to greatest 
        void printTreePostOrder(); // left tree then right tree then root 
				// lecture 18
        void insert(T d);
        int size(); 
        T maxN(); // right most child
        T minN(); // left most child 
        T median(); // will only work if tree is balanced 
        TreeNode<T>* find(T d);
        void remove (T d); 
        int getMaxDepth();
        int getMinDepth();
        bool checkDepthRatio();
         
    private: 
        TreeNode<T>* m_root;
        int m_size;
        bool recContainsHelper(TreeNode<T>* n, T d); 
        void printIOHelper(TreeNode<T>* n);
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
				// lecture 18
        void insertHelper(TreeNode<T>*& subTreeRoot, T& d, int depth);
        T getMaxHelper(TreeNode<T>* n);
        T getMinHelper(TreeNode<T>* n);
        TreeNode<T>* findHelper(TreeNode<T>* n, T d);
            // lecture 19 
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor (TreeNode<T>* rightChild);
        int getMDHelper(TreeNode<T>* n);
        int getMinDHelper(TreeNode<T>* n);
        // bool CDRHelper(TreeNode<T>* n);
};
   template <typename T>
        BST<T>::BST(){
        m_root = NULL;
        m_size = 0;
    }

    template <typename T>
    BST<T>::~BST(){
        // TO DO: free up all memory 
    }

    template <typename T>
    bool BST<T>::iterContains(T d){
        if (m_root == NULL){ // tree is empty
            return false; 
        }
        if (m_root -> data == d){ // root is the key d
            return true;
        }

        // look for d 
        bool found = false; 
        TreeNode<T>* current = m_root;
        while (!found){
            // check if d is greater than current go right 
            if (d > current -> m_data){
                current = current -> m_right;
            } else { // if d is less than/ == current go left 
                current = current -> m_left;
            } 
            // check if current node is NULL -> we've reached a leaf and d was not found
            if (current == NULL){
                found =  false; 
                break;
            }
            // check if the current node's data is d -> we found d 
            if (current -> m_data == d){
                found = true;
            }
        }
        return found;
    }

    template <typename T>
    bool BST<T>::contains(T d){
        return recContainsHelper(m_root, d);
    }

    // RECURSIVE CONTAINS HELPER
    template <typename T>
    bool BST<T>::recContainsHelper( TreeNode<T>* n, T d){
        if (n == NULL){ // if it is null then d is not in tree 
            return false;
        } 
        if (n -> m_data == d) { // if it is not null, is it here? 
            cout << n -> m_data;
            return true;
        }
        if (d > n -> m_data){ // it's not null but it's also not here, check if it is > or <
            return recContainsHelper( n->m_right, d);
        } else {
            return recContainsHelper( n->m_left, d);
        }
    }

    template <typename T>
    void BST<T>::printInOrder(){
        printIOHelper(m_root);
    }

    template <typename T>
    void BST<T>::printIOHelper(TreeNode<T>* n){
        if (n != NULL){ // is the node null? 
            printIOHelper(n->m_left); // if not then print the left thing 
            std::cout << n->m_data << std::endl; // then print the key of the curr node 
            printIOHelper(n->m_right); // then print the right thing 
        } 
    }

    template <typename T>
    void BST<T>::printTreePostOrder(){
        printTreePostOrderHelper(m_root);
    }

    template <typename T>
    void BST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
        if(subTreeRoot != NULL){
            printTreePostOrderHelper(subTreeRoot->m_left);
            printTreePostOrderHelper(subTreeRoot->m_right);
            std::cout << subTreeRoot->m_data << std::endl;
        }
    }

    template <typename T>
    void BST<T>::insert(T d){
        insertHelper(m_root, d, 0);
        ++m_size;

    }

    template <typename T>
    void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, T& d, int depth){
        if(subTreeRoot == nullptr && m_root != nullptr) {
            cout << "placing next node" << endl;
            subTreeRoot = new TreeNode<T>(d);
            cout << "setting m_depth to past depth";
            subTreeRoot->m_depth = depth;
            cout << "This is the depth of the new node" << subTreeRoot->m_depth;
        } else if (subTreeRoot == nullptr) {
            cout << "placing 1st node" << endl;
            subTreeRoot =  new TreeNode<T>(d); // insert here  & stop recursive call 
            subTreeRoot->m_depth = depth;
            cout << "This is the depth of the new node" << subTreeRoot->m_depth;
        } else if(d > subTreeRoot->m_data){
            cout << "node is larger than current subtreeroot" << endl;
            depth = subTreeRoot->m_depth;
            cout << depth << endl << "incrementing depth";
            depth += 1;
            cout << depth << endl;
            insertHelper(subTreeRoot->m_right, d, depth);
        } else{ 
            cout << "node is smaller than current subtreeroot" << endl;
            depth = subTreeRoot->m_depth;
            cout << depth << endl << "incrementing depth";
            depth += 1;
            cout << depth << endl;
            insertHelper(subTreeRoot->m_left, d, depth);
        }
    }

    template <typename T>
    int BST<T>::size(){
       return m_size;
    }

    template <typename T>
    T BST<T>::maxN(){
       return getMaxHelper(m_root);
    }

    template <typename T>
    T BST<T>::getMaxHelper(TreeNode<T>* n){
       if(n -> m_right == NULL){
        return n -> m_data;
       } else {
            return getMaxHelper(n -> m_right);
       }
       
    }

    template <typename T>
    T BST<T>::minN(){
       return getMinHelper(m_root);
    }

    template <typename T>
    T BST<T>::getMinHelper(TreeNode<T>* n){
       if(n -> m_left == NULL){
            return n -> m_data;
       } else {
            return getMinHelper(n -> m_left);
       }
       
    }

    template <typename T>
    T BST<T>::median(){
        //check if empty we assume it is a non-empty tree
        return m_root->m_data;
    }

    template <typename T>
    TreeNode<T>* BST<T>::find(T d) {
        return findHelper(m_root, d);
    }

    template <typename T>
    TreeNode<T>* BST<T>::findHelper(TreeNode<T>* n, T d) {
        if (n -> m_data == d) { // if it is not null, is it here? 
            return n;
        }
        if (d > n -> m_data){ // it's not null but it's also not here, check if it is > or <
            return findHelper( n->m_right, d);
        } else {
            return findHelper( n->m_left, d);
        }
    }

    template <typename T>
    void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
        // FIND THE NODE WE WANT TO DELETE AND ITS PARENT NODE 
        while (target != NULL && target -> m_data != key){ // while target still has children and it is not our actual target
            parent = target; 
            if (key < target -> m_data){ // if the key is less than the current target node, keep going left
                target = target -> m_left; 
            } else {
                target = target -> m_right;
            }
        }
    }

    template <typename T>
    TreeNode<T>* BST<T>::getSuccessor (TreeNode<T>* rightChild){
        while (rightChild -> m_left != NULL){ // If the node coming in (rightChild) doesn't have a left child then this is our successor and we're done, else:
            rightChild = rightChild -> m_left;
        }
        return rightChild; // not really (necessarily) a right child, this is the successor! 
    }

    template <typename T>
    void BST<T>::remove(T d){
        TreeNode<T>* target = NULL; 
        TreeNode<T>* parent = NULL; 
        target = m_root;
        // find the target 
        findTarget(d, target, parent); // no need save under any variables, target and parent are redefined bc we passed them in by reference  
        
        // target value was not found - it does not exist in our tree
        if (target == NULL){
            return;
        }
        // SCENARIO 1: TARGET IS A LEAF (INCLUDING ROOT)
        if (target -> m_left == NULL && target -> m_right == NULL){
            if (target == m_root){
                m_root = NULL;
            } else { // if it's a leaf but not the root 
                // check if target is its parent's left or right child 
                if (target == parent -> m_left){ // if target is a left child
                    parent -> m_left = NULL;
                } else { // target is a right child 
                    parent -> m_right = NULL;
                }
            }
            delete target;
				-- m_size;
        } 

        else if (target -> m_left != NULL && target -> m_right != NULL){  // both children pointers are not null
            TreeNode<T>* suc = getSuccessor(target -> m_right);
            T value = suc -> m_data;
            remove(value); // goes in the BST remove method and removes the node w/ d = value
            target -> m_data = value;
        }
        else { 
            TreeNode<T>* child;
            // check whether target has a left or right child 
            if (target -> m_left != NULL){ // target has a left child 
                child = target -> m_left;
            } else{                        // target has a right child 
                child = target -> m_right;
            }

            if (target == m_root){
                m_root = child;
            } else {
                if (target == parent -> m_left){ // our target is a left child 
                    parent -> m_left = child; // make the parent's left child the target's child 
                } else {                       // our target is a right child 
                    parent -> m_right = child; // make the parent's right child the target's child 
                }
            }
            delete target;
						-- m_size;
        }
        
    }

    template <typename T>
    bool BST<T>::checkDepthRatio() {
        return ((getMaxDepth()/getMinDepth()) >= 1.5);
    }

    template <typename T>
    int BST<T>::getMaxDepth() {
        return getMDHelper(m_root);
    }

    template <typename T>
    int BST<T>::getMDHelper(TreeNode<T>* n) {
        if(n == nullptr){
            return 0;
        }
        else{
            int leftDepth = getMDHelper(n->m_left);
            int rightDepth = getMDHelper(n->m_right);
            return max(leftDepth, rightDepth) + 1;
        }
    }

    template <typename T>
    int BST<T>::getMinDepth() {
        return getMinDHelper(m_root);
    }

    template <typename T>
    int BST<T>::getMinDHelper(TreeNode<T>* n) {
        if(n == nullptr){
            return 0;
        }
        else{
            int leftDepth = getMinDHelper(n->m_left);
            int rightDepth = getMinDHelper(n->m_right);
            return min(leftDepth, rightDepth) + 1;
        }
    }
#endif