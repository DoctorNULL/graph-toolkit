#include "Node.h"

gtk::Node::Node(std::string name)
{
	this->name = name;
}

bool gtk::Node::AddChild(std::shared_ptr<Node> child, double weight)
{
	if (child == nullptr)
		return false;

	if (this->HasChild(child->name))
		return false;

	this->children.push_back(Edge(child, weight));
	return true;
}

size_t gtk::Node::Degree()
{
	return this->children.size();
}

double gtk::Node::ConnectionWeight(std::string name)
{
	for (size_t i = 0; i < children.size(); i++)
	{
		if (children[i].distenation->Name() == name)
			return children[i].weight;
	}

	return std::numeric_limits<double>::max();
}

bool gtk::Node::HasChild(const std::string& name)
{
	return this->FetchChild(name) != NULL;
}

std::shared_ptr<gtk::Node> gtk::Node::FetchChild(const std::string& name)
{
	for (size_t i = 0; i < this->children.size(); i++)
	{
		if (this->children[i].distenation->name == name)
			return this->children[i].distenation;
	}

	return nullptr;
}

std::string gtk::Node::Name()
{
	return this->name;
}

std::vector<std::string> gtk::Node::Children()
{
	std::vector<std::string> res;

	if (this->children.size())
	{
		res.resize(this->children.size());

		for (size_t i = 0; i < this->children.size(); i++)
		{
			res[i] = this->children[i].distenation->name;
		}
	}
	return res;
}

gtk::Edge::Edge(const std::shared_ptr<Node>& node, double weight)
{
	this->distenation = node;
	this->weight = weight;
}

std::ostream& gtk::operator<<(std::ostream& out, const Edge& edge)
{
	out << " - " << edge.weight << " -> " << edge.distenation->Name();

	return out;
}

std::ostream& gtk::operator<<(std::ostream& out, std::shared_ptr<Node> node)
{
	if (node == nullptr)
		return out;

	out << node->name << " : ";

	for (size_t i = 0; i < node->children.size(); i++)
	{
		out << " |" << node->children[i] << " | ";
	}

	out << std::endl;

	return out;
}

std::ostream& gtk::operator<<(std::ostream& out, std::vector<std::string> strs)
{
	if (strs.empty())
	{
		out << "()" << std::endl;
		return out;
	}

	out << "( " << strs[0];

	for (size_t i = 1; i < strs.size(); i++)
	{
		out << ", " << strs[i];
	}

	out << " )" << std::endl;

	return out;
}
