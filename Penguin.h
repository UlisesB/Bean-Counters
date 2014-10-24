#ifndef __PINGUINO_H__
#define __PINGUINO_H__

class Pinguino {
	private:
		int x, y, bags, image;

	public:
		Pinguino();
		
		int get_y(void);
		int get_x(void);
		void set_x(int x);
		int get_image(void);
};

#endif