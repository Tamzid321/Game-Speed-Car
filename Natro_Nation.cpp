#include "iGraphics.h"
#include "myheader.h"
#include <iostream>

int redcar, taxi, police, ambulance, track, track2, whitecar, fire, guntaxi, life1, life2, life3, gameover;
int poster, play, start, menu, sc_board, devinfo, scorepage, aboutpage, nextlevel, nextlevelimage, home, pause;
int entername;

int front = 1;

char coin[4][20] = {"images\\coin1.bmp", "images\\coin2.bmp", "images\\coin3.bmp", "images\\coin4.bmp"}; //rotating

char score_char[10 + sizeof(char)];


char userNameInput[100];
int userNameInputIndex;
bool name = false;

FILE *fW;
FILE *fR;
int toggle_save = 0;
char players_name[999], char_high_score[100], pre_player[999];
int score_point, pre_score;

///////** MAIN FILE ***/////
void iDraw()
{

	iClear();
	///Poster//

	if (front == 1)
	{
		iShowImage(pic_x, pic_y, 840, 650, poster);
	}

	///Menu////
	if (front == 2)

	{
		iShowImage(pic_x, pic_y, 840, 650, menu);
	}
	//////////////----------LEVEL ONE-------------- ////////////

	if (front == 3)
	{

		iShowImage(0, 0, 840, 650, entername);
		iSetColor(225, 225, 225);
		iText(300, 400, userNameInput, GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(250,380,300,50);
	}
	if (front == 4)
	{
		level = 1;
		iShowImage(0, track_y, 840, 650, track);
		iShowImage(0, track2_y, 840, 650, track2);

		iShowImage(0, 590, 50, 50, home);
		iShowImage(65, 590, 50, 50, pause);

		iShowImage(taxi_x, taxi_y, 50, 100, taxi);
		iShowImage(whitecar_x, whitecar_y, 50, 100, whitecar);
		iShowImage(redcar_x, redcar_y, 50, 100, redcar);
		iShowImage(police_x, police_y, 50, 100, police);
		iShowImage(ambulance_x, ambulance_y, 50, 100, ambulance);

		////-------SCORE------////
		std::sprintf(score_char, "%d", score);
		iText(770, 628, score_char);
		iSetColor(255, 0, 0);
		iText(690, 628, "Score: ");

		// ---------- LIFE -------------- ///
		if (life == 3)
		{
			iShowImage(600, 610, 50, 50, life1);
			iShowImage(620, 610, 50, 50, life2);
			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 2)
		{

			iShowImage(620, 610, 50, 50, life2);
			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 1)
		{

			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 0)
		{
			iPauseTimer(0);
			iShowImage(pic_x, pic_y, 840, 650, gameover);
			iShowImage(0, 590, 50, 50, home);
			if (toggle_save == 0)
			{
				if (score > pre_score)
				{
					fW = fopen("taxi.txt", "w");
					fputs(userNameInput, fW);
					fprintf(fW, "\n%d\n", score);
					fclose(fW);
					toggle_save = 1;
				}
			}

		}

		///////    LEVEL ONE END LOGIC    ////////
		if (score == 100)
		{
			iPauseTimer(0);
			iShowImage(0, 0, 840, 650, nextlevelimage);
			iShowImage(600, -40, 200, 200, nextlevel);

			if (toggle_save == 0)
			{
				if (score > pre_score)
				{
					fW = fopen("taxi.txt", "w");
					fputs(userNameInput, fW);
					fprintf(fW, "\n%d\n", score);
					fclose(fW);
					toggle_save = 1;
				}
			}
		}
	}

	///// ------------------LEVEL TWO-------------------  //////

	if (front == 7)
	{
		level = 2;
		iResumeTimer(0);
		iShowImage(0, track_y, 840, 650, track);
		iShowImage(0, track2_y, 840, 650, track2);

		iShowImage(0, 590, 50, 50, home);
		iShowImage(65, 590, 50, 50, pause);

		iShowImage(taxi_x, taxi_y, 50, 100, taxi);
		iShowImage(whitecar_x, whitecar_y, 50, 100, whitecar);
		iShowImage(redcar_x, redcar_y, 50, 100, redcar);
		iShowImage(police_x, police_y, 50, 100, police);
		iShowImage(ambulance_x, ambulance_y, 50, 100, ambulance);

		/////               COIN           /////////
		iShowBMP2(coin_x, coin_y, coin[coinIndex], 0);
		iShowBMP2(coin2_x, coin2_y, coin[coinIndex], 0);
		iShowBMP2(coin3_x, coin3_y, coin[coinIndex], 0);
		iShowBMP2(coin4_x, coin4_y, coin[coinIndex], 0);

		////   SCORE   //////
		std::sprintf(score_char, "%d", score);
		iText(770, 628, score_char);
		iSetColor(255, 0, 0);
		iText(690, 628, "Score: ");

		// ---------- LIFE -------------- ///
		if (life == 3)
		{
			iShowImage(600, 610, 50, 50, life1);
			iShowImage(620, 610, 50, 50, life2);
			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 2)
		{

			iShowImage(620, 610, 50, 50, life2);
			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 1)
		{

			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 0)
		{
			iPauseTimer(0);
			iShowImage(pic_x, pic_y, 840, 650, gameover);
			iShowImage(0, 590, 50, 50, home);
			if (toggle_save == 0)
			{
				if (score > pre_score)
				{
					fW = fopen("taxi.txt", "w");
					fputs(userNameInput, fW);
					fprintf(fW, "\n%d\n", score);
					fclose(fW);
					toggle_save = 1;
				}
			}
		}

		///////    LEVEL TWO END LOGIC    ////////
		if (score == 200)
		{
			iPauseTimer(0);
			iShowImage(0, 0, 840, 650, nextlevelimage);
			iShowImage(100, -50, 200, 200, nextlevel);
			if (toggle_save == 0)
			{
				if (score > pre_score)
				{
					fW = fopen("taxi.txt", "w");
					fputs(userNameInput, fW);
					fprintf(fW, "\n%d\n", score);
					fclose(fW);
					toggle_save = 1;
				}
			}
		}
	}

	////-------------------- LEVEL THREEE-------------------------- /////
	if (front == 8)
	{
		level = 3;
		iResumeTimer(0);
		iShowImage(0, track_y, 840, 650, track);
		iShowImage(0, track2_y, 840, 650, track2);

		iShowImage(0, 590, 50, 50, home);
		//iShowImage(65,590,50,50,pause);

		iShowImage(taxi_x, taxi_y, 50, 100, guntaxi);
		iShowImage(whitecar_x, whitecar_y, 50, 100, whitecar);
		iShowImage(redcar_x, redcar_y, 50, 100, redcar);
		iShowImage(police_x, police_y, 50, 100, police);
		iShowImage(ambulance_x, ambulance_y, 50, 100, ambulance);

		iShowBMP2(coin_x, coin_y, coin[coinIndex], 0);
		iShowBMP2(coin2_x, coin2_y, coin[coinIndex], 0);
		iShowBMP2(coin3_x, coin3_y, coin[coinIndex], 0);
		iShowBMP2(coin4_x, coin4_y, coin[coinIndex], 0);

		iShowImage(fire_x, fire_y, 30, 30, fire);

		////   SCORE   //////
		std::sprintf(score_char, "%d", score);
		iText(770, 628, score_char);
		iSetColor(255, 0, 0);
		iText(690, 628, "Score: ");

		// ---------- LIFE -------------- ///
		if (life == 3)
		{
			iShowImage(600, 610, 50, 50, life1);
			iShowImage(620, 610, 50, 50, life2);
			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 2)
		{

			iShowImage(620, 610, 50, 50, life2);
			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 1)
		{

			iShowImage(640, 610, 50, 50, life3);
		}
		if (life == 0)
		{
			iPauseTimer(0);
			iShowImage(pic_x, pic_y, 840, 650, gameover);
			iShowImage(0, 590, 50, 50, home);
			if (toggle_save == 0)
			{
				if (score > pre_score)
				{
					fW = fopen("taxi.txt", "w");
					fputs(userNameInput, fW);
					fprintf(fW, "\n%d\n", score);
					fclose(fW);
					toggle_save = 1;
				}
			}
		}

		///////    LEVEL Three END LOGIC    ////////
		if (score == 300)
		{
			iPauseTimer(0);
			iShowImage(0, 0, 840, 650, nextlevelimage);
			iShowImage(0, 590, 50, 50, home);
			if (toggle_save == 0)
			{
				if (score > pre_score)
				{
					fW = fopen("taxi.txt", "w");
					fputs(userNameInput, fW);
					fprintf(fW, "\n%d\n", score);
					fclose(fW);
					toggle_save = 1;
				}
			}
		}
	}

	///-----------------HIGH SCORE--------------------//
	if (front == 5)
	{
		iShowImage(pic_x, pic_y, 840, 650, scorepage);


		iShowImage(0, 590, 50, 50, home);
		fscanf(fR, "%s%d", &players_name, &score_point);
		sprintf(char_high_score, "%s %d", players_name, score_point);
		iText(300, 300, char_high_score,GLUT_BITMAP_HELVETICA_18);
	}
	//-----------------about-------------------///
	if (front == 6)
	{
		iShowImage(pic_x, pic_y, 840, 650, aboutpage);

		iShowImage(0, 590, 50, 50, home);
	}
}

void iMouseMove(int mx, int my)
{
	printf("(x,y):%d,%d \n", mx, my);
}

void iPassiveMouse(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		////play button///

		if (front == 1)
		{
			if (mx >= 300 && mx <= 450)
			{
				if (my >= -20 && my <= 60)
				{
					front = 2;
				}
			}
		}

		///start button////
		if (front == 2)
		{
			if (mx >= 330 && mx <= 530)
			{
				if (my >= 420 && my <= 470)
				{
					front = 3;
				}
			}
		}

		//// LEVEL TWO BUTTON /////
		if (mx >= 600 && mx <= 800)
		{
			if (my >= -40 && my <= 240)
			{
				front = 7;
			}
		}

		///HIGH SCORE///
		if (mx >= 290 && mx <= 490)
		{
			if (my >= 260 && my <= 320)
			{
				fR = fopen("taxi.txt", "r");
				front = 5;
			}
		}

		//About//
		if (mx >= 290 && mx <= 490)
		{
			if (my >= 140 && my <= 180)
			{
				front = 6;
			}
		}

		//HOME//
		if (mx >= 0 && mx <= 50)
		{
			if (my >= 590 && my <= 640)
			{
				front = 2;
			}
		}
		//pause//
		if (mx >= 65 && mx <= 105)
		{
			if (my >= 590 && my <= 640)
			{
				iPauseTimer(0);
			}
		}

		//// LEVEL three BUTTON /////
		if (mx >= 100 && mx <= 300)
		{
			if (my >= -50 && my <= 150)
			{
				front = 8;
			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{

		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
	if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
	{

		userNameInput[userNameInputIndex++] = key;
	}
	if (key == '\b')
	{
		userNameInputIndex--;

		if (userNameInputIndex < 0) // used to prevent array out of index error
		{
			userNameInputIndex = 0;
		}

		userNameInput[userNameInputIndex] = '\0'; //erases the previous character
	}
	if (key == '\r')
	{
		strcpy(details[0].name, userNameInput);
		printf("%s", details[0].name);
		printf("%s",userNameInput);
		front = 4;
		name = true;
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_UP)
	{
		taxi_y = taxi_y + 15;
	}
	if (key == GLUT_KEY_DOWN)
	{
		taxi_y = taxi_y - 15;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		taxi_x = taxi_x + 15;
	}
	if (key == GLUT_KEY_LEFT)
	{
		taxi_x = taxi_x - 15;
	}
}

int main()
{

	iInitialize(840, 650, "TAXIMAMA");

	iSetTimer(20, objectChange);

	iSetTimer(200, coinChange);

	dx = 5;
	dy = 5;

	track_y = 0;
	track2_y = 650;

	taxi_x = 400;
	taxi_y = 0;

	redcar_x = 200;
	redcar_y = 1000;

	police_x = 400;
	police_y = 1800;

	whitecar_x = 480;
	whitecar_y = 1400;

	ambulance_x = 600;
	ambulance_y = 1600;

	coin_x = 400;
	coin_y = 300;

	coin2_x = 500;
	coin2_y = 400;

	coin3_x = 600;
	coin3_y = 500;

	coin4_x = 250;
	coin4_y = 450;

	fire_x = taxi_x + 12;
	fire_y = taxi_y + 100;

	taxi = iLoadImage("images\\taxi2.png");
	guntaxi = iLoadImage("images\\guntaxi.png");
	redcar = iLoadImage("images\\redcar.png");
	whitecar = iLoadImage("images\\whitecar.png");
	police = iLoadImage("images\\police.png");
	ambulance = iLoadImage("images\\ambulance.png");

	track = iLoadImage("images\\bk1.png");
	track2 = iLoadImage("images\\bk2.png");

	poster = iLoadImage("images\\poster2.png");
	play = iLoadImage("images\\play.png");

	menu = iLoadImage("images\\menu2.png");
	start = iLoadImage("images\\start.png");
	sc_board = iLoadImage("images\\highs.png");
	devinfo = iLoadImage("images\\about.png");
	nextlevel = iLoadImage("images\\nextlevel.png");
	nextlevelimage = iLoadImage("images\\congo.png");

	scorepage = iLoadImage("images\\scorebk.png");
	aboutpage = iLoadImage("images\\aboutbk.png");

	home = iLoadImage("images\\home.png");
	pause = iLoadImage("images\\pause.png");

	fire = iLoadImage("images\\fire.png");

	life1 = iLoadImage("images\\life.png");
	life2 = iLoadImage("images\\life.png");
	life3 = iLoadImage("images\\life.png");

	gameover = iLoadImage("images\\gameover.png");
	entername = iLoadImage("images\\entername.png");

	fR = fopen("taxi.txt", "r");
	if (fR == NULL)
	{
		fW = fopen("taxi.txt", "w");
	}
	fscanf(fR, "%s%d", &pre_player, &pre_score);
	// printf("%d", pre_score);
	iStart();

	return 0;
}
