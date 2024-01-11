#include "simulation.h"

int change_rotation(int rot, int state){
	if(state==10||state==20||state==30||state==40){
		if(rot==1){
			return 2;
		}
		else if(rot==2){
			return 3;
		}
		else if(rot==3){
			return 4;
		}
		else{
			return 1;
		}
	}
	else{
		if(rot==1){
			return 4;
		}
		else if(rot==4){
			return 3;
		}
		else if(rot==3){
			return 2;
		}
		else{
			return 1;
		}
	}
}

int change_color(int state){
	if(state==10||state==20||state==30||state==40){
		return 1;
	}
	else{
		return 0;
	}
}

void change_posision(int rot, int * x, int * y){
	if(rot==1){
		*y+=1;
	}
	else if(rot==2){
		*x+=1;
	}
	else if(rot==3){
		*y-=1;
	}
	else{
		*x-=1;
	}
}

int change_ant_placing(int state, int rot){
	if(state==0){
		if(rot==1){
			return 10;
		}
		else if(rot==2){
			return 20;
		}
		else if(rot==3){
			return 30;
		}
		else{
			return 40;
		}
	}
	else if(state==1){
		if(rot==1){
			return 11;
		}
		else if(rot==4){
			return 41;
		}
		else if(rot==3){
			return 31;
		}
		else{
			return 21;
		}
	}
	else{
		return 0;
	}
}
