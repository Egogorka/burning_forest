//
// Created by Meevere on 5/5/2021.
//

#ifndef BURNING_FOREST_APP_H
#define BURNING_FOREST_APP_H

#include "containers/array.h"
#include <SFML/Graphics.hpp>

#include "Automaton.h"
#include "AutomatonView.h"
#include "Rules.h"

using namespace containers;
using sf::Vector2f;

#define RESOLUTION_HEIGHT 800
#define RESOLUTION_WIDTH 800

#define RESOLUTION Vector2f(RESOLUTION_WIDTH, RESOLUTION_HEIGHT)

class App {
    Vector2f resolution;
    sf::RenderWindow window;

    // TODO: make it better, cuz what if i have more tables? then more variables? - bullshit
    AutomatonView automatonView;
    Automaton automaton;
    Rules rules;
public:
    App();

    void run();

protected:
    void before_loop();
    void on_loop();
    void on_event(sf::Event& event);
};

#endif //BURNING_FOREST_APP_H
