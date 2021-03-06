#include "pch.h"
#include "Message.h"
#include "Folder.h"


Message::Message(const Message& msg):
    contents(msg.contents),folders(msg.folders)
{
    add_to_Folders(msg);
}

Message::Message(Message&& msg) noexcept    //  when <set> use move assignment operator, 
                                            //  may cause except, so don't use noexcept.
{
    move_Folders(msg);
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    
    return *this;
}

Message& Message::operator=(Message&& rhs) noexcept
{
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(rhs);
    }
    
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

void Message::addFldr(Folder* f)
{
    folders.insert(f);
}

void Message::remFldr(Folder* f)
{
    folders.erase(f);
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

void Message::move_Folders(Message& msg)
{
    folders = std::move(msg.folders);
    for (auto f : folders) {
        f->remMsg(msg);
        f->addMsg(*this);
    }
    msg.folders.clear();
}
