struct Node
{
	int data;

	Node* left = nullptr;
	Node* right = nullptr;
};

int count(Node* node)
{
	if (node == nullptr)
		return 0;

	return count(node->left) + count(node->right) + 1;
}