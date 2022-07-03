#include "graphnode.h"
#include "graphedge.h"

GraphEdge::GraphEdge(int id)
{
    _id = id;
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}

// destructor
GraphEdge::~GraphEdge()
{
    _id = -1;
    _childNode = nullptr;
    _parentNode = nullptr;
    _keywords.clear();
}

// copy constructor
GraphEdge::GraphEdge(const GraphEdge &source)
{
    std::cout << "GraphEdge Copy" << std::endl;
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    _keywords = source._keywords;
}

// assignment operator
GraphEdge &GraphEdge::operator=(const GraphEdge &source)
{
    std::cout << "GraphEdge Assignment" << std::endl;
    if(this == &source)
        return *this;

    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    _keywords = source._keywords;

    return *this;
}

// move contructor
GraphEdge::GraphEdge(GraphEdge &&source)
{
    std::cout << "GraphEdge Move" << std::endl;
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    _keywords = source._keywords;

    source._childNode = nullptr;
    source._parentNode = nullptr;
    source._id = -1;
    source._keywords.clear();
}

// move assignment operator
GraphEdge &GraphEdge::operator=(GraphEdge &&source)
{
    std::cout << "GraphEdge Move Assignment" << std::endl;
    if(this == &source)
        return *this;
    
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    _keywords = source._keywords;

    source._childNode = nullptr;
    source._parentNode = nullptr;
    source._id = -1;
    source._keywords.clear();

    return *this;
}