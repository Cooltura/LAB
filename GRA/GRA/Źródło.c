#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
const float FPS = 60;
const int SCREEN_W = 1024;
const int SCREEN_H = 768;
const int BOUNCER_SIZE = 120;
const float pi = 3.14;
enum MYKEYS {
	KEY_UP, KEY_DOWN ,KEY_LEFT , KEY_RIGHT
};

int main(int argc, char **argv)
{
	ALLEGRO_BITMAP *tlo = NULL;
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_BITMAP *image2 = NULL;
	ALLEGRO_BITMAP *image3 = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *car = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	float car_x = 512, car_y = 384;
	float bouncer_x = 380, bouncer_y = 200;
	float bouncer_2x = 630, bouncer_2y = 200;
    bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	int x = 1;
	int y = 0;
	float k = 0, k2 = pi / 2, k3 = 0, k4 = 0, k5 = 0;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_image_addon()) {
		fprintf(stderr, "failed to initialize image addon\n");
		return -1;
	}
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE / 4, BOUNCER_SIZE);
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	bouncer2 = al_create_bitmap(BOUNCER_SIZE / 4, BOUNCER_SIZE);
	if (!bouncer2) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	image = al_load_bitmap("image.png");

	if (!image) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	
	car = al_load_bitmap("car.png");
	if (!car) {
			fprintf(stderr, "failed to create image bitmap!\n");
			al_destroy_display(display);
			al_destroy_timer(timer);
			return -1;
	}

	tlo = al_load_bitmap("tlo.png");
	if (!tlo) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	image2 = al_load_bitmap("image2.png");
	if (!image2) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	
	image3 = al_load_bitmap("image3.png");
	if (!image3) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_set_target_bitmap(bouncer2);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_set_target_bitmap(al_get_backbuffer(display));
	
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (x == 1)
			{
				if (key[KEY_UP]) {
					if (y == 1) {
						bouncer_y = 200;
						bouncer_2y =200;
						y = 0;
	                }
					
				}
				if (key[KEY_DOWN]) {
					if (y == 0) {
						bouncer_y = 500;
						bouncer_2y = 500;
						y = 1;
					}
				}
			}
			if (x == 0)
			{
				y = 0;
				if (key[KEY_UP] && key[KEY_LEFT]) {
					k = k - 0.01;
					k2 = k2 + 0.01;
					k3 = k3 - 0.01;
					k4 = k2 - pi / 2;
					k5 = k3 + pi / 2;
					y = 1;
				}
				else if (key[KEY_UP] && key[KEY_RIGHT]) {

					if (k3 < 0)
					{
						k = 2 * pi + k;
						k3 = k5;
						k2 = k4;
					}
					k = k + 0.01;
					k2 = k2 - 0.01;
					k3 = k3 + 0.01;
					y = 1;
				}
				else if (key[KEY_DOWN] && key[KEY_LEFT]) {
					k = k - 0.01;
					k2 = k2 + 0.01;
					k3 = k3 - 0.01;
					k4 = k2 - pi / 2;
					k5 = k3 + pi / 2;
					y = 2;
				}
				else if (key[KEY_DOWN] && key[KEY_RIGHT]) {
					y = 2;
					if (k3 < 0)
					{
						k = 2 * pi + k;
						k3 = k4;
						k2 = k5;
					}
					k = k + 0.01;
					k2 = k2 - 0.01;
					k3 = k3 + 0.01;
				}
				else if (key[KEY_UP]) {
					y = 1;
				}
				else if (key[KEY_DOWN]) {
					y = 2;
				}
				if (y == 1) {
					if ((car_x <= 998 || (k > 1.57 && k < 4.72) || (k<-1.57 && k>-4.72)) && (car_x >= 25 || (k < 1.57 || k > 4.72) || (k > -1.57 && k < -4.72)))
					{
						if ((car_y <= 589 || (k > 3.14 && k < 6.28) || (k<-3.14 && k>-6.28)) && (car_y >= 27 || (k >0 && k < 3.14) || (k <-3.14 && k > -6.28)))
						{
							if (k >= 0 && k < 1.57) {
								car_y += 1 * k3;
								car_x += 1 * k2;
							}
							if (k >= 1.57 && k < 3.14) {
								car_y += 1 * k2;
								car_x -= 1 * k3;
							}
							if (k >= 3.14 && k < 4.71) {
								car_y -= 1 * k3;
								car_x -= 1 * k2;
							}
							if (k >= 4.71 && k < 6.28)
							{
								car_y -= 1 * k2;
								car_x += 1 * k3;
							}

							if (k <= -0.01 && k > -1.57) {
								car_y -= 1 * k4;
								car_x += 1 * k5;
							}
							if (k <= -1.57 && k > -3.14) {
								car_y -= 1 * k5;
								car_x -= 1 * k4;
							}
							if (k <= -3.14 && k > -4.71) {
								car_y += 1 * k4;
								car_x -= 1 * k5;
							}
							if (k <= -4.71 && k > -6.28) {
								car_y += 1 * k5;
								car_x += 1 * k4;
							}
						}
					}
				}

				if (y == 2)
				{
					if (car_x < 999 && car_x >= 24) {
						if (car_y<590 && car_y>=24) {

							if (k >= 0 && k < 1.57) {
								car_y -= 1 * k3;
								car_x -= 1 * k2;
							}
							if (k >= 1.57 && k < 3.14) {
								car_y -= 1 * k2;
								car_x += 1 * k3;
							}
							if (k >= 3.14 && k < 4.71) {
								car_y += 1 * k3;
								car_x += 1 * k2;
							}
							if (k >= 4.71 && k < 6.28)
							{
								car_y += 1 * k2;
								car_x -= 1 * k3;
							}

							if (k <= -0.01 && k > -1.57) {
								car_y += 1 * k4;
								car_x -= 1 * k5;
							}
							if (k <= -1.57 && k > -3.14) {
								car_y += 1 * k5;
								car_x += 1 * k4;
							}
							if (k <= -3.14 && k > -4.71) {
								car_y -= 1 * k4;
								car_x += 1 * k5;
							}
							if (k <= -4.71 && k > -6.28) {
								car_y -= 1 * k5;
								car_x -= 1 * k4;
							}
						}
					}
				}

				if (k <= -6.27 || k >= 6.27)
				{
					k = 0;
					k2 = pi / 2;
					k3 = 0;
				}
				if ((k > 1.56 && k < 1.58) || (k > 3.13 && k < 3.15) || (k > 4.7 && k < 4.72))
				{
					k2 = pi / 2;
					k3 = 0;
				}
				if ((k < -1.56 && k > -1.58) || (k < -3.13 && k > -3.15) || (k < -4.7 && k > -4.72))
				{
					k2 = pi / 2;
					k3 = 0;
				}
			}
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_ENTER:
				if (y==1)
					doexit = true;
				else
				{
					x = 0;
					doexit = false;
				}
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			if (x == 1)
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));


				al_draw_bitmap(image, 400, 200, 0);
				al_draw_bitmap(image3, 400, 500, 0);
				al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
				al_draw_bitmap(bouncer2, bouncer_2x, bouncer_2y, 0);
				al_flip_display();
			}

			else
			{
				al_draw_bitmap(tlo, 0, 0, 0);
				al_draw_rotated_bitmap(car,50,25, car_x, car_y, k, 0);
				al_flip_display();
			}
		}
	}
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image);
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}