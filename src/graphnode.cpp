#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // deletion was handled in chatlogic. Now made into a static object.
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// owns all the child edges
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    // transfer of ownership to object in vector
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////

// change in function signature to make _chatbot an object in stack
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    // return raw pointer to avoid transfer ownership of the child edge
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}