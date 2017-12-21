#import "TreeNode.h"
#import <iostream>
using namespace std;

template <class T>
class BST
{
public:
  BST();
  ~BST();

  void insert(T value); //should be thinking templates though, not just int
  bool contains(T value);
  bool deleteNode(T value);

  bool isEmpty();
  TreeNode* getMin();//left most
  TreeNode* getMax();//right most

  TreeNode* getSuccessor(TreeNode* d); //for deleteNode, helper function

  //print method using traversal methods

private:
  TreeNode* root;


};


template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
BST<T>::~BST()
{
  //iterate and delete
  //linear
}

template <class T>
TreeNode* BST<T>::getMax()
{
  TreeNode* current = root;
  if(root == NULL)
  {
    return NULL;
  }

  while(current->right != NULL)
  {
    current = current->right;
  }

  return current; //returning the (pointer to the) node, not the actual value, then you can do what you want with the node
}

template <class T>
TreeNode* BST<T>::getMin()
{
  TreeNode* current = root;
  if(root == NULL)
  {
    return NULL;
  }

  while(current->left != NULL)
  {
    current = current->left;
  }

  return current; //returning the (pointer to the) node, not the actual value, then you can do what you want with the node
}

template <class T>
void BST<T>::insert(T value) //like a failed search, here it is done iteratively, but could be faster recursively
{
  TreeNode* node = new TreeNode(value);
  if (root == NULL)//tree is empty
  {
    root = node;
  }
  else
  {
    TreeNode* current = root; //start at the root
    TreeNode* parent; //empty for now

    while(true)
    {
      parent = current;
      if (value < current->key)
      {
        current = current->left;
        if(current == NULL)//found our position
        {
          parent->left = node;
          break;
        }//finish this on going to the right

      }
      else//go right
      {
        current = current->right;
        if(current == NULL)//found our position
        {
          parent->right = node;
          break;
        }
      }


    }
  }
}

template <class T>
bool BST<T>::contains(T value)//see if this value exists, or could be key
{
    if(root == NULL)
    {
      return false;
    }
    else
    {
      TreeNode* current = root; //always start at root

      while(current->key != value)
      {
          if(value < current->key)//go left
          {
            current = current->left;
          }
          else
          {
            current = current->right;
          }

          if (current == NULL)//if its gone through the whole tree without finding it
          {
            return false;
          }
      }
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T value)
{
    if(root == NULL)
    {
      return false;
    }

    TreeNode* current = root; //always start at root
    TreeNode* parent = NULL;
    bool isLeft; //which way the parent is pointing towards

    while(current->key != value)
    {
        parent = current;

        if(value < current->key) //go left
        {
            isLeft = true;
            current = current->left;
        }
        else //go right
        {
            isLeft = false;
            current = current->right;
        }

        if(current == NULL)
        {
          cout<<"going to delete "<<current->key<<endl;
          return false;
        }
    }
    //we found what needs to be deleted


    //case 1: no childeren
    if(current->left == NULL && current->right == NULL)
    {
      if(current == root)
          root = NULL;
      else if(isLeft) //need to delete it from the parent, and this shows which side to delete
      {
          parent->left = NULL;
      }
      else
      {
          parent->right = NULL;
      }
    }
    //case 2: has one child
    else if (current->right == NULL) //no right child
    {
        if(current == root)
            root = current->left;
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
          parent->right = current->left;
        }
    }
    else if (current->left == NULL) //no left child
    {
        if(current == root)
            root = current->right;
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else
        {
          parent->right = current->right;
        }
    }
    //case 3: has two children/////
    else
    {
        TreeNode* successor = getSuccessor(current);
        if(current == root)
        {
          root = successor;
        }
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
          parent->right = successor;

        successor->left = current->left;
    }

    current->right = NULL;
    current->left = NULL;

    return true;

}
//a node ALWAYS has a KEY, sometimes it will have a different value too, in this case we just have KEY

template <class T>
TreeNode* BST<T>::getSuccessor(TreeNode* d) //the one in the parenthesis is the one we're going to delete
{
  TreeNode* sp = d; //successor's parentss
  TreeNode* successor = d; //will be one right, all the way left
  TreeNode* current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;

}
