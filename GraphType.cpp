#include "GraphType.h"

bool gtk::UndirectedGraph::ConnectNodes(const std::string& parent, const std::string& child, double weight, std::string meta)
{
    if (!(this->HasNode(parent) && this->HasNode(child)))
        return false;

    if (this->FetchNode(parent)->FetchChild(child))
        return false;
    
    return this->FetchNode(parent)->AddChild(this->FetchNode(child), weight, meta) &&
        this->FetchNode(child)->AddChild(this->FetchNode(parent), weight, meta);
}

bool gtk::DirectedGraph::ConnectNodes(const std::string& parent, const std::string& child, double weight, std::string meta)
{
    if (!(this->HasNode(parent) && this->HasNode(child)))
        return false;

    if (this->FetchNode(parent)->FetchChild(child))
        return false;

    return this->FetchNode(parent)->AddChild(this->FetchNode(child), weight, meta);
}

bool gtk::Tree::ConnectNodes(const std::string& parent, const std::string& child, double weight, std::string meta)
{
    if (!(this->HasNode(parent) && this->HasNode(child)))
        return false;

    if (this->FetchNode(parent)->FetchChild(child))
        return false;

    std::vector<std::string> childChildren = this->FetchNode(child)->Children();

    for (size_t i = 0; i < childChildren.size(); i++)
    {
        // Prevent Cycles
        if (this->FetchNode(childChildren[i])->HasChild(parent) || this->FetchNode(child)->HasChild(parent))
            return false;
    }

    return this->FetchNode(parent)->AddChild(this->FetchNode(child), weight, meta);
}

bool gtk::BinaryTree::ConnectNodes(const std::string& parent, const std::string& child, double weight, std::string meta)
{
    if (!(this->HasNode(parent) && this->HasNode(child)))
        return false;

    if (this->FetchNode(parent)->Degree() >= 3)
        return false;

    return Tree::ConnectNodes(parent, child, weight, meta);
}
