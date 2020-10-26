#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"
#include <memory>   // AC Task 4 for unique_ptr


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes // AC Task 4
    std::vector< std::unique_ptr< GraphEdge> > _childEdges; // AC Task 4

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot _chatBot;   // AC Task 5 was a pointer

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    // void AddEdgeToChildNode(GraphEdge *edge);  // AC Task 4
    void AddEdgeToChildNode( std::unique_ptr<GraphEdge> edge); // AC Task 4

    //// STUDENT CODE
    ////

    // void MoveChatbotHere(ChatBot *chatbot); // AC Task 5
    void MoveChatbotHere( ChatBot & chatbot);    // AC Task 5

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */