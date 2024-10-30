#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScene {

	// Atributos
	private:
		// Background 1 y 2
		sf::Texture menuTexture;
		sf::Texture menuTexture2;
		sf::Texture gameOverTexture;
		sf::Sprite menuSprite;
		sf::Sprite menuSprite2;
		sf::Sprite gameOverSprite;
		// Texturas botones normales
		sf::Texture jugarTexture, salirTexture, comenzarTexture, rankTexture, volverTexture;
		sf::Sprite jugarSprite, salirSprite, comenzarSprite, rankSprite, volverSprite;
		// Texturas botones selected
		sf::Texture jugarSelTexture, salirSelTexture, comenzarSelTexture, rankSelTexture, volverSelTexture;
		sf::Sprite jugarSelSprite, salirSelSprite, comenzarSelSprite, rankSelSprite, volverSelSprite;
		// Atributos para manejar si esta seleccionado Jugar(1) o Salir(0) en el main
		// Los booleanos se activan si se presiono Enter en la opcion seleccionada

		// IDEA DE TIPOS DE MENU:
		// 1. Menu Principal: Jugar - Salir
		// 2. Sub Menu: Comenzar - Rank - Volver
		// 3. Rank Menu: Cinco casilleros donde iran los nombres con puntajes
		// Cuando aun no haya nombres podria haber algo como "1. AAAAA 0 pts"
		// 4. Menu Comenzar: Seleccion de nombre del jugador (maximo 5 caracteres)

		// NOTA: en el sub menu, tambien deberia estar la opcion continuar, si se hizo un save
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

		// Setters
		void setOpc(int v);
		void setTipoMenu(int v);
		void setSalir(int v);
		void setComenzar(int v);

		// Metodos
		void MenuUpdate();
};