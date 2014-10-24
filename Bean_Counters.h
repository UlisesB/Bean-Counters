#ifndef __BEAN_COUNTERS_H__
#define __BEAN_COUNTERS_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Penguin.h"
#include "Truck.h"
#include "Images.h"

class Bean_Counters {
	private:		
		int SCREEN_HEIGHT;
		int SCREEN_WIDTH;
		SDL_Surface *images[NUM_IMAGES];
		SDL_Surface *screen;

		Pinguino player;
		Truck truck;

	public:
		Bean_Counters();
		
		void play(void);
};

#endif