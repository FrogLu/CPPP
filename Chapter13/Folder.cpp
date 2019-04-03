#include "pch.h"
#include "Message.h"
#include "Folder.h"


Folder::Folder(const Folder& folder):
    name(folder.name),msgs(folder.msgs)
{
    addMessages(folder);
}

Folder& Folder::operator=(const Folder& rhs)
{
    removeMessages();
    msgs = rhs.msgs;
    addMessages(rhs);

    return *this;
}

void Folder::addMsg(Message& msg)
{
    msgs.insert(&msg);
    //msg.save(*this);

    return;
}

void Folder::remMsg(Message& msg)
{
    msgs.erase(&msg);
    //msg.remove(*this);

    return;
}

void Folder::print()
{
    std::cout << "Folder " << name << ": " << std::endl;
    int count = 1;
    for (auto msg : this->msgs) {
        std::cout << "\tMessage " << count << " : " << std::endl;
        std::cout << "\t\t" << msg->contents << std::endl;
        count++;
    }
}

void Folder::addMessages(const Folder& folder)
{
    for (auto msg : folder.msgs) {
        msg->folders.insert(this);
    }
}

void Folder::removeMessages()
{
    while (!msgs.empty()) {
        (*msgs.begin())->remove(*this);
    }
}


Folder::~Folder()
{
    removeMessages();
}
