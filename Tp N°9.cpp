#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
using namespace sf;
using namespace std;

int cambiarDictado(string p);
int main() {

	VideoMode vm(350, 90);
	RenderWindow window(vm, "Tp N°9");

	string p;

	cout << "Ingresa una frase: ";
	getline(cin, p);

	Font font;
	font.loadFromFile("font/Roboto-Blackitalic.ttf");

	Text frase1;
	frase1.setFont(font);
	frase1.setPosition(0, 0);

	Text letras;
	letras.setFont(font);
	letras.setPosition(0, 40);


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		stringstream ss, sd;
		ss << "Letras faltantes: " << cambiarDictado(p);
		letras.setString(ss.str());

		sd << "Palabra ingresada: " << p;
		frase1.setString(sd.str());

		window.clear();

		window.draw(frase1);
		window.draw(letras);

		window.display();
	}


	return 0;
}

int cambiarDictado(string p) {

	int letras = 0;

	for (int i = 0; i < p.size(); i++) {
		letras++;
	}
	return letras - 1;
}