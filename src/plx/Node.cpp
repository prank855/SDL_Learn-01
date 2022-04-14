#include "Node.h"
#include "Scene.h"
#include "Vec2.h"
void plx::Node::Update() {
    for (auto c : components) {
        c->Update();
    }
    for (auto n : children) {
        n->Update();
    }
}


/*
getWorldPosition(): Transform {
        if (this.parent == null) {
            return this.transform;
        }
        var tempTrans = new Transform();
        tempTrans.position = Vector2.Copy(
            this.parent.getWorldPosition().position
        ).add(this.transform.position);
        return tempTrans;
    }
*/

plx::Vec2 plx::Node::GetPosition() {
    if (parent == nullptr) {
        return position;
    } else {
        plx::Vec2 v;
        auto p = parent->GetPosition();
        v.x += p.x;
        v.y += p.y;
        return v;
    }
}

plx::Node* plx::Node::AddChild() {
    auto tempChild = scene->MakeNode();
    tempChild->parent = this;
    std::cout << tempChild->parent << " <-- Parent pointer\n";
    std::cout << this << " <-- Current pointer\n";
    tempChild->scene = scene;
    tempChild->name = "CHILD Node: " + std::to_string(tempChild->id);
    children.push_back(tempChild);
    std::cout << "ADDED " << tempChild->name << " TO " << tempChild->parent->name << std::endl;
    return tempChild;
}