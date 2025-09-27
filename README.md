# Graph Toolkit

A lightweight **C++ graph library** that supports multiple types of graphs and provides efficient operations using an **adjacency list representation**.

## 🚀 Features

- ✅ **Directed Graphs**  
- ✅ **Undirected Graphs**  
- ✅ **Trees**  
- ✅ **Binary Trees**

Built with performance and flexibility in mind, `graph-toolkit` allows you to easily construct, traverse, and manipulate graphs.

---

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/DoctorNULL/graph-toolkit
cd graph-toolkit
copy those files and add for your c++ project
include GraphType.h and start creating
```

## 🔧 Example Usage

```cpp
int main() {

  // Create a graph in heap graph types could be (UndirectedGraph, DirectedGraph, Tree, BinaryTree)
	gtk::Graph* x = new gtk::Tree();
  
  // Adding vertecies to graph
	x->AddNode("Root");
	x->AddNode("X");
	x->AddNode("Y");
	
	x->AddNode("A");
	x->AddNode("B");
	x->AddNode("C");
	x->AddNode("D");

  // Adding Edges to Graph with resriction in each graph type
	x->ConnectNodes("Root", "X");
	x->ConnectNodes("Root", "Y");

	x->ConnectNodes("X", "A");
	x->ConnectNodes("X", "B");
	x->ConnectNodes("B", "Root"); // This cycle will not be included in Tree types and will have no meaning in undirected graph
	
	x->ConnectNodes("Y", "C");
	x->ConnectNodes("Y", "D");

  // Print Graph formated as ArrayList
	cout << x << endl;

  // Remove graph from heap memory
	delete x;

	return EXIT_SUCCESS;
}
```

```mathematica
B :
Root :  | - 0 -> X|  | - 0 -> Y |
X :  | - 0 -> A|  | - 0 -> B |
A :
Y :  | - 0 -> C|  | - 0 -> D |
C :
D :
```

## 🛠️ Docs

This library consists of 2 main types (Graph, Node)

A Graph class has the following functions
- `bool AddNode(string name)` Adds new node to the graph
- `bool ConnectNodes(string parent, string child, double weight)` Create an Edge in the graph
- `bool HasNode(string name)` Check if a Node exists in the graph
- `shared_ptr<Node> FetchNode(string name)` Fetch a node object from the graph
- `vector<string> Vertecies()` Get all vertecies from the graph

A Node class has the following functions
- `Node(string name)` Constructor
- `bool HasChild(string name)` Check if a Child with the given name exists
- `shared_ptr<Node> FetchChild(string name)` Fetch a node object from the children list of the node
- `string Name()` Getter for the name
- `vector<string> Children()` Getter for childrens
- `bool AddChild(shared_ptr<Node> child, double weight)` Adds a new child to a node
- `unsigned long long Degree()` Getter for the node degree



