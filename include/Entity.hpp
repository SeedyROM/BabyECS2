#pragma once

#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "Component.hpp"

struct Entity {
    typedef std::unordered_map< std::type_index, Component<Entity>* > Components;

    Entity() {}
    virtual ~Entity();

    Components getComponents();

    template<typename T, typename... Cs>
    void addComponent(Cs... cs);

    template<typename T>
    T* getComponent();

    template<typename T>
    void removeComponent();
protected:
    Components m_components;
};
#include "Entity.inl"
