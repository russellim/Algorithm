// 20.11.04. 수
// 2019_길 찾기 게임 https://programmers.co.kr/learn/courses/30/lessons/42892
// 이진탐색트리.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, vector<int> > P;	// 노드번호, 좌표.

template <class T>
class Tree;

// 노드 하나가 이렇게 구성됩니다. Tree 클래스에 써줄것이에용.
template <class T>
class TreeNode
{
	friend class Tree<T>;
private:
	T data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(T data = 0, TreeNode* left = 0, TreeNode* right = 0)
		: data(data), left(left), right(right) { }
};

// Tree 만들기!.
template <class T>
class Tree
{
private:
	TreeNode<T>* root;
public:
	vector<int> search; // 탐색한순서 반환할 벡터칭구.

	// 생성하면서 루트도 같이 만들어주기.
	Tree(T data = 0)
	{
		root = new TreeNode<T>(data);
	}

	// 노드 추가 (부모보다 작으면 왼, 크면 오).
	void insertNode(TreeNode<T>* node)
	{
		TreeNode<T>* parent = 0;
		TreeNode<T>* current = root;
		// 타고타고 끝까지 내려갑니다.
		while (current != 0)
		{
			parent = current;
			if ((node->data).second[0] < (parent->data).second[0])
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}
		// 끝 만나면 그 자리 밑에 추가하기.
		if ((node->data).second[0] < (parent->data).second[0])
		{
			parent->left = node;
		}
		else
		{
			parent->right = node;
		}
	}

	TreeNode<T>* getRoot()
	{
		return root;
	}

	void clearSearch()
	{
		search.clear();
	}

	void visit(TreeNode<T>* current)
	{
		search.push_back(current->data.first);
	}

	// 전위순회.
	void preorder(TreeNode<T>* current)
	{
		if (current != 0)
		{
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}
	// 후위순회.
	void postorder(TreeNode<T>* current)
	{
		if (current != 0)
		{
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
};

// 좌표위치에 따라 순서대로 재배열 (y 큰거 우선 같으면 x 큰거).
bool comp(P& a, P& b)
{
	if (a.second[1] > b.second[1]) return true;
	if (a.second[1] == b.second[1])
	{
		return a.second[0] < b.second[0];
	}
	return false;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<P> nodes;
	for (int i = 0; i < nodeinfo.size(); ++i)
	{
		nodes.push_back({ i + 1, nodeinfo[i] });
	}

	sort(nodes.begin(), nodes.end(), comp);

	Tree<P> tree(nodes[0]);
	for (int i = 1; i < nodes.size(); ++i)
		tree.insertNode(new TreeNode<P>(nodes[i]));

	tree.preorder(tree.getRoot());
	answer.push_back(tree.search);

	tree.clearSearch();

	tree.postorder(tree.getRoot());
	answer.push_back(tree.search);

	return answer;
}

int main()
{
	vector<vector<int>> v = solution({ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} });

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}