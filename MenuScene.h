#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScene {

	// Atributos
	private:
		// Background 1 y 2
		sf::Texture menuTexture, menuTexture2, gameOverTexture;
		sf::Sprite menuSprite, menuSprite2, gameOverSprite;
		// Texturas botones normales
		sf::Texture jugarTexture, salirTexture, comenzarTexture, rankTexture, volverTexture, verRankTexture, borrarRankTexture;
		sf::Sprite jugarSprite, salirSprite, comenzarSprite, rankSprite, volverSprite, verRankSprite, borrarRankSprite;
		// Texturas botones selected
		sf::Texture jugarSelTexture, salirSelTexture, comenzarSelTexture, rankSelTexture, volverSelTexture, verRankSelTexture, borrarRankSelTexture;
		sf::Sprite jugarSelSprite, salirSelSprite, comenzarSelSprite, rankSelSprite, volverSelSprite, verRankSelSprite, borrarRankSelSprite;
		int tipoMenu = 1;
		// opcionMenu se encarga que sprites de botones se muestran segun seleccion con W y S
		int opcionMenu = 1;
		bool salir = false;
		bool comenzar = false;
		bool keyReleased = true;
		bool enterReleased = true;
		// AudioMenu
		sf::Music soundSel;

	public:
		// Constructor
		MenuScene();

		// Getters
		bool getSalir();
		bool getComenzar();
		int getOpc();
		int getTipoMenu();

		sf::Sprite& getMenuBack();
		sf::Sprite& getMenu2Back();
		sf::Sprite& getGameOver();
		sf::Sprite& getJugarButton();
		sf::Sprite& getJugarSelButton();
		sf::Sprite& getSalirButton();
		sf::Sprite& getSalirSelButton();
		sf::Sprite& getComenzarButton();
		sf::Sprite& getComenzarSelButton();
		sf::Sprite& getRankButton();
		sf::Sprite& getRankSelButton();
		sf::Sprite& getVolverButton();
		sf::Sprite& getVolverSelButton();
		sf::Sprite& getVerRankButton();
		sf::Sprite& getVerRankSelButton();
		sf::Sprite& getBorrarRankButton();
		sf::Sprite& getBorrarRankSelButton();

		// Setters
		void setOpc(int v);
		void setTipoMenu(int v);
		void setSalir(int v);
		void setComenzar(int v);

		// Metodos
		void MenuUpdate();
};