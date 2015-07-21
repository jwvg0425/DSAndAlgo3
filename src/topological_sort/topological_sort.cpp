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

void topological_sort(Node* source)
{
    std::list<Node*> sortedList;
    
    topological_sort_node(source, sortedList);
    
    for(auto& node : sortedList)
    {
        printf("%d ",node->value);
    }
    printf("\n");
}

void topological_sort_node(Node* source, std::list<Node*>& sortedList)
{
	for (auto e : source->adj)
	{
		if (!e->visited)
		{
			e->visited = true;
			topological_sort(e, sortedList);
		}
	}
    
    sortedList.push_front(source);
}