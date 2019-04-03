#pragma once
#ifndef _FOLDER_H_
#define _FOLDER_H_

class Folder
{
public:
    //  constructor
    explicit Folder(const std::string str = "new Folder") :
        name(str), msgs(std::set<Message*>()) {};
    Folder(const Folder& folder);
    Folder& operator=(const Folder& rhs);
    //  user function
    void addMsg(Message& msg);
    void remMsg(Message& msg);
    void print();
    //  destructor
    ~Folder();
private:
    //  data
    std::string name;
    std::set<Message*> msgs;
    //  function
    void addMessages(const Folder& folder);
    void removeMessages();
};

#endif // !_FOLDER_H_


