// 20.12.13. 일
// 1991: 트리 순회 https://www.acmicpc.net/problem/1991
#include <iostream>
using namespace std;

struct Node
{
    char left;
    char right;
};

int n;
Node arr[27];

void preorder(char root)
{
    if (root == '.') return;
    cout << root;
    preorder(arr[root].left);
    preorder(arr[root].right);
}
void inorder(char root)
{
    if (root == '.') return;
    inorder(arr[root].left);
    cout << root;
    inorder(arr[root].right);
}
void postorder(char root)
{
    if (root == '.') return;
    postorder(arr[root].left);
    postorder(arr[root].right);
    cout << root;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    char a, b, c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');


    return 0;
}