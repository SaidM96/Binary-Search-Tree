/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:43:00 by smia              #+#    #+#             */
/*   Updated: 2022/11/26 17:07:04 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct BSTnode
{
        int _data;
        BSTnode* _right;
        BSTnode* _left;
};

BSTnode* NewNode(int data)
{
    BSTnode* New;
    New = new BSTnode;
    New->_data = data;
    New->_left = NULL;
    New->_right = NULL;
    return New;
}

BSTnode* insert(BSTnode* root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
        std::cout << root->_data << " has inserted in tree " << std::endl;
        return root;
    }
    else if (data <= root->_data)
    {
        root->_left = insert(root->_left, data);
    }
    else
    {
        root->_right = insert(root->_right, data);
    }
    return root;
}

bool Search(BSTnode* root, int data)
{
    if (root == NULL)
    {
        std::cout << data <<" is Not found in tree" << std::endl;
        return false;
    }
    else if  (root->_data == data)
    {
        std::cout << root->_data << " Found" << std::endl;   
        return true;
    }
    else if (root->_data >= data)
    {
        return (Search(root->_left, data));
    }
    else 
    {
        return (Search(root->_right, data));
    }
}



BSTnode* Delete(BSTnode* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->_data)
        root->_left = Delete(root->_left, data);
    else if (data > root->_data)
        root->_right = Delete(root->_right, data);
        
    else // we should delete  that node  
    {
        if (root->_left == NULL && root->_right == NULL) // case: 1 : no children 
        {
            // we are safe we just need to delete that node 
            delete root;
            root = NULL;
            return root;
        }
        else if (root->_left == NULL) // case 2 : only right child  exist
        {
            BSTnode* tmp = root;
            root = root->_right;
            delete tmp;
        }
        else if (root->_right == NULL) // case 3 : only left child exist
        {
            BSTnode* tmp = root;
            root = root->_left;
            delete tmp;
        }
        else  // case 4 : right and left child exist
        {
            BSTnode* tmp = root->_right;
            root->_data = tmp->_data;
            root->_right = Delete(root->_right, tmp->_data);
        }
    }
    return root;
}



int main()
{
    // Creat an empty tree
    BSTnode* root = NULL; 
    
    // Fill our tree with numbers
	root = insert(root,12);
	root = insert(root,15);	
	root = insert(root,5);
	root = insert(root,13);
	root = insert(root,17);
	root = insert(root,14);
    root = insert(root,20);
    root = insert(root,18);
 	root = insert(root,3);
	root = insert(root,7);
    root = insert(root,1);
    root = insert(root,9);
	root = insert(root,8);
	root = insert(root,11);

    //  check if all numbers are in tree
Search(root,12);
Search(root,15);
Search(root,5);
Search(root,13);
Search(root,17);
Search(root,14);
Search(root,20);
Search(root,18);
Search(root,3);
Search(root,7);
Search(root,1);
Search(root,9);
Search(root,8);
Search(root,11);

    // delete some numbers 
	root = Delete(root,15);	
	root = Delete(root,12);
	root = Delete(root,17);
    root = Delete(root,18);
 	root = Delete(root,3);
    root = Delete(root,1);
	root = Delete(root,11);

    // check if all deleted numbers are realy deleted from tree
	Search(root,15);	
	Search(root,12);
	Search(root,17);
    Search(root,18);
 	Search(root,3);
    Search(root,1);
	Search(root,11);
    // 
}

