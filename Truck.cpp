#include "Truck.h"
#include "Images.h"

Truck::Truck() {
	//x = 551 + 204
	x = 551;
	y = 64;
	image = TRUCK;
}

int Truck::get_x(void) {
	return x;
}

int Truck::get_y(void) {
	return y;
}

int Truck::get_image(void) {
	return image;
}
