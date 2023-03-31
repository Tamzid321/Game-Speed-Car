#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int pic_x, pic_y,track_x,track_y,track2_x,track2_y;
int dx, dy,tx,ty;
int redcar_y,redcar_x,red;
int taxi_x,taxi_y;
int police_x,police_y;
int whitecar_x, whitecar_y;
int ambulance_x,ambulance_y;

int level = 0;
int life = 3;

int score = 0;


int car_point = 10;


//int red=0;
int white=0;

int fire_x,fire_y;

int coin_x,coin_y,coinIndex=0;
int coin2_x,coin2_y;
int coin3_x,coin3_y;
int coin4_x,coin4_y;

struct details{
    char name[100];
    int point;
} details[20];


void coinChange()
{
	coinIndex++;
	if (coinIndex>=3)
		coinIndex=0;
}

void objectChange() {

	//level-1-------------------------------------------------------------------------------------------------------
	if(level==1){
		track_y -= dy;
	track2_y -= dy;

	redcar_y -= dy+5;
	police_y -= dy+5;
	ambulance_y -= dy+5;
	whitecar_y -= dy+5;

	if(track2_y == 0)
	{
		track_y=0;
		track2_y=650;
	}

	if(redcar_y == -100)
	{
		redcar_x=(rand() % (280-130) )+ 130;
		
		redcar_y=650;
		 score+= car_point;
	}

	if(police_y == -100)
	{
		police_x=(rand() % (560-431) )+ 431;
		
		police_y=650;
		score+= car_point;
	}

	if(ambulance_y == -100)
	{
		ambulance_x=(rand() % (420-271) )+ 271;
		
		ambulance_y=650;
		score+= car_point;
	}

	if(whitecar_y == -100)
	{
		whitecar_x=(rand() % (700-561) )+ 561;
		
		whitecar_y=650;
		score+= car_point;
	}


	
	/*redcar_x=redcar_x+red;
	red=red*(-1);
	police_x=police_x+red;
	red=red*(-1);
	tank_x=tank_x+red;
	red=red*(-1);*/

	
	////// CAR COLLUSION ///////
	
	if(taxi_y+50>=redcar_y && taxi_y<=redcar_y+100 && taxi_x+50>=redcar_x && taxi_x<=redcar_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		redcar_x=(rand() % (700-561) )+ 561; 
		redcar_y=1000;
		life--;
		
	}
	if(taxi_y+50>=police_y && taxi_y<=police_y+100 && taxi_x+50>=police_x && taxi_x<=police_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		police_x=(rand() % (560-431) )+ 431; ;
		police_y=700;
		life--;
	}
	if(taxi_y+50>=ambulance_y && taxi_y<=ambulance_y+100 && taxi_x+50>=ambulance_x && taxi_x<=ambulance_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		ambulance_x=(rand() % (420-271) )+ 271; 
		ambulance_y=1200;
		life--;
	}
	if(taxi_y+50>=whitecar_y && taxi_y<=whitecar_y+100 && taxi_x+50>=whitecar_x && taxi_x<=ambulance_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		whitecar_x=(rand() % (280-130) )+ 130; 
		whitecar_y=800;
		life--;
	}



	}

	//level-2------------------------------------------------------------------------------------------------------
	if(level==2){

		track_y -= dy;
	track2_y -= dy;

	redcar_y -= dy+5;
	police_y -= dy+5;
	ambulance_y -= dy+5;
	whitecar_y -= dy+5;

	if(track2_y == 0)
	{
		track_y=0;
		track2_y=650;
	}

	if(redcar_y == -100)
	{
		redcar_x=(rand() % (280-130) )+ 130;
		
		redcar_y=650;
		 
	}

	if(police_y == -100)
	{
		police_x=(rand() % (560-431) )+ 431;
		
		police_y=650;
		
	}

	if(ambulance_y == -100)
	{
		ambulance_x=(rand() % (420-271) )+ 271;
		
		ambulance_y=650;
		
	}

	if(whitecar_y == -100)
	{
		whitecar_x=(rand() % (700-561) )+ 561;
		
		whitecar_y=650;
		
	}


	
	/*redcar_x=redcar_x+red;
	red=red*(-1);
	police_x=police_x+red;
	red=red*(-1);
	tank_x=tank_x+red;
	red=red*(-1);*/

	
	////// CAR COLLUSION ///////
	
	if(taxi_y+50>=redcar_y && taxi_y<=redcar_y+100 && taxi_x+50>=redcar_x && taxi_x<=redcar_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		redcar_x=(rand() % (700-561) )+ 561; 
		redcar_y=1000;
		life--;
		
	}
	if(taxi_y+50>=police_y && taxi_y<=police_y+100 && taxi_x+50>=police_x && taxi_x<=police_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		police_x=(rand() % (560-431) )+ 431; ;
		police_y=700;
		life--;
	}
	if(taxi_y+50>=ambulance_y && taxi_y<=ambulance_y+100 && taxi_x+50>=ambulance_x && taxi_x<=ambulance_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		ambulance_x=(rand() % (420-271) )+ 271; 
		ambulance_y=1200;
		life--;
	}
	if(taxi_y+50>=whitecar_y && taxi_y<=whitecar_y+100 && taxi_x+50>=whitecar_x && taxi_x<=ambulance_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		whitecar_x=(rand() % (280-130) )+ 130; 
		whitecar_y=800;
		life--;
	}

	coin_y -= dy;
	coin2_y -= dy;
	coin3_y -= dy;
	coin4_y -= dy;

	/////   COIN COLUUSION   ///////

	if(coin_y == -75)
	{
		coin4_x=(rand() % (700-130) )+ 130; 
		coin4_y=650;
	}
	if(coin2_y == -75)
	{
		coin3_x=(rand() % (700-130) )+ 130; 
		coin3_y=650;
	}
	if(coin3_y == -75)
	{
		coin2_x=(rand() % (700-130) )+ 130; 
		coin2_y=650;
	}if(coin4_y == -75)
	{
		coin_x=(rand() % (700-130) )+ 130; 
		coin_y=650;
	}


	if( taxi_y+90>=coin_y && taxi_y<=coin_y+70 && taxi_x+50>=coin_x && taxi_x<=coin_x+70 )
	{
		coin_x=(rand() % (700-130) )+ 130; 
		coin_y=650;
		score+= car_point;
	}
	if(taxi_y+90>=coin2_y && taxi_y<=coin2_y+70 && taxi_x+50>=coin2_x && taxi_x<=coin2_x+70)
	{
		coin2_x=(rand() % (700-130) )+ 130; 
		coin2_y=650;
		score+= car_point;
	}
	if(taxi_y+90>=coin3_y && taxi_y<=coin3_y+70 && taxi_x+50>=coin3_x && taxi_x<=coin3_x+70)
	{
		coin3_x=(rand() % (700-130) )+ 130; 
		coin3_y=650;
		score+= car_point;
	}
	if(taxi_y+90>=coin4_y && taxi_y<=coin4_y+70 && taxi_x+50>=coin4_x && taxi_x<=coin4_x+70)
	{
		coin4_x=(rand() % (700-130) )+ 130; 
		coin4_y=650;
		score+= car_point;
	}


	}

	//level-3----------------------------------------------------------------------------------------------
	if(level==3){
	
		track_y -= dy;
	track2_y -= dy;

	redcar_y -= dy+5;
	police_y -= dy+5;
	ambulance_y -= dy+5;
	whitecar_y -= dy+5;
	

	coin_y -= dy;
	coin2_y -= dy;
	coin3_y -= dy;
	coin4_y -= dy;

	fire_y += 15;

	if(fire_y >= 700)
	{
		fire_x=taxi_x+12;
		fire_y=taxi_y+100;
	}


	if(track2_y == 0)
	{
		track_y=0;
		track2_y=650;
	}


	if(redcar_y == -100)
	{
		redcar_x=(rand() % (280-130) )+ 130;
		
		redcar_y=650;
		 score+= car_point;
	}

	if(police_y == -100)
	{
		police_x=(rand() % (560-431) )+ 431;
		
		police_y=650;
		score+= car_point;
	}

	if(ambulance_y == -100)
	{
		ambulance_x=(rand() % (420-271) )+ 271;
		
		ambulance_y=650;
		score+= car_point;
	}

	if(whitecar_y == -100)
	{
		whitecar_x=(rand() % (700-561) )+ 561;
		
		whitecar_y=650;
		score+= car_point;
	}


	
	/*redcar_x=redcar_x+red;
	red=red*(-1);
	police_x=police_x+red;
	red=red*(-1);
	tank_x=tank_x+red;
	red=red*(-1);*/

	
	////// CAR COLLUSION ///////
	
	if(taxi_y+50>=redcar_y && taxi_y<=redcar_y+100 && taxi_x+50>=redcar_x && taxi_x<=redcar_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		redcar_x=(rand() % (700-561) )+ 561; 
		redcar_y=1000;
		life--;
		
	}
	if(taxi_y+50>=police_y && taxi_y<=police_y+100 && taxi_x+50>=police_x && taxi_x<=police_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		police_x=(rand() % (560-431) )+ 431; ;
		police_y=700;
		life--;
	}
	if(taxi_y+50>=ambulance_y && taxi_y<=ambulance_y+100 && taxi_x+50>=ambulance_x && taxi_x<=ambulance_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		ambulance_x=(rand() % (420-271) )+ 271; 
		ambulance_y=1200;
		life--;
	}
	if(taxi_y+50>=whitecar_y && taxi_y<=whitecar_y+100 && taxi_x+50>=whitecar_x && taxi_x<=ambulance_x+50)
	{
		taxi_x=400;
		taxi_y=0;

		whitecar_x=(rand() % (280-130) )+ 130; 
		whitecar_y=800;
		life--;
	}

	///// FIre /////
	if(redcar_y == -100 || fire_x>=redcar_x-8 && fire_x<=redcar_x+50 && fire_y+30 >= redcar_y)
	{
		redcar_x=(rand() % (270-130) )+ 130;
		redcar_y=650;
		score+= car_point;
	}
	if(police_y == -100  || fire_x>=police_x-5 && fire_x<=police_x+50 && fire_y+30 >= police_y)
	{
		police_x=(rand() % (550-431) )+ 431;
		police_y=650;
		score+= car_point;
	}
	if(ambulance_y == -100  || fire_x>=ambulance_x-10 && fire_x<=ambulance_x+50 && fire_y+30 >= ambulance_y)
	{
		ambulance_x=(rand() % (410-261) )+ 261; 
		ambulance_y=650;
		score+= car_point;
	}
	if(whitecar_y == -100  || fire_x>=whitecar_x-5 && fire_x<=whitecar_x+50 && fire_y+30 >= whitecar_y )
	{
		whitecar_x=(rand() % (700-561) )+ 561; 
		whitecar_y=650;
		score+= car_point;
	}

	/////   COIN COLUUSION   ///////

	if(coin_y == -75)
	{
		coin4_x=(rand() % (700-130) )+ 130; 
		coin4_y=650;
	}
	if(coin2_y == -75)
	{
		coin3_x=(rand() % (700-130) )+ 130; 
		coin3_y=650;
	}
	if(coin3_y == -75)
	{
		coin2_x=(rand() % (700-130) )+ 130; 
		coin2_y=650;
	}if(coin4_y == -75)
	{
		coin_x=(rand() % (700-130) )+ 130; 
		coin_y=650;
	}


	if( taxi_y+90>=coin_y && taxi_y<=coin_y+70 && taxi_x+50>=coin_x && taxi_x<=coin_x+70 )
	{
		coin_x=(rand() % (700-130) )+ 130; 
		coin_y=650;
		score+= car_point;
	}
	if(taxi_y+90>=coin2_y && taxi_y<=coin2_y+70 && taxi_x+50>=coin2_x && taxi_x<=coin2_x+70)
	{
		coin2_x=(rand() % (700-130) )+ 130; 
		coin2_y=650;
		score+= car_point;
	}
	if(taxi_y+90>=coin3_y && taxi_y<=coin3_y+70 && taxi_x+50>=coin3_x && taxi_x<=coin3_x+70)
	{
		coin3_x=(rand() % (700-130) )+ 130; 
		coin3_y=650;
		score+= car_point;
	}
	if(taxi_y+90>=coin4_y && taxi_y<=coin4_y+70 && taxi_x+50>=coin4_x && taxi_x<=coin4_x+70)
	{
		coin4_x=(rand() % (700-130) )+ 130; 
		coin4_y=650;
		score+= car_point;
	}
	}


}

#endif 
