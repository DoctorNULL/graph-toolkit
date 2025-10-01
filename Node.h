#pragma once

#include <string>
#include <vector>
#include <memory>
#include <ostream>

#ifndef GRAPHNODE
#define GRAPHNODE

namespace gtk {

	class Node;

	struct Edge {
		
		// Distenation of this edge
		std::shared_ptr<Node> distenation;

		// A weight to be used in weighted graphes
		double weight;

		// A meta data for the edge
		std::string meta = "";

		Edge() = delete; // No default Constructor
		Edge(const std::shared_ptr<Node>& node, double weight = 0, std::string meta = "");

		friend std::ostream& operator<< (std::ostream& out, const Edge& edge);
	};

	class Node {

		std::string name;
		std::vector<Edge> children;

	public:

		Node() = delete; // No defualt Constructor

		/*
		* Create a new node given a name and a weight
		* 
		* @PARAM
		* 
		* name: Node name
		* weight (optional): weight of Node
		*/
		Node(std::string name);

		/*
		* Checks if a child exists inside a node
		* 
		* @PARAM
		* 
		* name: name of child to search about
		* 
		* @RETURN
		* bool whether child exists or not
		*/
		bool HasChild(const std::string& name);

		/*
		* Gets a reference to the child if exists
		* 
		* @PARAM
		* 
		* name: child name to fetch
		* 
		* @RETURN
		* A reference to the child if exsits, otherwise returns NULL
		*/
		std::shared_ptr<Node> FetchChild(const std::string& name);

		/*
		* @RETURN
		* 
		* returns node name
		*/
		std::string Name();

		/*
		* @RETURN
		*
		* returns a list of node children names
		*/
		std::vector<std::string> Children();

		/*
		* Display node
		*/
		friend std::ostream& operator<< (std::ostream& out, std::shared_ptr<Node> node);

		/*
		* Adds a new child to the node
		*
		* @PARAM
		*
		* child: a pointer to a defined child
		*
		* @RETURN
		* boolean whether it successed or failed
		*/
		bool AddChild(std::shared_ptr<Node> child, double weight = 0, std::string meta = "");

		/*
		* @RETURN
		* The degree of this node
		*/
		size_t Degree();

		/*
		* @PARAM
		* name: the name of the child to get the weight from
		* 
		* @RETURN
		* Edge weight between node and child if exsits otherwise inf
		*/
		double ConnectionWeight(std::string name);

		/*
		* @PARAM
		* name: the name of the child to get the weight from
		*
		* @RETURN
		* Edge meta data between node and child if exsits otherwise empty
		*/
		std::string ConnectionMeta(std::string name);
	
	};

	std::ostream& operator<< (std::ostream& out, std::vector<std::string> strs);
}

#endif // !GRAPHNODE
