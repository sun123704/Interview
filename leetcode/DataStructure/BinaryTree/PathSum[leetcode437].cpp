struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL) return 0;
		int n = pathSumRecurse(root, sum);
		int l = pathSum(root->left, sum);
		int r = pathSum(root->right, sum);
		return n + l + r;
	}
	int pathSumRecurse(TreeNode* root, int sum) {
		if (root == NULL) return 0;
		int l = pathSumRecurse(root->left, sum - root->val);
		int right = pathSumRecurse(root->right, sum - root->val);
		return l + right + (root->val == sum ? 1 : 0);
	}
};

TreeNode *root = new TreeNode(1);
TreeNode *root2 = new TreeNode(2);
TreeNode *root3 = new TreeNode(3);
TreeNode *root4 = new TreeNode(4);
TreeNode *root5 = new TreeNode(5);
//test
#if 0
      1
	 / \
   null 2
		 \
		  3
		   \
		    4
			 \
			  5
#endif

int main() {
	root->right = root2;
	root2->right = root3;
	root3->right = root4;
	root4->right = root5;
	Solution s;
	std::cout << s.pathSum(root, 3);
}