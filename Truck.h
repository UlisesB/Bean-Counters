#ifndef __TRUCK__H_
#define __TRUCK__H_

class  Truck {
	private:
		int x, y, image;

	public:
		Truck();

		int get_x(void);
		int get_y(void);
		int get_image(void);
};

#endif