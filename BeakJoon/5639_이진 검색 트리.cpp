// 21.03.15. 월
// 5639: 이진 검색 트리 https://www.acmicpc.net/problem/5639
// 트리 순회.
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_5639
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
		int pointer = 0;

		void Push(int n)
		{
			TreeNode* newNode = new TreeNode(n);
			tree.push_back(newNode);
			if (tree.size() != 1)
			{
				auto pointer = tree[0];
				while (1)
				{
					if (n < pointer->value)
					{
						if (pointer->left != nullptr) pointer = pointer->left;
						else
						{
							pointer->left = newNode;
							break;
						}
					}
					else
					{
						if (pointer->right != nullptr) pointer = pointer->right;
						else
						{
							pointer->right = newNode;
							break;
						}
					}
				}
			}
		}

		void PrintNode(int v)
		{
			cout << v << "\n";
		}

		// 후위 순회.
		void Postorder(TreeNode* t)
		{
			if (t == nullptr) return;
			Postorder(t->left);
			Postorder(t->right);
			PrintNode(t->value);
		}
	};

	void solution()
	{
		Tree t;
		int temp;
		while (cin >> temp)
		{
			t.Push(temp);
		}

		t.Postorder(t.tree[0]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	BOJ_5639::solution();

	return 0;
}