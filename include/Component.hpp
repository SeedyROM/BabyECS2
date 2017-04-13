#pragma once

#include <string>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>

#include "Demangle.hpp"

struct AbstractComponent {
    AbstractComponent() {}
    virtual ~AbstractComponent() {}

    virtual void onAdd();
    virtual void update();
    virtual void draw();
    virtual void onRemove();

    virtual const std::string getName() { return typeName(*this); }
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
