#pragma once

#include <string>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>

struct AbstractComponent {
    const std::string name = "Component";

    AbstractComponent();
    virtual ~AbstractComponent();

    virtual void onAdd();
    virtual void update();
    virtual void draw();
    virtual void onRemove();
};

template<typename T>
struct Component : AbstractComponent {
    Component();
    T* getOwner();
    void setOwner(T* owner);

protected:
    T* m_owner;
};
#include "Component.inl"
