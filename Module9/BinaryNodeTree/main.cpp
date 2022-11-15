// CS110C Prof Max Luttrell
// KristinaHelwing
// 103122
// This program adds nodes in random places to a binary tree

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h" // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string &anItem)
{
   cout << "Displaying item - " << anItem << endl;
} // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
} // end check/sso/default.aspx

int main()
{

   BinaryTreeInterface<string> *tree1 = new BinaryNodeTree<string>();

   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");

   cout << "Tree 1 Preorder: Should *NOT* be: 10 20 40 70 60 30 50 80\n";
   tree1->preorderTraverse(display);

   cout << "Tree 1 Inorder: Should *NOT* be: 70 40 20 60 10 50 30 80\n";
   tree1->inorderTraverse(display);

   //****COMMENTING OUT ORIGINAL SAMPLE CODE****
   // //cout<<"Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10\n";
   // //tree1->postorderTraverse(display);

   // cout << "Tree 1 height: " << tree1->getHeight() << endl;
   // cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;

   // cout << "Remove the leaf 80: ";
   // bool success = tree1->remove("80");
   // check(success);

   // cout << "Try to remove the leaf 80 again: ";
   // success = tree1->remove("80");
   // check(success);

   // cout << "Remove the leaf 50: ";
   // success = tree1->remove("50");
   // check(success);

   // cout<<"Tree 1 Preorder: Should be 10 20 40 70 60 30\n";
   // tree1->preorderTraverse(display);

   // cout<<"Tree 1 Inorder: Should be 70 40 20 60 10 30\n";
   // tree1->inorderTraverse(display);

   // //cout<<"Tree 1 Postorder: Should be 70 40 60 20 30 10\n";
   // //tree1->postorderTraverse(display);

   // cout << "Tree 1 height: " << tree1->getHeight() << endl;
   // cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;

   // cout << "Remove the node 40 that has only a left child: ";
   // success = tree1->remove("40");
   // check(success);

   // cout<<"Tree 1 Preorder: Should be 10 20 70 60 30\n";
   // tree1->preorderTraverse(display);

   // cout<<"Tree 1 Inorder: Should be 70 20 60 10 30\n";
   // tree1->inorderTraverse(display);

   // //cout<<"Tree 1 Postorder: Should be 70 60 20 30 10\n";
   // //tree1->postorderTraverse(display);

   // cout << "Tree 1 height: " << tree1->getHeight() << endl;
   // cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;

   // cout << "Remove the root 10 that has both left and right subtrees: ";
   // success = tree1->remove("10");
   // check(success);

   // cout<<"Tree 1 Preorder: Should be 20 60 70 30\n";
   // tree1->preorderTraverse(display);

   // cout<<"Tree 1 Inorder: Should be 70 60 20 30\n";
   // tree1->inorderTraverse(display);

   // //cout<<"Tree 1 Postorder: Should be 70 60 30 20\n";
   // //tree1->postorderTraverse(display);

   // cout << "Tree 2 height: " << tree1->getHeight() << endl;
   // cout << "Tree 2 number of nodes: " << tree1->getNumberOfNodes() << endl;

   BinaryTreeInterface<string> *tree2 = new BinaryNodeTree<string>();

   tree2->add("10");
   tree2->add("20");
   tree2->add("30");
   tree2->add("40");
   tree2->add("50");
   tree2->add("60");
   tree2->add("70");
   tree2->add("80");

   cout << "Tree 2 Preorder: Should *NOT* be: 10 20 40 70 60 30 50 80\n";
   tree1->preorderTraverse(display);

   cout << "Tree 2 Inorder: Should *NOT* be: 70 40 20 60 10 50 30 80\n";
   tree1->inorderTraverse(display);

   return 0;
} // end main

/*
NEW SAMPLE OUTPUT
 BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();

   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");

   cout<<"Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80\n";
   tree1->preorderTraverse(display);

   cout<<"Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80\n";
   tree1->inorderTraverse(display);

*/