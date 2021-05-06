#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

#include "headers/Table.h"

#define RESOLUTION_HEIGHT 600
#define RESOLUTION_WIDTH 800

#define RESOLUTION Vector2f(RESOLUTION_WIDTH, RESOLUTION_HEIGHT)

#define CENTER_HEIGHT RESOLUTION_HEIGHT/2
#define CENTER_WIDTH RESOLUTION_WIDTH/2

#define CENTER RESOLUTION/2.f

#define TABLE_SIZE 10
#define CELL_SIZE 30
#define CELL_MARGIN 3

void draw( RenderWindow& window, Table& table ){

    window.draw(table);

//    Font font;
//    if(!font.loadFromFile("Arial.ttf"))
//        return;
//
//    Text text;
//    text.setFont(font);
//    text.setString("Hello my people");
//    text.setCharacterSize(24);
//    text.setFillColor(Color::White);
//    text.setPosition(320,280);
//
//    window.draw(text);

}

int main() {

    Clock clock;



    auto resolution = RESOLUTION;
    RenderWindow window;
    window.create(VideoMode(resolution.x, resolution.y), "Test", Style::Default);
    window.setFramerateLimit(60);

    CyclicArray<CyclicArray<int>>
            cells = {{0,0,0},
                     {0,0,0},
                     {0,0,0}};
    Table table(cells);

    table.centerAt(CENTER);

    while (window.isOpen()){
        auto time = clock.getElapsedTime();
        clock.restart();

        window.clear(Color::Black);
        draw(window, table);
        window.display();

        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else
            if (event.type == Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space){
                    table.update();
                    std::cout << "space!";
                }
            }
        }
    }
    return 0;
}
