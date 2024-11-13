#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

Ship::Ship() {};
Invader::Invader() : Ship() {};

bool Invader::direction = true;
float Invader::speed = 1.f;
float Player::direction;

const Keyboard::Key controls[4] = {
	Keyboard::W,
	Keyboard::A,
	Keyboard::S,
	Keyboard::D
};

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {};
Ship::~Ship() = default;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(Vector2f(16.f, 16.f));;
	setPosition(pos);
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);

	move(Vector2f(dt * (direction ? 1.f : -1.f) * speed, 0.f));
	
	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16)) {
		direction = !direction;

		for (int i = 0; i < ships.size(); i++) {
			ships[i]->move(Vector2f(0.f, 24.f));
		}
	}
}

Player::Player() : Ship(IntRect(Vector2i(160, 32), Vector2i(32, 32))) {
	setPosition({ gameWidth * .5f, gameHeight - 32.f});
}

void Player::Update(const float &dt) {
	Ship::Update(dt);

	if (Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}
}