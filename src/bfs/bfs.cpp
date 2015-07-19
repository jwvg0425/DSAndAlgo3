#include <vector>
#include <queue>

struct Node
{
	int data = 0;
	bool visited = false;
	std::vector<Node*> adj;
};

struct Graph
{
	std::vector<Node*> nodes;
};

void bfs(Graph* g)
{
	//nodes 0번째를 source로 생각
	Node* source = g->nodes[0];
	std::queue<Node*> q;

	source->visited = true;
	q.push(source);

	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();

		printf("data : %d \n", node->data);

		for (auto& adj : node->adj)
		{
			if (!adj->visited)
			{
				adj->visited = true;
				q.push(adj);
			}
		}
	}
}