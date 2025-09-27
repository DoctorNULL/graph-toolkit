#pragma once
#include "Graph.h"

#ifndef GRAPHTYPES
#define GRAPHTYPES

namespace gtk {

	class UndirectedGraph : public Graph {

	public:

		// Inherited via Graph
		bool ConnectNodes(std::string parent, std::string child, double weight = 0) override;

	};

	class DirectedGraph : public Graph {

	public:

		// Inherited via Graph
		bool ConnectNodes(std::string parent, std::string child, double weight = 0) override;

	};

	class Tree : public Graph {

	public:

		// Inherited via Graph
		bool ConnectNodes(std::string parent, std::string child, double weight = 0) override;

	};

	class BinaryTree : public Tree {

		// Inherited via Graph
		bool ConnectNodes(std::string parent, std::string child, double weight = 0) override;

	};
}

#endif // !GRAPHTYPES
