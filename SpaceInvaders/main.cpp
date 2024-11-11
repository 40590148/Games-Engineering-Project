#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "ship.h"

sf::Texture spritesheet;
sf::Sprite invader;
sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");

std::vector<Ship*> ships;

float dt = 1.f;

void Load() {
    if (!spritesheet.loadFromFile("C:/Users/Cameron/Documents/GitHub/Games-Engineering-Project/res/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

    Invader* inv = new Invader(sf::IntRect(160, 32, 32, 32), { 100,100 });
    ships.push_back(inv);

    Invader* inv2 = new Invader(sf::IntRect(0, 0, 32, 32), { 48,16 });
    ships.push_back(inv2);
}

void Update() {
    for (auto &s : ships) {
        s->Update(dt);
    }
}

void Render() {
    window.draw(invader);

    for (const auto s : ships) {
        window.draw(*s);
    }
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