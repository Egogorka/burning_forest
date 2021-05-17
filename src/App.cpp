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

    Array<Array<int>> cells(20, Array<int>(20, 0));

                  cells[5][4] =
                                cells[6][5] =
    cells[4][6] = cells[5][6] = cells[6][6] = 1;

    automaton.setFrom(cells);
    automatonView.bind(automaton);
    automatonView.centerAt(Vector2f(window.getSize())/2.f);

    rules.set_weighter([](int state, int index){
        return state;
    });

    rules.set_processor([](int weight, int state){
        if( weight == 3 )
            return 1;
        if( weight == 2 and state == 1 )
            return 1;
        return 0;
    });
}

void App::on_loop() {
    window.clear(sf::Color::Black);
    window.draw(automatonView);
    window.display();
}

void App::on_event(sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Space){
            std::cout << "space!\n";
            automaton.update(rules);
        }
    }
//    if (event.type == sf::Event::MouseButtonPressed){
//        if(event.mouseButton.button == sf::Mouse::Left){
//            std::cout << "click!\n";
//            table.click(Vector2f(event.mouseButton.x,event.mouseButton.y));
//        }
//    }
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