#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

#include "headers/Table.h"
#include "headers/App.h"

#define RESOLUTION_HEIGHT 600
#define RESOLUTION_WIDTH 800

#define RESOLUTION Vector2f(RESOLUTION_WIDTH, RESOLUTION_HEIGHT)

#define CENTER_HEIGHT RESOLUTION_HEIGHT/2
#define CENTER_WIDTH RESOLUTION_WIDTH/2

#define CENTER RESOLUTION/2.f

#define TABLE_SIZE 10

int main() {
    App app;
    app.run();
    return 0;
}
