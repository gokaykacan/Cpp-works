//============================================================================
// Name        : CombinedThreePatternExample.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//
//  main.cpp
//  combined-patterns- Command - Observer - Chain of Responsibility
//

#include <iostream>
#include <vector>
#include <algorithm>

class Subscriber {
public:
	virtual ~Subscriber() {};
    virtual void notify(const std::string & publisherName, const std::string & message) = 0;
    virtual std::string getName() = 0;
};

class ChatUser : public Subscriber {
    std::string userName;
public:
    virtual ~ChatUser() {};
    ChatUser(const std::string & userName) : userName(userName) {};
    void notify(const std::string & publisherName, const std::string & message) override {
        std::cout << userName << " received a new message from " << publisherName << ": " << message << "\n";
    }
    std::string getName() override {
        return userName;
    }
};

class Publisher {
public:
	virtual ~Publisher() {};
    virtual void subscribe(Subscriber *subscriber) = 0;
    virtual void unsubscribe(Subscriber *subscriber) = 0;
    virtual void publish(const std::string & message) = 0;
};

class ChatGroup : public Publisher {
    std::string groupName;
    std::vector<Subscriber*> subscribers;
public:
    virtual ~ChatGroup() {};
    ChatGroup(const std::string & groupName) : groupName(groupName) {};
    void subscribe(Subscriber *subscriber) {
        this->subscribers.push_back(subscriber);
    }
    void unsubscribe(Subscriber *subscriber) {
        subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(), [subscriber](Subscriber *s){ return s->getName() == subscriber->getName(); }), subscribers.end());
    }
    void publish(const std::string & message) {
        for (auto subscriber : subscribers) {
            subscriber->notify(groupName, message);
        }
    }
};

class MessageCommand{
public:
	virtual ~MessageCommand() {};
	virtual void execute() = 0;
	virtual std::string getMessage() = 0;
};

class SendMessageCommand: public MessageCommand{
	ChatGroup* pChatGroup;
	std::string message;
public:
	SendMessageCommand(ChatGroup *chatgroup, std::string message ): pChatGroup(chatgroup), message(message) {};
	void execute() override{
		pChatGroup->publish( message );
	}
	std::string getMessage() override {
		return message;
	}
};

class Handler {
public:
    virtual Handler *setNext(Handler *nextValidator) = 0;
    virtual ~Handler() {};
    virtual std::string handle(SendMessageCommand *sendMessage ) = 0;
};

class BaseHandler : public Handler {
protected:
    Handler *next = nullptr;
public:
    ~BaseHandler() { delete next; };
    Handler *setNext(Handler *nextValidator) override {
        next = nextValidator;
        return nextValidator;
    }
    virtual std::string handle(SendMessageCommand *sendMessage) override {
        if (this->next) {
            return this->next->handle(sendMessage);
        }
        return "Success!";
    }
};

class NotEmptyValidator: public BaseHandler {
public:
    std::string handle(SendMessageCommand *sendMessage) override {
        std::cout << "Checking if empty...\n";

        if (sendMessage->getMessage().empty()) {
            return "Please enter a value";
        }

        return BaseHandler::handle(sendMessage);
    }
};

class LengthValidator: public BaseHandler {
    unsigned int minLength;
public:
    LengthValidator(int minLength) : minLength(minLength) {};
    std::string handle(SendMessageCommand *sendMessage) override {
        std::cout << "Checking if length equals " << minLength << "...\n";

        if (sendMessage->getMessage().length() < minLength) {
            return "Please enter a value longer than " + std::to_string(minLength);
        }

        return BaseHandler::handle(sendMessage);
    }
};

class PostMessageHandler: public BaseHandler {
public:
    std::string handle(SendMessageCommand *sendMessage) {
        sendMessage->execute();
        return "Message Sent!";
    }
};

int main(int argc, const char * argv[]) {
    ChatUser *user1 = new ChatUser("Jim");
    ChatUser *user2 = new ChatUser("Barb");
    ChatUser *user3 = new ChatUser("Hannah");

    ChatGroup *group1 = new ChatGroup("Gardening Group");
    ChatGroup *group2 = new ChatGroup("Dog-lovers Group");

    group1->subscribe(user1);
    group1->subscribe(user2);

    group2->subscribe(user2);
    group2->subscribe(user3);

    Handler *sendMessageChain = new BaseHandler;

    sendMessageChain
        ->setNext(new NotEmptyValidator)
        ->setNext(new LengthValidator(2))
        ->setNext(new PostMessageHandler);

    SendMessageCommand *sendEmptyMessage = new SendMessageCommand(group1, "");
    SendMessageCommand *sendShortMessage = new SendMessageCommand(group1, "H");
    SendMessageCommand *sendToGroup1 = new SendMessageCommand(group1, "Hello everyone in group 1!");
    SendMessageCommand *sendToGroup2 = new SendMessageCommand(group2, "Hello everyone in group 2!");

    std::cout << "Sending empty message:\n" << sendMessageChain->handle(sendEmptyMessage) << "\n\n";
    std::cout << "Sending short message:\n" << sendMessageChain->handle(sendShortMessage) << "\n\n";
    std::cout << "Sending message to group 1:\n" << sendMessageChain->handle(sendToGroup1) << "\n\n";
    std::cout << "Sending message to group 2:\n" << sendMessageChain->handle(sendToGroup2) << "\n\n";

    delete user1;
    delete user2;
    delete user3;
    delete group1;
    delete group2;
    delete sendMessageChain;
    delete sendEmptyMessage;
    delete sendShortMessage;
	delete sendToGroup1;
	delete sendToGroup2;
}


