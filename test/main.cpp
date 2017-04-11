#include <SFML/Graphics.hpp>

#include <iostream>
#include <typeinfo>

#include "Entity.hpp"

struct TestComponent : Component<Entity> {
    const std::string name = "TestComponent";

    std::string field;

    // Pass variables arguments to constructors!
    TestComponent(const std::string _field) {
        field = _field;
    }

    void onAdd() override {
        std::cout << name << " has been added!" << std::endl;
    }
    void onRemove() override {
        std::cout << name << " has been removed!" << std::endl;
    }
};

int main(int argc, char* arv[]) {
    sf::RenderWindow window(sf::VideoMode(600, 200), "Testing");

    Entity e;

    e.addComponent<TestComponent>("ME!");
    std::cout << e.getComponent<TestComponent>()->getOwner() << std::endl;


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
