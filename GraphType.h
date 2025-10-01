#pragma once
#include "Graph.h"

#ifndef GRAPHTYPES
#define GRAPHTYPES

namespace gtk {

	class UndirectedGraph : public Graph {

	public:

		// Inherited via Graph
		bool ConnectNodes(const std::string& parent,const std::string& child, double weight = 0, std::string meta = "") override;

	};

	class DirectedGraph : public Graph {

	public:

		// Inherited via Graph
		bool ConnectNodes(const std::string& parent, const std::string& child, double weight = 0, std::string meta = "") override;

	};

	class Tree : public Graph {

	public:

		// Inherited via Graph
		bool ConnectNodes(const std::string& parent, const std::string& child, double weight = 0, std::string meta = "") override;

	};

	class BinaryTree : public Tree {

		// Inherited via Graph
		bool ConnectNodes(const std::string& parent, const std::string& child, double weight = 0, std::string meta = "") override;

	};
}

#endif // !GRAPHTYPES
