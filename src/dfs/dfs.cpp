#include <stdio.h>
#include <vector>

struct Node
{
	Node(int value_, std::vector<Node*> adj_)
		:value(value_), adj(adj_)
	{
	}

	int value;
	std::vector<Node*> adj;
	bool visited = false;
};

void dfs(Node* source)
{
	printf("%d\n", source->value);

	for (auto e : source->adj)
	{
		if (!e->visited)
		{
			e->visited = true;
			dfs(e);
		}
	}
}