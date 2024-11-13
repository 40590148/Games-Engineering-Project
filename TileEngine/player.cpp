#include "player.h"
using namespace std;
using namespace sf;

void Player::Update(double dt) {
	Entity::Update(dt);
}

Player::Player() : _speed(200.f), Entity(make_unique<CircleShape>(25.f)){
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vetor2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}