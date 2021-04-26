// 21.04.26. 월
// 2263: 트리의 순회 https://programmers.co.kr/learn/courses/30/lessons/2263
// 트리.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_2263
{
	struct TreeNode
	{
		int value;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int v) : value(v), left(nullptr), right(nullptr) { }
	};
	struct Tree
	{
		vector<TreeNode*> tree;

		void SetNode(int value)
		{
			tree.push_back(new TreeNode(value));
		}
		void SetNode(int value, int left, int right)
		{
			if (value == left) tree[value]->left = nullptr;
			else tree[value]->left = tree[left];

			if (value == right) tree[value]->right = nullptr;
			else  tree[value]->right = tree[right];
		}

		void Preorder(TreeNode* node)
		{
			if (node == nullptr) return;
			cout << node->value << " ";
			Preorder(node->left);
			Preorder(node->right);
		}
	};

	int n;
	vector<int> inorder, postorder;
	Tree t;

	void FindChild(int instart, int inend, int poststart, int postend)
	{
		int parent = postorder[postend];
		int parentIndex = find(inorder.begin() + instart, inorder.begin() + inend + 1, parent) - inorder.begin();

		int left, right;
		
		if (parentIndex > instart)
		{
			left = postorder[poststart + parentIndex - instart - 1];
			FindChild(instart, parentIndex - 1, poststart, poststart + parentIndex - instart - 1);
		}
		else left = parent;

		if (parentIndex < inend)
		{
			right = postorder[postend - 1];
			FindChild(parentIndex + 1, inend, poststart + parentIndex - instart, postend - 1);
		}
		else right = parent;

		t.SetNode(parent, left, right);
	}

	void Solution()
	{
		cin >> n;
		inorder.assign(n, 0);
		postorder.assign(n, 0);
		for (int& x : inorder) cin >> x;
		for (int& x : postorder) cin >> x;
		for (int i = 0; i <= n; ++i) t.SetNode(i);

		FindChild(0, n - 1, 0, n - 1);

		// output.
		t.Preorder(t.tree[postorder[n-1]]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_2263::Solution();
}