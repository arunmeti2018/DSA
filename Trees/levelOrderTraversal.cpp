#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class with level order traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->val);

                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Function to print the result
void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    TreeNode* root = createSampleTree();

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal:\n";
    printResult(result);

    return 0;
}
