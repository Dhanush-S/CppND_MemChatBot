#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <vector>
#include <string>
#include <memory>
#include <iostream>

class GraphNode; // forward declaration

class GraphEdge
{
private:
    // data handles (not owned)
    GraphNode *_childNode;
    GraphNode *_parentNode;

    // proprietary members
    int _id;
    std::vector<std::string> _keywords; // list of topics associated with this edge
    

public:
    // constructor / desctructor
    GraphEdge(int id);
    ~GraphEdge();                                   // destructor
    GraphEdge(const GraphEdge &source);             // copy constructor
    GraphEdge &operator=(const GraphEdge &source);  // assignment operator
    GraphEdge(GraphEdge &&source);                  // move condtructor
    GraphEdge &operator=(GraphEdge &&source);       // move assignment operator

    // getter / setter
    int GetID() { return _id; }
    void SetChildNode(GraphNode *childNode);
    void SetParentNode(GraphNode *parentNode);
    GraphNode *GetChildNode() { return _childNode; }
    std::vector<std::string> GetKeywords() { return _keywords; }

    // proprietary functions
    void AddToken(std::string token);
};

#endif /* GRAPHEDGE_H_ */