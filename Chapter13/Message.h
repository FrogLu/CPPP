#pragma once
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

class Folder;
class Message
{
    friend class Folder;
public:
    //  constructor
    explicit Message(const std::string& str = "") :
        contents(str) {}
    Message(const Message& msg);
    Message& operator=(const Message& rhs);
    //  user function
    void save(Folder& f);
    void remove(Folder& f);
    void swap(Message& lhs, Message& rhs);
    void addFldr(Folder* f);
    void remFldr(Folder* f);
    //  destructor
    ~Message();
private:
    //  data
    std::string contents;
    std::set<Folder*> folders;
    //  function
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

#endif // !_MESSAGE_H_
