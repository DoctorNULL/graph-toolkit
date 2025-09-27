#include "Graph.h"

bool gtk::Graph::AddNode(std::string name)
{
	if (this->HasNode(name))
		return false;

	this->nodes[name] = std::make_shared<Node>(name);
	return true;
}

bool gtk::Graph::HasNode(std::string name)
{
	if (this->nodes.find(name) == this->nodes.cend())
		return false;

	return true;
}

std::shared_ptr<gtk::Node> gtk::Graph::FetchNode(std::string name)
{
	if (HasNode(name))
		return this->nodes[name];

	return nullptr;
}

std::vector<std::string> gtk::Graph::Vertecies()
{
	std::vector<std::string> res;
	res.resize(this->nodes.size());

	size_t i = 0;

	for (auto& item : this->nodes)
	{
		res[i] = item.first;
		i++;
	}

	return res;
}

std::ostream& gtk::operator<<(std::ostream& out, Graph* g)
{
	if (g)
	{
		auto vertecies = g->Vertecies();

		for (size_t i = 0; i < vertecies.size(); i++)
		{
			out << g->FetchNode(vertecies[i]);
		}
	}

	return out;
}
