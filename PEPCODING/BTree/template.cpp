#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right, *left;
    TreeNode(int val) : val(val), left(NULL), right(NULL){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree(vector<int> nums)
    {
        if (nums.size() == 0)
            return;
        this->root = new TreeNode(nums[0]);
        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});
        for (auto a : nums)
        {
            assert(!s.empty()); // checking stack is not empty
            if (a == -1)
            { // vector cannot contain null, so -1 marks null
                s.top().second++;
                continue;
            }

            int state = s.top().second;
            if (state == 1) // add to left
            {
                TreeNode *temp = new TreeNode(a);
                s.top().first->left = temp;
                s.top().second++;
                s.push({temp, 1});
            }
            else if (state == 2) // add to right
            {
                TreeNode *temp = new TreeNode(a);
                s.top().first->right = temp;
                s.top().second++;
                s.push({temp, 1});
            }
            else
                s.pop();
        }
    }
};

int main()
{
    BinaryTree tree({1, 2, 3, 4, 5, 6, 7});
    return 0;
}