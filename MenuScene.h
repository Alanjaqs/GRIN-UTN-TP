#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
		// Atributos para manejar si esta seleccionado Jugar(1) o Salir(0) en el main
		// Los booleanos se activan si se presiono Enter en la opcion seleccionada
		int opcionMenu = 1;
		bool jugar = false;
		bool salir = false;
		// AudioMenu
		sf::Music soundSel;

	public:
		// Constructor
		MenuScene();

		// Getters
		int getOpc();
		bool getJugar();
		bool getSalir();

		sf::Sprite& getMenuBack();
		sf::Sprite& getJugarButton();
		sf::Sprite& getJugarSelButton();
		sf::Sprite& getSalirButton();
		sf::Sprite& getSalirSelButton();

		// Setters
		void setJugar(int v);
		void setSalir(int v);

		// Metodos
		void MenuUpdate();
};