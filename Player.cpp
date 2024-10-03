#include <SFML/Graphics.hpp>
#include "Player.h"

		// Constructor (carga textura, setea textura, setea posicion en pantalla, setea origen de sprite)
		Player::Player() {
			Player::textureIdle.loadFromFile("images\\playerIdle.png");
			Player::textureJump.loadFromFile("images\\playerJump.png");
			Player::textureMove.loadFromFile("images\\playerMove.png");
			Player::sprite.setTexture(textureIdle);
			sprite.setPosition(200, 500);
			sprite.setOrigin(sprite.getGlobalBounds().width / 2, 0);
		}
		// Metodos
		void Player::update() {		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				setVelocity(6);
				isMoving = true;
				sprite.move(velocityX, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				setVelocity(-6);
				isMoving = true;
				sprite.move(velocityX, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isJumping == false) {
				velocityY = jumpForce;
				isJumping = true;		
			}
			if (sprite.getGlobalBounds().left < 0) {
				sprite.setPosition(sprite.getOrigin().x, sprite.getPosition().y);
			}
			if ((sprite.getPosition().x + sprite.getGlobalBounds().width) > 2000) {
				sprite.setPosition(2000 - sprite.getGlobalBounds().width, sprite.getPosition().y);
			}
			if (velocityX < 0) {
				sprite.setScale(-1, 1);
			}
			else if (velocityX > 0) {
				sprite.setScale(1, 1);
			}

		}
		void Player::setVelocity(float v) {
			velocityX = v;
		}
		float Player::getVelocity() {
			return velocityX;
		}
		void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(sprite, states);
		}
		void Player::moveJump(float g) {
			Player::sprite.setTexture(textureJump);
			velocityY += g;
			sprite.move(0, velocityY);
		}
		void Player::detectFloor() {
			if (sprite.getPosition().y >= 600) {
				sprite.setPosition(sprite.getPosition().x, 600);
				isJumping = false;
				velocityY = 0;
				if (isMoving == false) {
					Player::sprite.setTexture(textureIdle);
				}
				if (isMoving == true) {
					Player::sprite.setTexture(textureMove);
					isMoving = false;
				}

			}
		}
		sf::Vector2f Player::getPlayerPosition() {
			return sprite.getPosition();
		}


