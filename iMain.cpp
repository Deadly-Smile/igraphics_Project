/*
Created by :
Anik Saha ( 190115 )
Shimul Hoassain ( 190114 )
Anamul Haque ( 190113 )
Project:- Object Oriented Programming Sessional (CSE-1202)
Course Teacher:- Md.Toukir Ahmed (Lecturer)
Department:- Computer Science and Engineering
Pabna University of Science and Technology
*/
#define _CRT_SECURE_NO_DEPRECATE
#include "iGraphics.h"
/*//////////functions initialization///////////*/
void fourth_stage();
void loading();
void manu();
void score_system();
void levels();
void character_movement();
void creating_object_at_random();
void colution();
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
/*This is Home screen and other stafs*/
short int game_stage{ -1 };
short int screen_x{ 1000 }, screen_y{ 667 };
short int character_width{ 105 }, charater_higth{ 168 };
int score{ 0 }, backup{ 0 };
char score_string[7] = { "000000" };
short int loop_count{ 0 };
char in_about[] = { "bmp\\in_about.bmp" };
char home_manu[] = { "bmp\\music_on.bmp" };
char home_manu_off[] = { "bmp\\music_off.bmp" };
char in_control[] = { "bmp\\control.bmp" };
char loading_screen[] = { "bmp\\loading.bmp" };
char high_score_screen[] = { "bmp\\high_score.bmp" };
short int is_on{ 0 };
bool is_music_on{ true };
/*:::::::End::::::::::

/*In game character and objects

/*::::::objects:::::*/
struct Apple{
	short int apple_x, apple_y;
}apple[3];
struct Fire
{
	short int fire_x, fire_y;
}fire[5];

char apple_obj[] = { "loading\\apple.bmp" };
char fire_obj[] = { "loading\\fire.bmp" };
bool object_1{ true }, object_2{ true }, object_3{ true };
bool object_4{ true }, object_5{ true }, object_6{ false }, object_7{ false }, object_8{ false };
bool only_once{ true };
/*:::::objects:::::*/
//////////     Level       //////////

bool level_0{ true }, level_1{ false }, level_2{ false }, level_3{ false }, final_level{ false };

//////////     Level       //////////
char a_character[8][43] = { "char\\a1.bmp", "char\\a2.bmp","char\\a3.bmp", "char\\a4.bmp",
							"char\\a5.bmp", "char\\a6.bmp","char\\a7.bmp", "char\\a8.bmp" };

char d_character[8][43] = { "char\\d1.bmp", "char\\d2.bmp","char\\d3.bmp", "char\\d4.bmp",
							"char\\d5.bmp", "char\\d6.bmp","char\\d7.bmp", "char\\d8.bmp", };

char loading_bar[9][50] = { "loading\\lo_1.bmp", "loading\\lo_2.bmp","loading\\lo_3.bmp", "loading\\lo_4.bmp",
							"loading\\lo_5.bmp", "loading\\lo_6.bmp","loading\\lo_7.bmp", "loading\\lo_8.bmp",
							"loading\\lo_9.bmp", };
char in_game[] = { "bmp\\in_game.bmp" };

short int loading_bar_index{ 0 };
short int loading_time{ 0 };
char idle_d[] = { "char\\idle_d.bmp" };
char idle_a[] = { "char\\ldle_a.bmp" };
/*    game_over     */
char dead2_d[] = { "char\\dead2_d.bmp" };
char game_over[] = { "bmp\\game_over.bmp" };

bool is_stand{ true };
short int standing_timer{ 0 };
bool character_looking_side{ true };
short int character_x{ 500 }, chararcter_y{ 12 };
short int character_index{ 0 };
short int dx{ 15 };
short int dy{ 4 };
/*    hi score variables     */
int hi_score{ 0 };
bool game_start{ true };
/*:::::::end::::::::::*/
void iDraw()
{
	iClear();
	if (game_stage == -1){
		loading();
	}
	else if (game_stage == 0){
		manu();
	}
	else if (game_stage == 1){
		iShowBMP(0, 0, in_game);
		score_system();
		levels();
		character_movement();
		creating_object_at_random();
		colution();		
	}
	else if (game_stage == 2){
		iShowBMP(0, 0, in_control);
	}
	else if (game_stage == 3){
		iShowBMP(0, 0, in_about);
	}
	else if (game_stage == 4){
		fourth_stage();
	}
	else if (game_stage == 5){
		iShowBMP(0, 0, high_score_screen);
		backup = hi_score;
		for (loop_count = 6; loop_count >= 0; loop_count--){
			score_string[loop_count] = backup % 10 + 48;
			backup /= 10;
		}
		iSetColor(180, 0, 0);
		iText(450, 335, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
/*//////////user defined functions////////////////*/
void loading(){
	iShowBMP(0, 0, loading_screen);
	iShowBMP2(350, 200, loading_bar[loading_bar_index], 255);
	loading_time++;
	if (loading_time >= 10){
		loading_time = 0;
		loading_bar_index++;
	}
	if (loading_bar_index >= 9){
		game_stage++;
	}
	if (game_start){
		FILE *flp = nullptr;
		flp = fopen("hi_score.txt", "r");
		if (flp != nullptr){
			fscanf(flp, "%d", &hi_score);
		}
		else{
			printf("file did not open\n");
		}
		game_start = false;
		fclose(flp);
	}
}
void manu(){
	if (is_on % 2 == 0){
		iShowBMP(0, 0, home_manu);
	}
	else
	{
		iShowBMP(0, 0, home_manu_off);
	}
}
void score_system(){
	backup = score;
	for (loop_count = 6; loop_count >= 0; loop_count--){
		score_string[loop_count] = backup % 10 + 48;
		backup /= 10;
	}
	iSetColor(180, 0, 0);
	iText(20, 630, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
}
void levels(){
	if (only_once && level_0){
		only_once = false;
		object_1 = true;
		object_2 = true;
		object_3 = true;
		object_4 = true;
		object_5 = true;
	}
	if (score > 10 && level_0){
		level_1 = true;
		level_0 = false;
		dy = 5;
	}
	if (score > 17 && level_1){
		level_2 = true;
		level_1 = false;
		dy = 5;
		object_6 = true;
	}
	if (score > 26 && level_2){
		level_3 = true;
		level_2 = false;
		dy = 7;
	}
	if (score > 33 && level_3){
		final_level = true;
		level_3 = false;
		object_7 = true;
		object_8 = true;
		dy = 8;
	}
}
void fourth_stage(){
	iShowBMP(0, 0, game_over);
	final_level = false;
	level_0 = true;
	object_1 = false;
	object_2 = false;
	object_3 = false;
	object_4 = false;
	object_5 = false;
	object_6 = false;
	object_7 = false;
	object_8 = false;
	dy = 4;
	iSetColor(180, 0, 0);
	iText(450, 285, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
	if (score > hi_score){
		hi_score = score;
		FILE *flp = nullptr;
		flp = fopen("hi_score.txt", "w");
		if (flp != nullptr){
			fprintf(flp, "%d", hi_score);
		}
		else{
			printf("file did not open\n");
		}
		fclose(flp);
	}
	score = 0;
}
void character_movement(){
	if (character_looking_side){
		if (is_stand)
			iShowBMP2(character_x, chararcter_y, idle_d, 255);
		if (!is_stand){
			iShowBMP2(character_x, chararcter_y, d_character[character_index], 255);
			if (standing_timer > 20){
				standing_timer = 0;
				character_index = 0;
				iShowBMP2(character_x, chararcter_y, d_character[0], 255);
				is_stand = true;
			}
		}
	}
	else if (!character_looking_side){
		if (is_stand)
			iShowBMP2(character_x, chararcter_y, idle_a, 255);
		if (!is_stand){
			iShowBMP2(character_x, chararcter_y, a_character[character_index], 255);
			if (standing_timer > 20){
				standing_timer = 0;
				character_index = 0;
				iShowBMP2(character_x, chararcter_y, a_character[0], 255);
				is_stand = true;
			}
		}
	}
	standing_timer++;
}
void creating_object_at_random(){
	srand(time(nullptr));
	if (object_1){
		apple[0].apple_x = rand() % 10 * 100;
		apple[0].apple_y = 750;
		object_1 = false;
	}
	if (object_2){
		apple[1].apple_x = rand() % 10 * 100;
		apple[1].apple_y = 888;
		object_2 = false;
	}
	if (object_3){
		apple[2].apple_x = rand() % 10 * 100;
		apple[2].apple_y = 700;
		object_3 = false;
	}
	if (object_4){
		fire[0].fire_x = rand() % 10 * 100;
		fire[0].fire_y = 822;
		object_4 = false;
	}
	if (object_5){
		fire[1].fire_x = rand() % 10 * 100;
		fire[1].fire_y = 812;
		object_5 = false;
	}
	if (object_6){
		fire[2].fire_x = rand() % 10 * 100;
		fire[2].fire_y = 742;
		object_6 = false;
	}
	if (object_7){
		fire[3].fire_x = rand() % 10 * 100;
		fire[3].fire_y = 699;
		object_7 = false;
	}
	if (object_8){
		fire[4].fire_x = rand() % 10 * 100;
		fire[4].fire_y = 690;
		object_8 = false;
	}
	iShowBMP2(apple[1].apple_x, apple[1].apple_y, apple_obj, 0);
	iShowBMP2(apple[2].apple_x, apple[2].apple_y, apple_obj, 0);
	iShowBMP2(apple[0].apple_x, apple[0].apple_y, apple_obj, 0);
	iShowBMP2(fire[0].fire_x, fire[0].fire_y, fire_obj, 0);
	iShowBMP2(fire[1].fire_x, fire[1].fire_y, fire_obj, 0);
	if (score >= 18)
		iShowBMP2(fire[2].fire_x, fire[2].fire_y, fire_obj, 0);
	if (score >= 34){
		iShowBMP2(fire[3].fire_x, fire[3].fire_y, fire_obj, 0);
		iShowBMP2(fire[4].fire_x, fire[4].fire_y, fire_obj, 0);
	}
	apple[0].apple_y -= dy;
	apple[1].apple_y -= dy;
	apple[2].apple_y -= dy;
	fire[0].fire_y -= dy;
	fire[1].fire_y -= dy;
	if (score >= 18)
		fire[2].fire_y -= dy;
	if (score >= 34){
		fire[3].fire_y -= dy;
		fire[4].fire_y -= dy;
	}
}
void colution(){
	if (apple[0].apple_y <= 0 || (apple[0].apple_x + 25 >= character_x && apple[0].apple_x <= character_x + character_width) && (apple[0].apple_y <= charater_higth))
	{
		if ((apple[0].apple_x + 25 >= character_x && apple[0].apple_x <= character_x + character_width) && (apple[0].apple_y <= charater_higth)){
			score++;
		}
		object_1 = true;
	}if (apple[1].apple_y <= 0 || (apple[1].apple_x + 25 >= character_x && apple[1].apple_x <= character_x + character_width) && (apple[1].apple_y <= charater_higth))
	{
		if ((apple[1].apple_x + 25 >= character_x && apple[1].apple_x <= character_x + character_width) && (apple[1].apple_y <= charater_higth)){
			score++;
		}
		object_2 = true;
	}if (apple[2].apple_y <= 0 || (apple[2].apple_x + 25 >= character_x && apple[2].apple_x <= character_x + character_width) && (apple[2].apple_y <= charater_higth))
	{
		if ((apple[2].apple_x + 25 >= character_x && apple[2].apple_x <= character_x + character_width) && (apple[2].apple_y <= charater_higth)){
			score++;
		}
		object_3 = true;
	}if (fire[0].fire_y <= 0 || (fire[0].fire_x + 25 >= character_x && fire[0].fire_x <= character_x + character_width) && (fire[0].fire_y <= charater_higth)){
		if ((fire[0].fire_x + 25 >= character_x && fire[0].fire_x <= character_x + character_width) && (fire[0].fire_y <= charater_higth)){
			game_stage = 4;
			iShowBMP2(character_x, chararcter_y, dead2_d, 255);
		}
		object_4 = true;
	}if (fire[1].fire_y <= 0 || (fire[1].fire_x + 25 >= character_x && fire[1].fire_x <= character_x + character_width) && (fire[1].fire_y <= charater_higth)){
		if ((fire[1].fire_x + 25 >= character_x && fire[1].fire_x <= character_x + character_width) && (fire[1].fire_y <= charater_higth)){
			game_stage = 4;
			iShowBMP2(character_x, chararcter_y, dead2_d, 255);
		}
		object_5 = true;
	}if (fire[2].fire_y <= 0 || (fire[2].fire_x + 25 >= character_x && fire[2].fire_x <= character_x + character_width) && (fire[2].fire_y <= charater_higth)){
		if ((fire[2].fire_x + 25 >= character_x && fire[2].fire_x <= character_x + character_width) && (fire[2].fire_y <= charater_higth)){
			game_stage = 4;
			iShowBMP2(character_x, chararcter_y, dead2_d, 255);
		}
		object_6 = true;
	}if (fire[3].fire_y <= 0 || (fire[3].fire_x + 25 >= character_x && fire[3].fire_x <= character_x + character_width) && (fire[3].fire_y <= charater_higth)){
		if ((fire[3].fire_x + 25 >= character_x && fire[3].fire_x <= character_x + character_width) && (fire[3].fire_y <= charater_higth)){
			game_stage = 4;
			iShowBMP2(character_x, chararcter_y, dead2_d, 255);
		}
		object_7 = true;
	}if (fire[4].fire_y <= 0 || (fire[4].fire_x + 25 >= character_x && fire[4].fire_x <= character_x + character_width) && (fire[4].fire_y <= charater_higth)){
		if ((fire[4].fire_x + 25 >= character_x && fire[4].fire_x <= character_x + character_width) && (fire[4].fire_y <= charater_higth)){
			game_stage = 4;
			iShowBMP2(character_x, chararcter_y, dead2_d, 255);
		}
		object_8 = true;
	}
}
/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (game_stage == 0){
			if (mx >= 500 && mx <= 766 && my >= 447 && my <= 517)
			{
				only_once = true;
				game_stage = 1;
			}
			else if (mx >= 500 && mx <= 766 && my >= 274 && my <= 344)
			{
				game_stage = 2;
			}
			else if (mx >= 500 && mx <= 766 && my >= 188 && my <= 258)
			{
				game_stage = 3;
			}
			else if (mx >= 500 && mx <= 766 && my >= 102 && my <= 172)
			{
				exit(1);
			}
			else if (mx >= 36 && mx <= 150 && my >= 515 && my <= 607)
			{
				if (is_on == 1000){
					is_on = 0;
				}
				is_on++;
				if (is_music_on){
					is_music_on = false;
					PlaySound(0, 0, 0);
				}
				else{
					is_music_on = true;
					PlaySound("bmp\\mu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				game_stage = 0;
			}
			else if (mx >= 500 && mx <= 766 && my >= 361 && my <= 431){
				game_stage = 5;
			}
		}
		else if (game_stage == 2){
			if (mx >= 873 && mx <= 976 && my >= 487 && my <= 590)
			{
				game_stage = 0;
			}
		}
		else if (game_stage == 3){
			if (mx >= 873 && mx <= 976 && my >= 469 && my <= 572)
			{
				game_stage = 0;
			}
		}
		else if (game_stage==4)
		{
			if (mx >= 873 && mx <= 976 && my >= 469 && my <= 572)
			{
				game_stage = 0;
			}
			if (mx >= 322 && mx <= 666 && my >= 84 && my <= 184){
				only_once = true;
				game_stage = 1;
			}
		}
		else if (game_stage == 5){
			if (mx >= 368 && mx <= 630 && my >= 210 && my <= 280){
				hi_score = 0;
				FILE *flp = nullptr;
				flp = fopen("hi_score.txt", "w");
				if (flp != nullptr){
					fprintf(flp, "%d", hi_score);
				}
				else{
					printf("file did not open\n");
				}
				fclose(flp);
			}
			if (mx >= 873 && mx <= 976 && my >= 469 && my <= 572)
			{
				game_stage = 0;
			}
		}		
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{

	}
	if (key == 'd'){
		character_index++;
		character_looking_side = true;
		character_x += dx;
		if (character_index >= 8){
			character_index = 0;
		}
		if (character_x >= 1000){
			character_x = 0;
		}
		is_stand = false;
	}
	else if (key == 'a'){
		character_index++;
		character_looking_side = false;
		character_x -= dx;
		if (character_index >= 8){
			character_index = 0;
		}
		if (character_x < 0){
			character_x = 1000;
		}
		is_stand = false;
	}



}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{
		character_index++;
		character_looking_side = true;
		character_x += dx;
		if (character_index >= 8){
			character_index = 0;
		}
		if (character_x >= 1000){
			character_x = 0;
		}
		is_stand = false;
	}
	if (key == GLUT_KEY_LEFT)
	{
		character_index++;
		character_looking_side = false;
		character_x -= dx;
		if (character_index >= 8){
			character_index = 0;
		}
		if (character_x < 0){
			character_x = 1000;
		}
		is_stand = false;
	}

	if (key == GLUT_KEY_HOME)
	{

	}

}
/// loading character moving variable
int main()
{
	if (is_music_on){
		PlaySound("bmp\\mu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	FILE *fp = nullptr;

	iInitialize(screen_x, screen_y, "Advanturer");
	///updated see the documentations
	iStart();
	return 0;
}