template<typename T>
Component<T>::Component() { }

template<typename T>
T* Component<T>::getOwner() {
    return m_owner;
}

template<typename T>
void Component<T>::setOwner(T* _owner) {
    m_owner = _owner;
}
