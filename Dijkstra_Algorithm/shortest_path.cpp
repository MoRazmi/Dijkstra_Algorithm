#include "shortest_path.h"
#include "list.h"

using node = graph::node;


path::path()
{}

void path::path_add_node(node node_input)
{
	path_list.prepend(node_input);
}

