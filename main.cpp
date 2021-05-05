#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

void draw( RenderWindow& window ){
    window.clear(Color::Black);

    Font font;
    if(!font.loadFromFile("Arial.ttf"))
        return;

    Text text;
    text.setFont(font);
    text.setString("Hello my people");
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(320,280);

    window.draw(text);

    window.display();
}

int main() {

    auto resolution = Vector2f(800,600);
    RenderWindow window;
    window.create(VideoMode(resolution.x, resolution.y), "Test", Style::Default);
    window.setFramerateLimit(60);

    while (window.isOpen()){
        draw(window);
        Event event{};
        while (window.pollEvent(event))
            if(event.type == Event::Closed)
                window.close();
    }
    return 0;
}
