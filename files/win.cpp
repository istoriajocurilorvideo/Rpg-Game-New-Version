#include "win.h"

sf::RenderWindow window;

sf::Event event;
//Sprite.Resize(VideoMode.X, VideoMode.Y);
int sleepValue = 0;

void initWindow(int width, int height, char *title) {
    srand (time(NULL));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    window.create(sf::VideoMode(width, height), title, sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void runGameLoop() {
    while(window.isOpen()) {
        window.clear();
        loop();
        window.display();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            if (event.type==sf::Event::Closed || event.key.code==sf::Keyboard::Escape) {
                window.close();
            }
        }
        Sleep(sleepValue);
    }
}

void setSleep(int a) {
    sleepValue = a;
}

int getWinWidth() {
    return window.getSize().x;
}

int getWinHeight() {
    return window.getSize().y;
}
