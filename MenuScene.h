#include <SFML/Graphics.hpp>

class MenuScene {

	// Atributos
	private:
		// Background
		sf::Texture menuTexture;
		sf::Sprite menuSprite;
		// Texturas normales
		sf::Texture jugarTexture;
		sf::Sprite jugarSprite;
		sf::Texture salirTexture;
		sf::Sprite salirSprite;
		// Texturas selected
		sf::Texture jugarSelTexture;
		sf::Sprite jugarSelSprite;
		sf::Texture salirSelTexture;
		sf::Sprite salirSelSprite;
		// opcion 1 = jugar / opcion 0 = salir
		int opcion = 1;

	public:
		// Constructor
		MenuScene();
		// Getters
		sf::Sprite& getMenuBack();
		sf::Sprite& getJugarButton(int opc);
		sf::Sprite& getSalirButton(int opc);
		// Setters
};