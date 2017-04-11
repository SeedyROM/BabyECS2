#include "Component.hpp"
#include "Entity.hpp"

AbstractComponent::AbstractComponent() { }
AbstractComponent::~AbstractComponent() { }

void AbstractComponent::onAdd() { }
void AbstractComponent::update() { }
void AbstractComponent::draw() { }
void AbstractComponent::onRemove() { }
