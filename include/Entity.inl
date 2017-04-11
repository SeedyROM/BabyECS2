template<typename T, typename... Cs>
void Entity::addComponent(Cs... cs) {
    m_components.emplace(typeid(T), new T(cs...));
    getComponent<T>()->setOwner(this);
    getComponent<T>()->onAdd();
}

template<typename T>
T* Entity::getComponent() {
    return static_cast<T*>(m_components.at(typeid(T)));
}
