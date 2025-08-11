#include "BST.h"


void BST::InsertNode(int value){
    // TODO: Implement this function to add a new node while maintaining BST properties.
    TreeNode *node = new TreeNode(value);
    if (!root) {
        root = node;
        return;
    }
    TreeNode *now = root;
    while (now) {
        if (value < now->value) {
            if (now->leftChild) {
                now = now->leftChild;
            }
            else {
                now->leftChild = node;
                return;
            }
        }
        else if(value > now->value){
            if (now->rightChild) {
                now = now->rightChild;
            }
            else {
                now->rightChild = node;
                return;
            }
        }
    }
}


void BST::DeleteNode(int value){
    // TODO: Implement this function to remove a node and rearrange the tree correctly.
    // If the node has both a left and right child, the node should be replaced with the maximum value node from its left subtree.
    // Hint: Use SearchNode() 

    if (root == nullptr)return;

    TreeNode* node = SearchNode(value);
    if (node == nullptr)return;

    if (!node->leftChild && !node->rightChild) {
        TreeNode* parent = SearchParent(value, node);
//        cout << parent->value << " " << node->value << endl;
        if (parent == root) {
            root = nullptr;
            return;
        }
        if (parent->leftChild && parent->leftChild == node) {
            parent->leftChild = nullptr;
        }
        else if (parent->rightChild && parent->rightChild == node) {
            parent->rightChild = nullptr;
        }
        else {
        }
        delete node;
    }
    else if (node->leftChild && !node->rightChild) {
        TreeNode* parent = SearchParent(value, node);
        if (parent == nullptr) {
            return;
        }
        if (parent->leftChild && parent->leftChild == node) {
            parent->leftChild = node->leftChild;
        }
        else if (parent->rightChild && parent->rightChild == node) {
            parent->rightChild = node->leftChild;
        }
        delete node;
    }
    else if (node->rightChild && !node->leftChild) {
        TreeNode* parent = SearchParent(value, node);
        if (parent->leftChild && parent->leftChild == node) {
            parent->leftChild = node->rightChild;
        }
        else if (parent->rightChild && parent->rightChild == node) {
            parent->rightChild = node->rightChild;
        }
        delete node;
    }
    else {
        TreeNode* tmp = node->leftChild;
        while (tmp->rightChild) {
            tmp = tmp->rightChild;
        }
        //cout << node->value << " " << tmp->value << endl;
        int tmpval = tmp->value;
 //       cout << "tmpvalue is " << tmpval << endl;
        DeleteNode(tmpval);
        node->value = tmpval;
    }
}

TreeNode* BST::SearchNode(int value){
    // TODO: Implement search function to find and return the node with the given value.
    TreeNode* node = root;
    while (node && value != node->value) {
        if (value < node->value) {
            node = node->leftChild;
        }
        else {
            node = node->rightChild;
        }
    }
    return node;
}

TreeNode* BST::SearchParent(int value, TreeNode* node) {
    TreeNode* parent = root;
    while (parent != nullptr) {
        if (node == parent->leftChild) {
            break;
        }
        else if (node == parent->rightChild) {
            break;
        }
        else if (parent->value > node->value) {
            parent = parent->leftChild;
        }
        else if (parent->value < node->value) {
            parent = parent->rightChild;
        }
    }
    return parent;
}

void BST::PreOrder(TreeNode* node){
    //TODO: Implement preorder traversal and store result to preOrderAnswer.
    if (!node)return;
    preOrderAnswer.push_back(node->value);
    cout << node->value << " ";
    PreOrder(node->leftChild);
    PreOrder(node->rightChild);
}

void BST::InOrder(TreeNode* node){
    //TODO: Implement inorder traversal and store result to inOrderAnswer.
    if (!node)return;
    InOrder(node->leftChild);
    inOrderAnswer.push_back(node->value);
    cout << node->value << " ";
    InOrder(node->rightChild);
}

void BST::PostOrder(TreeNode* node){
    //TODO: Implement postorder traversal and store result to postOrderAnswer.
    if (!node)return;
    PostOrder(node->leftChild);
    PostOrder(node->rightChild);
    postOrderAnswer.push_back(node->value);
    cout << node->value << " ";
}

// Do not modify those function.
void BST::destroyTree(TreeNode* node) {
    if (!node) return;
    destroyTree(node->leftChild);
    destroyTree(node->rightChild);
    delete node;
}

// Do not modify those function.
void BST::clear(){
    preOrderAnswer.clear();
    inOrderAnswer.clear();
    postOrderAnswer.clear();
    destroyTree(root);
    root = nullptr;
}

// Do not modify those function.
void BST::Output(ofstream& out){
    // Execute.
    PreOrder(root);cout << endl;
    InOrder(root);cout << endl;
    PostOrder(root);cout << endl;

    // Output the reuslt of traversals.
    out << "PreOrder traversal:";
    for(unsigned int i = 0; i < preOrderAnswer.size(); i++){
        out << preOrderAnswer[i];
        if(i < preOrderAnswer.size() - 1)
            out << ",";
        else
            out << "\n";
    }

    out << "InOrder traversal:";
    for(unsigned int i = 0; i < inOrderAnswer.size(); i++){
        out << inOrderAnswer[i];
        if(i < inOrderAnswer.size() - 1)
            out << ",";
        else
            out << "\n";
    }

    out << "PostOrder traversal:";
    for(unsigned int i = 0; i < postOrderAnswer.size(); i++){
        out << postOrderAnswer[i];
        if(i < postOrderAnswer.size() - 1)
            out << ",";
        else
            out << "\n";
    }
}

/*

        TreeNode* parent = SearchParent(value, node);
        int tmp = node->rightChild->value;
        DeleteNode(tmp);
        node->value = tmp;
*/