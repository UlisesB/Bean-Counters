#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_keysym.h>

#include "Bean_Counters.h"
#include "Penguin.h"
#include "Truck.h"
#include "Images.h"

#define GAMEDATA_DIR "images/"

const char *images_game[NUM_IMAGES] = {
	GAMEDATA_DIR "1up.png",
	
	GAMEDATA_DIR "anvil.png",
	GAMEDATA_DIR "anvil-fall.png",
	
	GAMEDATA_DIR "intro.png",
	GAMEDATA_DIR "background.png",
	GAMEDATA_DIR "snow.png",
	
	GAMEDATA_DIR "bag-1.png",
	GAMEDATA_DIR "bag-2.png",
	GAMEDATA_DIR "bag-3.png",
	GAMEDATA_DIR "bag-dropped.png",
	
	GAMEDATA_DIR "bolsas-0001.png",
	GAMEDATA_DIR "bolsas-0002.png",
	GAMEDATA_DIR "bolsas-0003.png",
	GAMEDATA_DIR "bolsas-0004.png",
	GAMEDATA_DIR "bolsas-0005.png",
	GAMEDATA_DIR "bolsas-0006.png",
	GAMEDATA_DIR "bolsas-0007.png",
	GAMEDATA_DIR "bolsas-0008.png",
	GAMEDATA_DIR "bolsas-0009.png",
	GAMEDATA_DIR "bolsas-0010.png",
	GAMEDATA_DIR "bolsas-0011.png",
	GAMEDATA_DIR "bolsas-0012.png",
	GAMEDATA_DIR "bolsas-0013.png",
	GAMEDATA_DIR "bolsas-0014.png",
	GAMEDATA_DIR "bolsas-0015.png",
	GAMEDATA_DIR "bolsas-0016.png",
	GAMEDATA_DIR "bolsas-0017.png",
	GAMEDATA_DIR "bolsas-0018.png",
	GAMEDATA_DIR "bolsas-0019.png",
	GAMEDATA_DIR "bolsas-0020.png",
	GAMEDATA_DIR "bolsas-0021.png",
	GAMEDATA_DIR "bolsas-0022.png",
	GAMEDATA_DIR "bolsas-0023.png",
	GAMEDATA_DIR "bolsas-0024.png",
	GAMEDATA_DIR "bolsas-0025.png",
	GAMEDATA_DIR "bolsas-0026.png",
	GAMEDATA_DIR "bolsas-0027.png",
	GAMEDATA_DIR "bolsas-0028.png",
	GAMEDATA_DIR "bolsas-0029.png",
	GAMEDATA_DIR "bolsas-0030.png",
	GAMEDATA_DIR "bolsas-0031.png",
	GAMEDATA_DIR "bolsas-0032.png",
	GAMEDATA_DIR "bolsas-0033.png",
	GAMEDATA_DIR "bolsas-0034.png",
	GAMEDATA_DIR "bolsas-0035.png",
	GAMEDATA_DIR "bolsas-0036.png",
	GAMEDATA_DIR "bolsas-0037.png",
	GAMEDATA_DIR "bolsas-0038.png",
	GAMEDATA_DIR "bolsas-0039.png",
	GAMEDATA_DIR "bolsas-0040.png",
	GAMEDATA_DIR "bolsas-0041.png",
	GAMEDATA_DIR "bolsas-0042.png",
	GAMEDATA_DIR "bolsas-0043.png",
	GAMEDATA_DIR "bolsas-0044.png",
	GAMEDATA_DIR "bolsas-0045.png",
	GAMEDATA_DIR "bolsas-0046.png",
	GAMEDATA_DIR "bolsas-0047.png",
	GAMEDATA_DIR "bolsas-0048.png",
	GAMEDATA_DIR "bolsas-0049.png",
	GAMEDATA_DIR "bolsas-0050.png",
	GAMEDATA_DIR "bolsas-0051.png",
	GAMEDATA_DIR "bolsas-0052.png",
	GAMEDATA_DIR "bolsas-0053.png",
	GAMEDATA_DIR "bolsas-0054.png",
	GAMEDATA_DIR "bolsas-0055.png",
	GAMEDATA_DIR "bolsas-0056.png",
	GAMEDATA_DIR "bolsas-0057.png",
	GAMEDATA_DIR "bolsas-0058.png",
	GAMEDATA_DIR "bolsas-0059.png",
	GAMEDATA_DIR "bolsas-0060.png",

	GAMEDATA_DIR "plataform.png",
	GAMEDATA_DIR "truck.png",
	GAMEDATA_DIR "candy-truck.png",

	GAMEDATA_DIR "crash-1.png",
	GAMEDATA_DIR "crash-2.png",
	GAMEDATA_DIR "crash-3.png",

	GAMEDATA_DIR "fish.png",
	GAMEDATA_DIR "fish-fall.png",
	GAMEDATA_DIR "flowerpot.png",
	GAMEDATA_DIR "flowerpot-broken.png",
	
	GAMEDATA_DIR "penguin-1.png",
	GAMEDATA_DIR "penguin-2.png",
	GAMEDATA_DIR "penguin-3.png",
	GAMEDATA_DIR "penguin-4.png",
	GAMEDATA_DIR "penguin-5.1.png",
	GAMEDATA_DIR "penguin-5.2.png",
	GAMEDATA_DIR "penguin-5.3.png",
	GAMEDATA_DIR "penguin-6.1.png",
	GAMEDATA_DIR "penguin-6.2.png",
	GAMEDATA_DIR "penguin-6.3.png",
	GAMEDATA_DIR "penguin-7.png",
	GAMEDATA_DIR "penguin-8.png",
	GAMEDATA_DIR "penguin-9.png",
	GAMEDATA_DIR "penguin-10.png"
};
Bean_Counters::Bean_Counters() {	
	SCREEN_HEIGHT = 480;
	SCREEN_WIDTH = 760;
	SDL_Surface *carga;
	if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		fprintf (stderr, "Error al inicializar SDL_Init: %s", SDL_GetError ());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, 16, 0);
	if (screen == NULL) {
		fprintf (stderr, "Error con el modo de video");
		SDL_Quit ();
		exit (EXIT_FAILURE);
	}

	for (int g = 0; g < NUM_IMAGES; g++) {
        carga = IMG_Load(images_game [g]);
 
        if (carga == NULL) {
            fprintf (stderr, "Error al cargar la imagen %s\n", images_game [g]);
            SDL_Quit ();
            exit (1);
        }
 
        images[g] = carga;
    }
}

void Bean_Counters::play(void) {
	SDL_Rect rect;
	SDL_Event event;
	SDLKey key;

	do {
		while (SDL_PollEvent (&event) > 0) {
			switch (event.type) {
				case SDL_QUIT:
					SDL_Quit();
					return;
					break;
				case SDL_KEYDOWN:
					key = event.key.keysym.sym;
					switch (key) {
						case SDLK_ESCAPE:
							SDL_Quit();
							return;
							break;
					}
					break;
				case SDL_MOUSEMOTION:
					player.set_x(event.motion.x);
					break;
			}
		}
		rect.x = 0;
		rect.y = 0;
		rect.w = images[BACKGROUND]->w;
		rect.h = images[BACKGROUND]->h;
		SDL_BlitSurface(images[BACKGROUND], NULL, screen, &rect);

		
		rect.w = images[player.get_image()]->w;
		rect.h = images[player.get_image()]->h;
		rect.y = player.get_y();
		rect.x = player.get_x() - 113;
		SDL_BlitSurface(images[player.get_image()], NULL, screen, &rect);

		rect.w = images[PLATAFORM]->w;
		rect.h = images[PLATAFORM]->h;
		rect.y = 378;
		rect.x = -17;
		SDL_BlitSurface(images[PLATAFORM], NULL, screen, &rect);

		rect.w = images[truck.get_image()]->w;
		rect.h = images[truck.get_image()]->h;
		rect.y = truck.get_y();
		rect.x = truck.get_x();
		SDL_BlitSurface(images[truck.get_image()], NULL, screen, &rect);

		rect.w = images[SNOW]->w;
		rect.h = images[SNOW]->h;
		rect.y = 436;
		rect.x = -53;
		SDL_BlitSurface(images[SNOW], NULL, screen, &rect);

		SDL_Flip(screen);
		
		SDL_Delay(32);

	} while (1);
}