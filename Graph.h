#pragma once

#include <unordered_map>
#include "Node.h"

#ifndef GRAPHBASE
#define GRAPHBASE

namespace gtk {

	class Graph {

	protected:

		std::unordered_map<std::string, std::shared_ptr<Node>> nodes;

	public:

		/*
		* Adds a node for the graph
		* 
		* @PARAM
		* 
		* name: name of the node (should be unique)
		* 
		* @RETURN
		* returns true if the node added successfully, otherwise false
		*/
		bool AddNode(std::string name);

		/*
		* Adds an edge for the graph
		*
		* @PARAM
		*
		* parent: name of the node to insert into
		* child: name of the node to be inserted
		* weight: weight assigned to this edge
		*
		* @RETURN
		* returns true if the node added successfully, otherwise false
		*/
		virtual bool ConnectNodes(std::string parent, std::string child, double weight = 0) = 0;

		/*
		* Checks if node exists in this graph
		* 
		* @PARAM
		* 
		* name: node name to search about
		* 
		* @RETURN
		* 
		* true if the node exists, false otherwise
		*/
		bool HasNode(std::string name);

		/*
		* fetches a reference to an existing node in the graph
		* 
		* @PARAM
		* 
		* name: node name
		* 
		* @RETURN
		* A pointer to the node if exists, otherwise NULL
		*/
		std::shared_ptr<Node> FetchNode(std::string name);

		/*
		* @RETURN
		* 
		* A list of all vertecies names
		*/
		std::vector<std::string> Vertecies();

		friend std::ostream& operator<< (std::ostream& out, Graph* g);

	private:

	};

}

#endif // !GRAPHBASE
