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
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)    // AC Task 5
void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)   // AC Task 5
{
    // _chatBot = chatbot;     // AC Task 5 ... use of deleted fn..
    _chatBot = std::move( chatbot );    // AC Task 5
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere( std::move(_chatBot) );     // AC Task 5 from (_chatBot)
    // _chatBot = nullptr; // invalidate pointer at source  // AC Task 5 - smart ptr should do this auto
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