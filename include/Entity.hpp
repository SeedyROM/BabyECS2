#pragma once

#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <memory>

#include "Component.hpp"

struct Entity {
    typedef std::unordered_map< std::type_index, Component<Entity>* > Components;

    virtual ~Entity() {}
    Components getComponents();

    template<typename T, typename... Cs>
    void addComponent(Cs... cs);

    template<typename T>
    T* getComponent();
protected:
    Components m_components;
};
#include "Entity.inl"
