template<typename T, typename... Cs>
void Entity::addComponent(Cs... cs) {
    m_components.emplace(typeid(T), new T(cs...));
    m_components.at(typeid(T))->setOwner(this);
    m_components.at(typeid(T))->onAdd();
}

template<typename T>
T* Entity::getComponent() {
    try {
        return static_cast<T*>(m_components.at(typeid(T)));
    }
    catch (const std::out_of_range &e) {
        std::cout << "Unable to get component with typename: " << typeid(T).name() << std::endl;
    }
}

template<typename T>
void Entity::removeComponent() {
    m_components.at(typeid(T))->onRemove();
    m_components.erase(typeid(T));
}
