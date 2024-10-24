#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#pragma once 

		// Constructor (carga textura, setea textura, setea posicion en pantalla, setea origen de sprite)
		Player::Player() {
			Player::textureIdle.loadFromFile("images\\playerIdle.png");
			Player::textureJump.loadFromFile("images\\playerJump.png");
			Player::textureMove.loadFromFile("images\\playerMove.png");
			Player::textureRun.loadFromFile("images\\playerRun.png");
			Player::textureRunJump.loadFromFile("images\\playerRunJump.png");
			Player::sprite.setTexture(textureIdle);
			sprite.setPosition(200, 500);
			Player::updateHitbox();
			sprite.setOrigin(getHitbox().width / 2, 0);
		}
		// Metodos
		void Player::update() {
			updateHitbox();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (!getHasSpeed()) setVelocityX(6);
				else {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
						setVelocityX(9);
						isRunning = true;
					}
					else setVelocityX(6);
				}
				isMoving = true;
				sprite.move(velocityX, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (!getHasSpeed()) setVelocityX(-6);
				else {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
						setVelocityX(-9);
						isRunning = true;
					}
					else setVelocityX(-6);
				}
				isMoving = true;
				sprite.move(velocityX, 0);
			}

			// Verificar si el espacio est� presionado
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (spaceReleased) {  // Solo si se solt� antes
					if (!isJumping) {
						// Primer salto
						velocityY = jumpForce;
						isJumping = true;
						spaceReleased = false;  // Marcar como presionado
					}
					else if (hasDoubleJump && !hasAlreadyJumped) {
						// Doble salto
						velocityY = jumpForce;
						hasAlreadyJumped = true;
						std::cout << "Doble salto realizado" << std::endl;
					}
				}
			}
			else {
				spaceReleased = true;  // Marcar que se solt� la tecla
			}
			if (sprite.getGlobalBounds().left < 0) {
				sprite.setPosition(sprite.getOrigin().x, sprite.getPosition().y);
			}
			if ((sprite.getPosition().x + sprite.getGlobalBounds().width) > 5000) {
				sprite.setPosition(5000 - sprite.getGlobalBounds().width, sprite.getPosition().y);
			}
			if (velocityX < 0) {
				sprite.setScale(-1, 1);
			}
			else if (velocityX > 0) {
				sprite.setScale(1, 1);
			}	
		}
		void Player::setVelocityX(float v) {
			velocityX = v;
		}
		float Player::getVelocityX() {
			return velocityX;
		}
		void Player::setVelocityY(float v) {
			velocityY = v;
		}
		float Player::getVelocityY() {
			return velocityY;
		}
		void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(sprite, states);
		}
		void Player::moveJump(float g) {
			if (!isRunning)
				Player::sprite.setTexture(textureJump);
			else
				Player::sprite.setTexture(textureRunJump);
			velocityY += g;
			sprite.move(0, velocityY);
			updateHitbox();
		}
		void Player::onFloor() {
				isJumping = false;
				hasAlreadyJumped = false;  // Permitir un nuevo doble salto
				velocityY = 0;

				if (!isMoving) {						// Si no se esta moviendo
					sprite.setTexture(textureIdle);
				}
				else {									// Si se esta moviendo
					if (!isRunning)
						sprite.setTexture(textureMove);
					else
						sprite.setTexture(textureRun);
				}
				isMoving = false;
				isRunning = false;
		}
		sf::Vector2f Player::getPlayerPosition() {
			return sprite.getPosition();
		}

		// Double Jump

		void Player::setHasDoubleJump(bool hasIt) {
			hasDoubleJump = hasIt;
		}
		void Player::setHasAlreadyJumped(bool hasIt) {
			hasAlreadyJumped = hasIt;
		}

		// Speed Boost

		void Player::setHasSpeed(bool hasIt) {
			hasSpeed = hasIt;
		}
		bool Player::getHasSpeed() { return hasSpeed; }
		//
		sf::Sprite& Player::getPlayerSprite() {
			return sprite;
		}

		// *** Fijarse como ajustar mejor la hitbox ***
		void Player::updateHitbox() {
			hitbox = sf::FloatRect(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height - 15);
		}

		sf::FloatRect Player::getHitbox() { return hitbox; }