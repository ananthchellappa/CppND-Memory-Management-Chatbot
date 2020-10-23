#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
    _chatBot = nullptr;    // AC add
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // delete _chatBot;     // this is always deleted by the ChatLogic.. 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)    // incoming
{
    _parentEdges.push_back(edge);    // AC.. no change
    // _parentEdges.push_back( std::weak_ptr<GraphEdge> edge );    // AC add -- don't know if it's needed..
}

void GraphNode::AddEdgeToChildNode( std::unique_ptr<GraphEdge> edge) // AC from GraphEdge * outgoing
{
    // _childEdges.push_back(edge);    // AC .. how can this be retained? We need to push unique pointers!
    _childEdges.push_back( std::move( edge ) );    // AC add
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot) // AC Task 5 from ChatBot *
{
    // _chatBot = chatbot;     // can't do this with unique_ptr, right? AC Task 5
    _chatBot = std::move( chatbot );    // AC Task 5
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere( std::move(_chatBot) );    // AC Task 5
    // _chatBot = nullptr; // invalidate pointer at source // AC Task 5 -- with unique_ptr, should be auto'd
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();    // AC added .get() .. why isn't it ->get()?

    ////
    //// EOF STUDENT CODE
}