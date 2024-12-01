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

			// Sounds
			jumpSound.openFromFile("audio\\jump.mp3");
			dashSound.openFromFile("audio\\dash.mp3");

		}
		// Metodos
		void Player::update() {
			updateHitbox();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (!getHasSpeed()) setVelocityX(6);
				else {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
						if (!isDashKeyPressed) {
							dashSound.play();
							isDashKeyPressed = true;
						}
						setVelocityX(9);
						isRunning = true;
					}
					else {
						setVelocityX(6);
						isDashKeyPressed = false;
					}
				}
				isMoving = true;
				sprite.move(velocityX, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				if (!getHasSpeed()) setVelocityX(-6);
				else {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
						if (!isDashKeyPressed) {
							dashSound.play();
							isDashKeyPressed = true;
						}
						setVelocityX(-9);
						isRunning = true;
					}
					else {
						setVelocityX(-6);
						isDashKeyPressed = false;
					}
				}
				isMoving = true;
				sprite.move(velocityX, 0);
			}

			// Verificar si el espacio está presionado
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (spaceReleased) {  // Solo si se soltó antes
					if (!isJumping) {
						jumpSound.play();
						// Primer salto
						velocityY = jumpForce;
						isJumping = true;
						spaceReleased = false;  // Marcar como presionado
					}
					else if (hasDoubleJump && !hasAlreadyJumped /* && doubleJumpClock.getElapsedTime().asSeconds() < doubleJumpDuration*/) {
						jumpSound.play();
						// Doble salto
						velocityY = jumpForce;
						hasAlreadyJumped = true;
					}
				}
			}
			else {
				spaceReleased = true;  // Marcar que se soltó la tecla
			}
			if (sprite.getGlobalBounds().left < 0) {
				sprite.setPosition(sprite.getOrigin().x, sprite.getPosition().y);
			}
			if ((sprite.getPosition().x + sprite.getGlobalBounds().width) > 7600) {
				sprite.setPosition(7600 - sprite.getGlobalBounds().width, sprite.getPosition().y);
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
		void Player::moveJump() {
			if (!isRunning)
				Player::sprite.setTexture(textureJump);
			else
				Player::sprite.setTexture(textureRunJump);
			velocityY += 0.5f;
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
			//doubleJumpClock.restart();
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
		bool Player::getIsJumping() { return isJumping; }

		// Hitbox
		void Player::updateHitbox() {
			playerTop = sprite.getGlobalBounds().top;
			playerBottom = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height;
			playerLeft = sprite.getGlobalBounds().left;
			playerRight = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width;
			hitbox = sprite.getGlobalBounds();
		}
		sf::FloatRect Player::getHitbox() { return hitbox; }
		float Player::getPlayerTop() { return playerTop; }
		float Player::getPlayerBottom() { return playerBottom; }
		float Player::getPlayerLeft() { return playerLeft; }
		float Player::getPlayerRight() { return playerRight; }

		void Player::setIsDead(int v) {
			isDead = v;
		}
		bool Player::getIsDead() { return isDead; }


		void Player::doDamage(int damage) {
			life -= 1;
			if (life <= 0) {
				life = 0;  // Asegurarse de que la vida no sea negativa
				setIsDead(1);  // Marcar al jugador como muerto
			}
		}
		int Player::getCurrentLife() {
			return life;
		}
		int Player::getTotalLife() {
			return totalLife;
		}
		void Player::setCurrentLife(int l) {
			life = l;
		}
		void Player::setTotalLife(int newTotalLife) {
			totalLife = newTotalLife;
		}
		void Player::healLife(int healing) {
			life += healing;
		}
		sf::Clock& Player::getDamageClock(){
			return damageClock;
		}

		//Puntaje
		void Player::setPuntaje(int p) { puntos = p; }
		void Player::addPuntaje(int p) { puntos += p; }
		int Player::getPuntaje() { return puntos; }
		void Player::quitarPuntaje(int p) { puntos -= p; }