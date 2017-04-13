#include <SFML/Graphics.hpp>

#include <iostream>
#include <typeinfo>

#include "Entity.hpp"

struct TestComponent : Component<Entity> {
    void onAdd() override {
        std::cout << getName() << " has been added!" << std::endl;
    }
    void onRemove() override {
        std::cout << getName() << " has been removed!" << std::endl;
    }
};
struct MoveComponent : TestComponent { };

int main(int argc, char* arv[]) {
    sf::RenderWindow window(sf::VideoMode(600, 200), "Testing");

    Entity e;
    Entity e1;

    e.addComponent<TestComponent>();
    e.addComponent<MoveComponent>();

    for(auto &c : e.getComponents()) {
        std::cout << c.second->getName() << std::endl;
    }

    e.removeComponent<TestComponent>();
    e.removeComponent<MoveComponent>();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        window.clear(sf::Color::Red);
        window.display();
    }

    return 0;
}
