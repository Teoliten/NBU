#include <iostream>
#include <vector>

using namespace std;

// ------------ NODE ------------
class Node
{
public:
  Node(int id);
  void connect(int value, Node *other);
  int getId() const { return id; }

  const vector<pair<int, Node *>> &getConnectedNodes() const { return connectedNodes; }

private:
  int id;
  vector<pair<int, Node *>> connectedNodes; // connection value, and pointer to node
};                                          // Class Node

Node::Node(int id)
{
  this->id = id;
} // parameter constructor

void Node::connect(int value, Node *other)
{
  connectedNodes.push_back(make_pair(value, other));
} // connect

// ------------ NODE ------------

// ------------ NETWORK ------------
class Network
{
public:
  Network();
  ~Network();

  void addNode(int id, int value);
  void addConnection(int id, int id2, int value);
  void traverseNetwork();

private:
  vector<pair<int, Node *>> nodesInNetwork; // id, pointer to node
  int nodes;
  Node *root;
}; // Class Network

Network::Network()
{
  Node *rootNode = new Node(0);
  nodesInNetwork.push_back(make_pair(0, rootNode));
  nodes = 1;
  root = rootNode;
} // Constructor

Network::~Network()
{
  // Implement destructor if necessary
} // Destructor

void Network::addNode(int id, int value)
{
  // Create a new node
  bool found = false;
  Node *newNode = new Node(nodes);

  // Search for a node with the given ID in nodesInNetwork
  for (auto &pair : nodesInNetwork)
  {
    if (pair.first == id)
    {
      found = true;
      // Connect the newly created node to the found node
      newNode->connect(value, pair.second);
      pair.second->connect(value, newNode);
      break; // Exit loop since we found the node
    }
  }

  if (found)
  {
    // Increment the node count
    nodes++;

    // Add the new node to the nodesInNetwork vector
    nodesInNetwork.push_back(make_pair(nodes - 1, newNode));
  }
  else
  {
    cout << "addNode_err: connecting node not found" << endl;
  }
} // addNode

void Network::addConnection(int id, int id2, int value)
{
  Node *node1;
  Node *node2;

  bool f1 = false, f2 = false;

  for (auto &pair : nodesInNetwork)
  {
    if (pair.first == id)
    {
      node1 = pair.second; // link node1 to the found node
      f1 = true;
    }
    else if (pair.first == id2)
    {
      node2 = pair.second; // link node2 to the found node
      f2 = true;
    }
  }

  if (f1 && f2) // both nodes found and pointers saved
  {
    node1->connect(value, node2);
    node2->connect(value, node1);
  }
  else // didnt find both nodes
  {
    cout << "addConnection_err: nodes not found" << endl;
  }
} // addConnection

void Network::traverseNetwork()
{
  int currentNodeId = 0; // Start from the root node
  Node *currentNode = root;

  while (currentNodeId != 999)
  {
    // Display current node's ID and connected nodes with their associated values
    cout << "Current Node: " << currentNodeId << endl;
    cout << "Connected Nodes:" << endl;
    for (const auto &pair : currentNode->getConnectedNodes())
    {
      cout << "   Node ID: " << pair.second->getId() << ", Value: " << pair.first << endl;
    }
    cout << endl;

    // Ask user to choose a connected node or enter 999 to exit
    cout << "Enter the ID of the node you want to go to (or enter 999 to exit): ";
    cin >> currentNodeId;

    // Find the next node
    bool found = false;
    for (const auto &pair : currentNode->getConnectedNodes())
    {
      if (pair.second->getId() == currentNodeId)
      {
        currentNode = pair.second;
        found = true;
        break;
      }
    }

    // If the entered ID is not found among connected nodes, print error message
    if (!found && currentNodeId != 999)
    {
      cout << "Node not found among connected nodes!" << endl;
    }
  }
}

// ------------ MAIN ------------
int main()
{
  // Create a network
  Network network; // creates root node, id: 0

  // Add nodes
  network.addNode(0, 2);           // id:1
  network.addNode(0, 6);           // id:2
  network.addNode(1, 5);           // id:3
  network.addConnection(3, 2, 8);  // connecting node 2 and 3, with value of 8
  network.addNode(3, 10);          // id:4
  network.addNode(4, 6);           // id:5
  network.addNode(4, 2);           // id:6
  network.addConnection(3, 5, 15); // connecting node 3 and 5, with value of 15
  network.addConnection(5, 6, 6);  // connecting node 5 and 6, with value of 6

  // Traverse the network
  network.traverseNetwork();

  return 0;
} // main
