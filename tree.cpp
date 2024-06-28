//  Basic operations in TREE

#include<bits/stdc++.h>
using namespace std;

bool findElementInBinaryTree(TreeNode* root, int x)
{
    if(root==nullptr)
    {
        return false;
    }
    else{

        // check current node
        if(root->val == x)
        {
            return true;
        }
        else 
        {
            //finding in left sub-tree
            if(findElementInBinaryTree(root->left,x))
            {
                return true;
            }
            else if(findElementInBinaryTree(root->right,x))
            {
                return true;
            }
            

        }

    }
}



//  function for BFS
vector<vector<int>> BFSTraversal(TreeNode* root)
{
    vector<vector<int>> ans;
    if(root==nullptr)
        return ans;
    queue<TreeNode*> q;
    q.push_back(root);
    while(!q.empty())
    {   
        vector<int> v;
        int s=q.size();
        for(int i=0;i<s;i++)
        {   
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
                q.push_back(node->left);
            }
            if(node->right)
            {
                q.push_back(node->right);
            }
            v.push_back(node->val);
        }
        ans.push_back(v);
    }
    return ans;
}

// function to find the number of LEAF nodes

// code stays same for finding full nodes or half nodes only CONDITION CHANGES

int numberOfLeafNodes(TreeNode* root)
{
    int n=0;
    if(root==nullptr)
    {
        return 0;
    }
    queue<TreeNode*> q;
    q.push_back(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node->left==nullptr && node->right==nullptr)     // this CONDITION changes accordingly 
        {
            n++;
        }
        else
        {
            if(node->left)
            {
                q.push_back(node->left);
            }
            if(node->right)
            {
                q.push_back(node->right);
            }
        }
    }
    return n;
}

//  maximum LEVEL SUM in a binary tree


