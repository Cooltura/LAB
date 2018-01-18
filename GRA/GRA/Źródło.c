#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
const float FPS = 60;
const int SCREEN_W = 1024;
const int SCREEN_H = 768;
const int BOUNCER_SIZE = 120;
const float pi = 3.14;
enum MYKEYS {
	KEY_UP, KEY_DOWN ,KEY_LEFT , KEY_RIGHT,KEY_ESCAPE
};
int kolizja2(float x, float y)
{
	if (x <= 225 && y <= 125)
		return 1;
	else if (x >= 800 && y < 125)
		return 1;
	else if (x >= 275 && x<=525 && y < 125)
		return 1;
	else if (x <= 225 && y >= 225 && y <= 350)
		return 1;
	else if (x <= 225 && y >= 400 && y <=525)
		return 1;

	else return 0;

}
int kolizja_z_pojazdem(float x, float x2,float x3,float y4 ,float y, float k)
{
	int y2 = 240;
	int y3 = 608;
	int x4 = 220;
	int kx, ky, kx2, ky2, kx3, kx4, ky3, ky4;
	if (k >= -1.68 && k < 0) {
		k = -k;
		kx = x + 50 - k * 45;
		ky = y - 25 - k * 15;
		kx2 = x + 50 - k * 15;
		ky2 = y + 25 - k * 45;

		kx3 = x - 50 + k * 15;
		kx4 = x - 50 + k * 45;
		ky3 = y + 25 + k * 15;
		ky4 = y - 25 + k * 45;
	}
	if (k >= -3.14 && k < -1.58) {
		k = -k - 1.58;
		kx = x - 25 - k * 15;
		ky = y - 50 + k * 45;
		kx2 = x + 25 - k * 45;
		ky2 = y - 50 + k * 15;

		kx3 = x + 25 + k * 15;
		kx4 = x - 25 + k * 45;
		ky3 = y + 50 - k * 45;
		ky4 = y + 50 + k * 15;
	}
	if (k >= -4.72 && k < -3.14) {
		k = -k - 3.14;
		kx = x - 50 + k * 45;
		ky = y + 25 + k * 15;
		kx2 = x - 50 + k * 15;
		ky2 = y - 25 + k * 45;

		kx3 = x + 50 - k * 45;
		kx4 = x + 50 - k * 15;
		ky3 = y - 25 - k * 15;
		ky4 = y + 25 - k * 45;
	}
	if (k >= -6.28 && k < -4.72) {
		k = -k - 4.72;
		kx = x + 25 + k * 15;
		ky = y + 50 - k * 45;
		kx2 = x - 25 + k * 45;
		ky2 = y + 50 - k * 15;

		kx3 = x - 25 - k * 15;
		kx4 = x + 25 - k * 45;
		ky3 = y - 50 + k * 45;
		ky4 = y - 50 + k * 15;
	}
	if (k >= 0 && k <= 1.58) {
		kx = x + 50 - k * 15;
		ky = y - 25 + k * 45;
		kx2 = x + 50 - k * 45;
		ky2 = y + 25 + k * 15;
		kx3 = x - 50 + k * 15;
		kx4 = x - 50 + k * 45;
		ky3 = y + 25 - k * 45;
		ky4 = y - 25 - k * 15;
	}
	if (k > 1.58 && k <= 3.14) {
		k = k - 1.58;
		kx = x + 25 - k * 45;
		ky = y + 50 - k * 15;
		kx2 = x - 25 - k * 15;
		ky2 = y + 50 - k * 45;
		kx3 = x - 25 + k * 45;
		kx4 = x + 25 + k * 15;
		ky3 = y - 50 + k * 15;
		ky4 = y - 50 + k * 45;
	}
	if (k > 3.14 && k <= 4.72) {
		k = k - 3.14;
		kx = x - 50 + k * 15;
		ky = y + 25 - k * 45;
		kx2 = x - 50 + k * 45;
		ky2 = y - 25 - k * 15;

		kx3 = x + 50 - k * 15;
		kx4 = x + 50 - k * 45;
		ky3 = y - 25 + k * 45;
		ky4 = y + 25 + k * 15;
	}
	if (k > 4.72 && k <= 6.28) {
		k = k - 4.72;
		kx = x - 25 + k * 45;
		ky = y - 50 + k * 15;
		kx2 = x + 25 + k * 15;
		ky2 = y - 50 + k * 45;

		kx3 = x + 25 - k * 45;
		kx4 = x - 25 - k * 15;
		ky3 = y + 50 - k * 15;
		ky4 = y + 50 - k * 45;
	}


	if (
		(((kx >= x2  && kx <= x2 + 80) || (kx2 >= x2 && kx2 <= x2 + 80)) &&
		((ky >= y3 - 20 && ky <= y2 - 5) || (ky2 >= y2 - 25 && ky2 <= y2 - 5)) )||(
		((kx3 >= x2  && kx3 <= x2 + 80) || (kx4 >= x2 && kx4 <= x2 + 80)) &&
		((ky3 >= y2 - 20 && ky3 <= y2 - 5) || (ky4 >= y2 - 25 && ky4 <= y2 - 5)))
		)
		return 1;

	if (
		(((kx >= x4  && kx <= x4 + 30) || (kx2 >= x4 && kx2 <= x4 + 30)) &&
		((ky >= y4  && ky <= y4 +80) || (ky2 >= y4 && ky2 <= y4 +80))) || (
			((kx3 >= x4  && kx3 <= x4 + 30) || (kx4 >= x4 && kx4 <= x4 + 30)) &&
			((ky3 >= y4  && ky3 <= y4 - 5) || (ky4 >= y4 - 25 && ky4 <= y4- 5)))
		)
		return 1;

	if (
		(((kx >= x3  && kx <= x3 + 80) || (kx2 >= x3 && kx2 <= x3 + 80)) &&
		(ky >y3 || ky2>y3)) || (
			((kx3 >= x3  && kx3 <= x3 + 80) || (kx4 >= x3 && kx4 <= x3 + 80)) &&
			(ky3 >y3 || ky4>y3))
		)
		return 1;

	if ((kx > 350 && kx < 430 && ky<160 && ky >150) ||( kx2 >350 && kx2 < 430 && ky2<160 && ky2 >150) || (kx3 >350 && kx3 < 430 && ky3<160 && ky3 >150) || (kx4 >350 && kx4 < 430 && ky4<160 && ky4 >150))
		return 1;

	if ((kx > 710 && kx < 730 && ky>280 && ky <380) || (kx2 >710 && kx2 < 730 && ky2>280 && ky2 <380) || (kx3 >710 && kx3 < 730 && ky3>280 && ky3 <380) || (kx4 >710 && kx4 < 730 && ky4>280 && ky4 <380))
		return 1;


	if ((kx < 191 && ky < 91) || (kx2 < 191 && ky2 < 91) ) 
		return 2;
	else if ((kx3 < 191 && ky3 < 91) || (kx4 < 191 && ky4 < 91))
	return 3;

	else if ((kx < 491 && kx>289 && ky < 91) || (kx2 < 491 && kx2>289 && ky2 < 91))
	return 2;
	else if ((kx3 < 491 && kx3>289 && ky3 < 91) || (kx4 < 491 && kx4>289 && ky4 < 91))
		return 3;

	else if (( kx>823 && ky < 91) || ( kx2>823 && ky2 < 91))
		return 2;
	else if ((kx3>823 && ky3 < 91) || ( kx4>823 && ky4 < 91))
		return 3;

	else if ((kx < 191 && ky<341 && ky >261) || (kx2 < 191 && ky2<341 && ky2 > 261))
		return 2;
	else if ((kx3 < 191 && ky3<341 && ky3 >261) || (kx4 < 191 && ky4<341 && ky4 >261))
		return 3;

	else if ((kx < 191 && ky<491 && ky >411) || (kx2 < 191 && ky2<491 && ky2 > 411))
		return 2;
	else if ((kx3 < 191 && ky3<491 && ky3 >411) || (kx4 < 191 && ky4<491 && ky4 >411))
		return 3;

	else if ((kx < 491 && kx > 300 && ky<341 && ky >261) || (kx2 < 491 && kx2 > 300 && ky2<341 && ky2 > 261))
		return 2;
	else if ((kx3 < 491 && kx3 > 300 && ky3<341 && ky3 >261) || (kx4 <491 && kx4 > 300 && ky4<341 && ky4 >261))
		return 3;

	else if ((kx < 591 && kx > 400 && ky<511 && ky >411) || (kx2 < 591 && kx2 > 400 && ky2<511 && ky2 > 411))
		return 2;
	else if ((kx3 < 591 && kx3 > 400 && ky3<511 && ky3 >411) || (kx4 <591 && kx4 > 400 && ky4<511 && ky4 >411))
		return 3;

	else if ((kx > 834 && ky<511 && ky >411) || ( kx2 > 834 && ky2<511 && ky2 > 411))
		return 2;
	else if (( kx3 > 834 && ky3<511 && ky3 >411) || ( kx4 > 834 && ky4<511 && ky4 >411))
		return 3;

	else if ((kx > 740 && kx<930 && ky >261 && ky <340) || (kx2 > 740 && kx2<930 && ky2 > 261 && ky2 <340))
		return 2;
	else if ((kx3 > 740 && kx3<930 && ky3 >261 && ky3 <340) || (kx4 > 740 && kx3<930 && ky4 >261 && ky4 <340))
		return 3;

	
	
	return 0;


}
int main(int argc, char **argv)
{
	char time[25];
	ALLEGRO_BITMAP *logo = NULL;
	ALLEGRO_BITMAP *serce = NULL;
	ALLEGRO_BITMAP *paczka = NULL;
	ALLEGRO_BITMAP *home = NULL;
	ALLEGRO_BITMAP *tlo = NULL;
	ALLEGRO_BITMAP *image = NULL;
	ALLEGRO_BITMAP *image2 = NULL;
	ALLEGRO_BITMAP *image3 = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *car = NULL;
	ALLEGRO_BITMAP *car2 = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	ALLEGRO_BITMAP *pole = NULL;
	float car_x = 650, car_y = 70, car_2x=-500,car_3y=200,car_4x=1500;
	float bouncer_x = 380, bouncer_y = 200;
	float bouncer_2x = 630, bouncer_2y = 200;
	bool key[5] = {false, false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	int i,j, p1=0, p2=0, p3=0, p4=0, p5=0, p6=0;
	int kolizja = 0;
	int p = 0;
	int x = 1;
	int y = 0;
	int s = 3;
	int time1 = 2 ,time11 = 59 ;
	int  time2 =0;
	float k = 0, k2 = pi / 2, k3 = 0, k4 = 0, k5 = 0;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	al_init_font_addon(); 
	al_init_ttf_addon();
	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 36, 0);
	if (!font) {
		fprintf(stderr, "Could not load 'arial.ttf'.\n");
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
	home = al_load_bitmap("home.jpg");

	if (!home) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	pole = al_load_bitmap("pole.jpg");

	if (!pole) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	paczka = al_load_bitmap("paczka.jpg");

	if (!paczka) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	serce = al_load_bitmap("serce.jpg");

	if (!serce) {
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
	car2 = al_load_bitmap("car1.png");
	if (!car2) {
		fprintf(stderr, "failed to create image bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	logo = al_load_bitmap("logo.jpg");
	if (!logo) {
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
				if (p == 0) {
					p2 = 1;
					p = 1;
				}
			
				if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0)
				{
					time2 = 0;
					x = 2;
				}
				else {
					
			
				
					if (car_2x < 1100) {
						car_2x = car_2x + 2;
						car_3y = car_3y - 1;
						car_4x = car_4x - 3;
					}  // Pojazdy w Grze
					else {
						car_2x = -300;
						car_3y = 578;
						car_4x = 1500;
					}

					i = kolizja_z_pojazdem(car_x, car_2x, car_4x,car_3y, car_y, k);
					if (i == 1)
					{
						s = s - 1;
						car_x = 650;
						car_y = 70;
						i = 0;
					}
					
					time2 = time2 + 1;
					if (time2 == 60) {
						time11 = time11 - 1;
						time2 = 0;
					}    // CZas GRY
					if (time11 == 0)
					{
						time11 = 59;
						time1 = time1 - 1;
					}   

					y = 0;
					if (key[KEY_UP] && key[KEY_LEFT]) {
						k = k - 0.01;
						k2 = k2 + 0.01;
						k3 = k3 - 0.01;
						k4 = k2 - pi / 2;
						k5 = k3 + pi / 2;
						y = 11;
					}
					else if (key[KEY_UP] && key[KEY_RIGHT]) {
						if (k < 0)
							k = 2 * pi + k;
						if (k3 < 0)
						{
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
						if (k < 0)
							k = 2 * pi + k;
						if (k3 < 0)
						{
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

					if (k <= -6.28 || k >= 6.28)
					{
						k = 0;
						k2 = pi / 2;
						k3 = 0;
						k4 = 0;
						k5 = 0;
					}
					if ((k > 1.56 && k < 1.58) || (k > 3.13 && k < 3.15) || (k > 4.70 && k < 4.72))
					{
						k2 = pi / 2;
						k3 = 0;
						k4 = 0;
						k5 = 0;
					}
					if ((k < -1.56 && k > -1.58) || (k < -3.13 && k > -3.15) || (k < -4.70 && k > -4.72))
					{
						k2 = pi / 2;
						k3 = 0;
						k4 = 0;
						k5 = 0;
					}

					if ((y == 1 || y==11) && i!=2){
						if ((car_x <= 998 || (k > 1.57 && k < 4.72) || (k<-1.57 && k>-4.72)) && (car_x >= 25 || (k < 1.57 || k > 4.72) || (k > -1.57 && k < -4.72)))
						{
							if ((car_y <= 589 || (k > 3.14 && k < 6.28) || (k<-3.14 && k>-6.28)) && (car_y >= 27 || (k > 0 && k < 3.14) || (k <-3.14 && k > -6.28)))
							{
								//kolizja = kolizja2(car_x, car_y);
								if (kolizja == 0) {
									if (y == 1) {
										if (k > -0.01 && k < 1.56) {
											car_y += k3;
											car_x += k2;
										}
										if (k > 1.56 && k < 3.13) {
											car_y += k2;
											car_x -= k3;
										}
										if (k > 3.13 && k < 4.7) {
											car_y -= k3;
											car_x -= k2;
										}
										if (k > 4.71 && k < 6.28)
										{
											car_y -= k2;
											car_x += k3;
										}

										if (k < -0.01 && k > -1.56) {
											car_y -= k4;
											car_x += k5;
										}
										if (k < -1.56 && k > -3.13) {
											car_y -= k5;
											car_x -= k4;
										}
										if (k < -3.14 && k > -4.7) {
											car_y += k4;
											car_x -= k5;
										}
										if (k < -4.71 && k > -6.28) {
											car_y += k5;
											car_x += k4;
										}
									}
									if (y == 11) {
										if (k >= 0 && k < 1.57) {
											car_y += k4;
											car_x += k5;
										}
										if (k >= 1.57 && k < 3.14) {
											car_y += k5;
											car_x -= k4;
										}
										if (k >= 3.14 && k < 4.71) {
											car_y -= k4;
											car_x -= k5;
										}
										if (k >= 4.71 && k < 6.28)
										{
											car_y -= k5;
											car_x += k4;
										}

										if (k <= -0.01 && k > -1.57) {
											car_y -= k4;
											car_x += k5;
										}
										if (k <= -1.57 && k > -3.14) {
											car_y -= k5;
											car_x -= k4;
										}
										if (k <= -3.14 && k > -4.71) {
											car_y += k4;
											car_x -= k5;
										}
										if (k <= -4.71 && k > -6.28) {
											car_y += k5;
											car_x += k4;
										}
									}
								}
							}
						}
					}

					else if (y == 2 && i!=3)
					{
						if (car_x < 999 && car_x >= 24) {
							if (car_y < 590 && car_y >= 24) {

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


					if (car_x > 98 && car_x < 102 && car_y>123 && car_y < 127)
					{
						p1 = 0;
					}
					if (car_x > 98 && car_x < 102 && car_y>373 && car_y < 377)
					{
						p3 = 0;
					}
					if (car_x > 922 && car_x < 926 && car_y>123 && car_y < 127)
					{
						p2 = 0;
					}
					if (car_x > 98 && car_x < 102 && car_y>373 && car_y < 377)
					{
						p3 = 0;
					}
				}
			}
			if (x == 2) {
				time2 = time2 + 1;
				if (time2 == 120) {
					time1 = 2;
					time11 = 59;
					time2 = 0;
					car_x = 100;
					car_y = 375;
					x = 3;
				}
			}
			if (x == 3)
			{
				if (p == 1) {
					p1 = 1;
						p = 0;
				}
				if (car_2x < 1100) {
					car_2x = car_2x + 2;
					car_3y = car_3y - 1;
					car_4x = car_4x - 3;
				}
				else {
					car_2x = -300;
					car_3y = 578;
					car_4x = 1500;
				}
				
				if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0)
				{
					x = 2;
				}

				time2 = time2 + 1;
				if (time2 == 60) {
					time11 = time11 - 1;
					time2 = 0;
				}
				if (time11 == 0)
				{
					time11 = 59;
					time1 = time1 - 1;
				}

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
					if (k<0)
						k = 2 * pi + k;
					if (k3 < 0)
					{
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
					if (k<0)
						k = 2 * pi + k;
					if (k3 < 0)
					{
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

				if (k <= -6.28 || k >= 6.28)
				{
					k = 0;
					k2 = pi / 2;
					k3 = 0;
					k4 = 0;
					k5 = pi / 2;
				}
				if ((k > 1.56 && k < 1.58) || (k > 3.13 && k < 3.15) || (k > 4.70 && k < 4.72))
				{
					k2 = pi / 2;
					k3 = 0;
					k4 = 0;
					k5 = pi / 2;
				}
				if ((k < -1.56 && k > -1.58) || (k < -3.13 && k > -3.15) || (k < -4.70 && k > -4.72))
				{
					k2 = pi / 2;
					k3 = 0;
					k4 = 0;
					k5 = pi / 2;
				}


				if (y == 1) {
					if ((car_x <= 998 || (k > 1.57 && k < 4.72) || (k<-1.57 && k>-4.72)) && (car_x >= 25 || (k < 1.57 || k > 4.72) || (k > -1.57 && k < -4.72)))
					{
						if ((car_y <= 589 || (k > 3.14 && k < 6.28) || (k<-3.14 && k>-6.28)) && (car_y >= 27 || (k >0 && k < 3.14) || (k <-3.14 && k > -6.28)))
						{
							//kolizja = kolizja2(car_x, car_y);
							if (kolizja == 0) {
								if (k >= 0 && k < 1.57) {
									car_y += k3;
									car_x += k2;
								}
								if (k >= 1.57 && k < 3.14) {
									car_y += k2;
									car_x -= k3;
								}
								if (k >= 3.14 && k < 4.71) {
									car_y -= k3;
									car_x -= k2;
								}
								if (k >= 4.71 && k < 6.28)
								{
									car_y -= k2;
									car_x += k3;
								}

								if (k <= -0.01 && k > -1.57) {
									car_y -= k4;
									car_x += k5;
								}
								if (k <= -1.57 && k > -3.14) {
									car_y -= k5;
									car_x -= k4;
								}
								if (k <= -3.14 && k > -4.71) {
									car_y += k4;
									car_x -= k5;
								}
								if (k <= -4.71 && k > -6.28) {
									car_y += k5;
									car_x += k4;
								}
							}
						}
					}
				}

				else if (y == 2)
				{
					if (car_x < 999 && car_x >= 24) {
						if (car_y<590 && car_y >= 24) {

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

				if (car_x > 98 && car_x < 102 && car_y>123 && car_y < 127)
				{
					p1 = 0;
				}
				if (car_x > 98 && car_x < 102 && car_y>373 && car_y < 377)
				{
					p3 = 0;
				}
				if (car_x > 922 && car_x < 926 && car_y>123 && car_y < 127)
				{
					p2 = 0;
				}
				if (car_x > 98 && car_x < 102 && car_y>373 && car_y < 377)
				{
					p3 = 0;
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
			case ALLEGRO_KEY_ESCAPE:
				key[KEY_ESCAPE] = true;
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
			case ALLEGRO_KEY_ESCAPE:
				key[KEY_ESCAPE] = false;
				if (x == 0)
					x = 1;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_ENTER:
				if (x == 2)
					x =3;
				if (y==1)
					doexit = true;
				else if (x!=2)
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

		    if (x==0)
			{
				al_draw_bitmap(tlo, 0, 0, 0);
				al_draw_bitmap(home, 0, 0, 0);
				al_draw_bitmap(home, 300, 0, 0);
				al_draw_bitmap(home, 824, 0, 0);
				al_draw_bitmap(home, 0, 250, 0);
				al_draw_bitmap(home, 0, 400, 0);
				al_draw_bitmap(home, 300, 250, 0);
				al_draw_bitmap(home, 400, 400, 0);
				al_draw_bitmap(home, 824, 400, 0);
				al_draw_bitmap(home, 730, 250, 0);

				al_draw_bitmap(pole, 50, 100, 0);
				al_draw_bitmap(pole, 874, 100, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 550, 50, 1.57, 0);
				al_draw_bitmap(pole, 50, 350, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 550, 300, 1.57, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 1000, 300, 1.57, 0);
				al_draw_bitmap(pole, 50, 500, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 350, 450, 1.57, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 770, 450, 1.57, 0);
			

				al_draw_bitmap(car2, car_2x, 200, 0);
				al_draw_bitmap(car2, 350, 130, 0);

				if (p1 > 0)
				al_draw_bitmap(paczka, 20, 650, 0);
				if (p4 >0)
				al_draw_bitmap(paczka, 20, 720, 0);
				if (p2> 0)
				al_draw_bitmap(paczka, 90, 650, 0);
				if (p5 >0)
				al_draw_bitmap(paczka, 90, 720, 0);
				if (p3 >0)
				al_draw_bitmap(paczka, 160, 650, 0);
				if (p6 >0)
				al_draw_bitmap(paczka, 160, 720, 0);
				al_draw_bitmap(logo, 250, 648, 0);
				if(s > 0)
				al_draw_bitmap(serce, 550, 648, 0);
				if(s > 1)
				al_draw_bitmap(serce, 550, 678, 0);
				if (s > 2)
				al_draw_bitmap(serce, 550, 708, 0);

				al_draw_text(font, al_map_rgb(255, 255, 255), 694, 688, ALLEGRO_ALIGN_CENTRE, "LVL 1");
				al_draw_text(font, al_map_rgb(255, 255, 255), 915, 678, ALLEGRO_ALIGN_CENTRE, "Exit(ESC)");
				al_draw_textf(font, al_map_rgb(255, 255, 255), 694, 648, ALLEGRO_ALIGN_CENTRE, "%i : %i",time1,time11);

				//textout_ex(tlo, font, 664, 658, al_map_rgb(255, 255, 255), ALLEGRO_ALIGN_CENTRE, "%d", time);
				//al_draw_ustr(font, al_map_rgb(255, 255, 255), 694, 648, ALLEGRO_ALIGN_CENTRE, "3:00");

				al_draw_rotated_bitmap(car2, 50, 25, car_4x, 608, 3.14, 0);
				al_draw_rotated_bitmap(car2, 50, 25,220,car_3y, -1.57, 0);
				al_draw_rotated_bitmap(car2, 50, 25, 710, 300, 1.57, 0);
				al_draw_rotated_bitmap(car,50,25, car_x, car_y, k, 0);

				al_flip_display();
			}

			if(x==2){
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_map_rgb(255, 255, 255), 500, 300, ALLEGRO_ALIGN_CENTRE, "LVL 2");
				al_flip_display();
				}
			
			if (x == 3)
			{
				al_draw_bitmap(tlo, 0, 0, 0);
				al_draw_bitmap(home, 0, 0, 0);
				al_draw_bitmap(home, 300, 0, 0);
				al_draw_bitmap(home, 824, 0, 0);
				al_draw_bitmap(home, 0, 250, 0);
				al_draw_bitmap(home, 0, 400, 0);
				al_draw_bitmap(home, 300, 250, 0);
				al_draw_bitmap(home, 400, 400, 0);
				al_draw_bitmap(home, 824, 400, 0);
				al_draw_bitmap(home, 730, 250, 0);

				al_draw_bitmap(pole, 50, 100, 0);
				al_draw_bitmap(pole, 874, 100, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 550, 50, 1.57, 0);
				al_draw_bitmap(pole, 50, 350, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 550, 300, 1.57, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 1000, 300, 1.57, 0);
				al_draw_bitmap(pole, 50, 500, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 350, 450, 1.57, 0);
				al_draw_rotated_bitmap(pole, 50, 25, 770, 450, 1.57, 0);


				al_draw_bitmap(car2, car_2x, 200, 0);
				al_draw_bitmap(car2, 350, 130, 0);

				if (p1 > 0)
					al_draw_bitmap(paczka, 20, 650, 0);
				if (p4 >0)
					al_draw_bitmap(paczka, 20, 720, 0);
				if (p2> 0)
					al_draw_bitmap(paczka, 90, 650, 0);
				if (p5 >0)
					al_draw_bitmap(paczka, 90, 720, 0);
				if (p3 >0)
					al_draw_bitmap(paczka, 160, 650, 0);
				if (p6 >0)
					al_draw_bitmap(paczka, 160, 720, 0);
				al_draw_bitmap(logo, 250, 648, 0);
				al_draw_bitmap(serce, 550, 648, 0);
				al_draw_bitmap(serce, 550, 678, 0);
				al_draw_bitmap(serce, 550, 708, 0);
				al_draw_text(font, al_map_rgb(255, 255, 255), 694, 688, ALLEGRO_ALIGN_CENTRE, "LVL 2");
				al_draw_text(font, al_map_rgb(255, 255, 255), 915, 678, ALLEGRO_ALIGN_CENTRE, "Exit(ESC)");
				al_draw_textf(font, al_map_rgb(255, 255, 255), 694, 648, ALLEGRO_ALIGN_CENTRE, "%i : %i", time1, time11);

				//textout_ex(tlo, font, 664, 658, al_map_rgb(255, 255, 255), ALLEGRO_ALIGN_CENTRE, "%d", time);
				//al_draw_ustr(font, al_map_rgb(255, 255, 255), 694, 648, ALLEGRO_ALIGN_CENTRE, "3:00");

				al_draw_rotated_bitmap(car2, 50, 25, car_4x, 608, 3.14, 0);
				al_draw_rotated_bitmap(car2, 50, 25, 220, car_3y, -1.57, 0);
				al_draw_rotated_bitmap(car2, 50, 25, 710, 300, 1.57, 0);
				al_draw_rotated_bitmap(car, 50, 25, car_x, car_y, k, 0);

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