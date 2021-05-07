//
// Created by Meevere on 5/5/2021.
//

#include "App.h"

App::App() {

    resolution = RESOLUTION;
    window.create(sf::VideoMode(resolution.x, resolution.y), "Test", sf::Style::Default);
    window.setFramerateLimit(60);

}

void App::before_loop() {

    CyclicArray<CyclicArray<int>>cells(10, CyclicArray<int>(10,0));

                  cells[5][4] =
                                cells[6][5] =
    cells[4][6] = cells[5][6] = cells[6][6] = 1;
    table = Table(cells);
    table.centerAt(Vector2f(window.getSize())/2.f);
}

void App::on_loop() {
    window.clear(sf::Color::Black);
    window.draw(table);
    window.display();
}

void App::on_event(sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    } else
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Space){
            table.update();
        }
    }
}

void App::run() {
    before_loop();
    while (window.isOpen()){
        on_loop();
        sf::Event event{};
        while (window.pollEvent(event))
            on_event(event);
    }
}