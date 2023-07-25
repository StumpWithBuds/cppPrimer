#include <iostream>
#include <string>
#include <vector>
#include <set>

class Folder {
public:
    Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();    
    
    void addMsg(Message*);
    void remMsg(Message*);

private:
    std::set<Message*> messages;  
};

void Folder::addMsg(Message* m) {
    messages.insert(m);
}

void Folder::remMsg(Message* m) {
    messages.erase(m);
}

class Message{
    friend class Folder;
public:
    Message();
    Message(const std::string &str): contents(str) {}
    Message(const Message&);
    Message& operator= (const Message&);
    ~Message();
    Message(Message&&);
    Message& operator=(Message&&);

    void save(Folder*);
    void remove(Folder*);
    void move_Folders(Message*);

    friend void swap(Message&, Message&);

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folder(const Message&);
    void remove_from_Folder(const Message&);
};

// 将消息添加到本消息的Folder中
void Message::add_to_Folder(const Message& m) {
    for(Folder* f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folder() {
    for(Folder* f : folders) {
        f->remMsg(this);
    }
}

Message::Message(const Message& m): contents(m.contents), folders(m.folders) {
    add_to_Folder(m);
}

Message::Message(Message&& m): contents(std::move(m.contents)) {
    move_Folders(m);
}

Message& Message::operator= (const Message& rhs) {
    remove_from_Folder();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folder(*this);
    return *this;
}

Message::~Message() {
    remove_from_Folder();
}

void Message::save(Folder* f) {
    folders.insert(f);
    f.addMsg(this);
}

void Message::remove(Folder* f) {
    folders.erase(f);
    f.remMsg(this);
}

void Message::move_Folders(Message* m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    
}

void swap(Message& lhs, Message& rhs) {
    using std::swap;
    for (auto f : lhs.folders) {
        f.remMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f.remMsg(&rhs);
    }
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f : lhs.folders) {
        f.addMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f.addMsg(&rhs);
    }
}

