#include <SFML/Graphics.hpp>

class Map
{
	// Atributos
	private:
	// Background
	sf::Texture backTexture;
	sf::Sprite backSprite;
	// Plataformas
	sf::Texture platTexture1;
	sf::Sprite platSprite1;

	public:
		// Constructor
		Map();
		// Getters de texturas/sprites
		sf::Sprite& getBackground();
		sf::Sprite& getPlatform(int tipoPlataforma);

		// Setters
		void setMapPosition(sf::Sprite &sprite, float x, float y);


};