#include "Entity.hpp"

Entity::~Entity() {
    for(auto const &c : m_components) {
        m_components.erase(c.first);
    }
}

Entity::Components Entity::getComponents() {
    return m_components;
}
