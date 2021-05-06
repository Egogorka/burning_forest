#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

#define RESOLUTION_HEIGHT 600
#define RESOLUTION_WIDTH 800

#define RESOLUTION Vector2f(RESOLUTION_WIDTH, RESOLUTION_HEIGHT)

#define CENTER_HEIGHT RESOLUTION_HEIGHT/2
#define CENTER_WIDTH RESOLUTION_WIDTH/2

#define CENTER RESOLUTION/2.f


#define TABLE_SIZE 10
#define CELL_SIZE 30
#define CELL_MARGIN 3



/**
 * function that draws cell on the window
 * @param window
 * @param position - two numbers from 0 to TABLE_SIZE (not included)
 */
void draw_cell( RenderWindow& window, Vector2i position, int cell_type){
    Vector2f temp(CELL_SIZE, CELL_SIZE);
    RectangleShape rect(temp);

    Vector2f real_position;
    real_position = CENTER - (Vector2f(position) - Vector2f(TABLE_SIZE, TABLE_SIZE) / 2.f) * float(CELL_SIZE + CELL_MARGIN) - rect.getSize()/2.f;
    rect.setPosition(real_position);

    switch (cell_type) {
        case 0: rect.setFillColor(Color::Green); break;
        case 1: rect.setFillColor(Color::Red); break;
        default: rect.setFillColor(Color::Cyan); break;
    }

    window.draw(rect);
}


void draw_table( RenderWindow& window ){
    for( int i=0; i<TABLE_SIZE; i++)
        for( int j=0; j<TABLE_SIZE; j++)
            draw_cell(window, Vector2i(i,j), 0);
}

void draw( RenderWindow& window ){

    draw_table(window);

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

    auto resolution = Vector2f(800,600);
    RenderWindow window;
    window.create(VideoMode(resolution.x, resolution.y), "Test", Style::Default);
    window.setFramerateLimit(60);

    while (window.isOpen()){
        window.clear(Color::Black);
        draw(window);
        window.display();

        Event event{};
        while (window.pollEvent(event))
            if(event.type == Event::Closed)
                window.close();
    }
    return 0;
}
