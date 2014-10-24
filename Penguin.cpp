#include "Penguin.h"
#include "Images.h"

Pinguino::Pinguino() {
	x = 279; 
	y = 247;
	bags = 0;
	image = PENGUIN_1;
}

int Pinguino::get_y(void) {
	return y;
}

int Pinguino::get_x(void) {
	return x;
}

void Pinguino::set_x(int x) {
	this->x = x;
	if (x < 190) {
		this->x = 190;
	}
	else if (x > 555) {
		this->x = 555;
	}
}

int Pinguino::get_image(void) {
	return image+bags;
}