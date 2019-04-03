#include "pch.h"
#include "Message.h"
#include "Folder.h"


Message::Message(const Message& msg):
    contents(msg.contents),folders(msg.folders)
{
    add_to_Folders(msg);
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    
    return *this;
}

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(*this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(*this);
}

void Message::swap(Message& lhs, Message& rhs)
{
    using std::swap;    // not strictly needed in this case, but good habit

    for (auto f : lhs.folders) {
        f->remMsg(lhs);
    }
    for (auto f : rhs.folders) {
        f->remMsg(rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f : lhs.folders) {
        f->addMsg(lhs);
    }
    for (auto f : rhs.folders) {
        f->addMsg(rhs);
    }

    return;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::add_to_Folders(const Message& msg)
{
    for (auto f : msg.folders) {
        f->addMsg(*this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders) {
        f->remMsg(*this);
    }
}
