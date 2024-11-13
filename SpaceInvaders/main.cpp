#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "ship.h"
#include "game.h"

sf::Texture spritesheet;
sf::Sprite invader;
sf::RenderWindow window(sf::VideoMode({ 500, 300 }), "SFML works!");

std::vector<Ship*> ships;

float dt = 1.f;

void Load() {
    if (!spritesheet.loadFromFile("invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

    //Invader* inv = new Invader(sf::IntRect(160, 32, 32, 32), { 100,100 });
    //ships.push_back(inv);

    for (int r = 0; r < invaders_rows; r++) {
        auto rect = sf::IntRect(0, 0, 32, 32);
        auto position = sf::Vector2f(0.f, 0.f);

        for (int c = 0; c <= invaders_columns; c++) {
            if (c == 0) {
                position = sf::Vector2f(32, r * 32 + 32);
            }
            else {
                position = sf::Vector2f(c * 32, r * 32 + 32);
            }

            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }
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