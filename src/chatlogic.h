#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"
#include <memory> // for unique_ptr Task 3
#define CB_IMAGE "../images/chatbot.png"   // AC Task 5 -- not reqd but neater

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // std::vector<GraphNode *> _nodes; // AC Task 3
    std::vector< std::unique_ptr<GraphNode> > _nodes;   // AC Task 3


    // std::vector<GraphEdge *> _edges; // AC Task 4 - now owned by the nodes, not ChatLogic

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */