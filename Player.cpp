#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#pragma once 

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
				hasAlreadyJumped = false;  // Permitir un nuevo doble salto
				velocityY = 0;

				if (!isMoving) {
					sprite.setTexture(textureIdle);
				}
				else {
					sprite.setTexture(textureMove);
					isMoving = false;
				}
			}
		}
		sf::Vector2f Player::getPlayerPosition() {
			return sprite.getPosition();
		}

		void Player::setHasDoubleJump(bool hasIt) {
			hasDoubleJump = hasIt;
		}
		void Player::setHasAlreadyJumped(bool hasIt) {
			hasAlreadyJumped = hasIt;
		}
