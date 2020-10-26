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

    // delete _chatBot; // Task 0 AC

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back( edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)    // AC Task 4
void GraphNode::AddEdgeToChildNode( std::unique_ptr<GraphEdge> edge )
{
    _childEdges.push_back( std::move(edge) ); //  AC Task 4
}

//// STUDENT CODE
////
// void GraphNode::MoveChatbotHere(ChatBot &chatbot)    // AC Task 5   from *chatbot
void GraphNode::MoveChatbotHere(ChatBot chatbot)    // AC Task 5   from &chatbot
{
    // _chatBot = chatbot; // AC Task 5  -- also works, but not using move semantics as proj asks
    _chatBot = std::move( chatbot );    // std::move nothing to do with smart ptr here - but to create lvalue from rvalue
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // newNode->MoveChatbotHere( _chatBot );    // also works, but not using move semantics
    newNode->MoveChatbotHere( std::move(_chatBot) ) ;    // AC Task 5
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();    // AC Task 4 added .get() to return raw

    ////
    //// EOF STUDENT CODE
}