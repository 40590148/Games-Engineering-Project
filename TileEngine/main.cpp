#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>

sf::Texture spritesheet;
sf::RenderWindow window(sf::VideoMode({ 500, 300 }), "SFML works!");

void Load() {
    if (!spritesheet.loadFromFile("invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
}

void Update() {
}

void Render() {
}

int main(){
  while (window.isOpen()){
     sf::Event event;
     while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
     }
    window.clear();
    Load();
    Update();
    Render();
    window.display();
  }
  return 0;
}