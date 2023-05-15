#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void input();
void output(int height, int width, int scale[height][width]); 

int main() {

    input(); //pivotal function
    return 0;
    
}

void input() { 
    int height, width, clear; //clear - the variable for getting char to following stdin buffer purifying
    printf("введите размеры матрицы: ширина × высота\n");
    scanf("%d %d", &width, &height);
    while ((clear = getchar()) != '\n' && clear != EOF) {} //very important crap for stdin buffer purifying
    int scale[height][width];
    int engine = 0, vec_y = 0; //engine to count steps on x axis | vec_y to count steps on y axis
    int counter = 0, counter1 = 0; //counters are very important to output one line after another
    //variable for determining when to make a shift
	int step; 
	//tmp - variable for making shift every -n steps along the y axis | tmp1 - the same but for x axis 
    int tmp = -1, tmp1 = -1;
    for(int i = 0; i < height; i++) { //filing the matrix with nulls
        for(int j = 0; j < width; j++) {
        scale[i][j] = 0;
        }
    }
    while(1){
        char tail[20]; //mas for input phrase
        //forward - how many points will the programm output 
		//turn - the degree of inclination is line
		//lift - we use this to determine while the program just changes position or draws lines
		int forward, turn, lift; 
        printf("Введите фразу 'lift the tail' или 'lower the tail': ");
        fgets(tail, sizeof(tail), stdin);
        tail[strcspn(tail, "\n")] = '\0'; // deleting the newline character
        for (int i = 0; i < strlen(tail); i++) {
            tail[i] = tolower(tail[i]); // we reduce all characters to lowercase
        }
        if (strcmp(tail, "lift the tail") == 0) {
            lift = 0;
        } else if (strcmp(tail, "lower the tail") == 0) {
            lift = 1;
        } else {
            printf("Некорректная фраза!\n");
        }
        printf("forward:");
        scanf("%d", &forward);
        printf("\nright:");
        scanf("%d", &turn);
        while ((clear = getchar()) != '\n' && clear != EOF) {} //very important crap for stdin buffer purifying
        counter = engine;
        counter1 = vec_y;
        int start_x = 49, start_y = 19;
        int counter = engine, counter1 = vec_y;
        int i, j, tmp_counter = 0; //we use tmp_counter to comare forward and this variable
        printf("%d %d\n", tmp, tmp1);
        while(tmp_counter < forward){
        ////////////////////////////////////////////////////////////////////////////////////////////
        //                                          For | Quarter
        ////////////////////////////////////////////////////////////////////////////////////////////
            if ((forward >= 0) && (turn > 0 && turn <= 45) && (engine > (-1 * forward) + counter)){
                if(turn >= 1 && turn < 5){
                    step = 10;
                } else if (turn >= 5 && turn < 10){
                     step = 9;
                } else if (turn >= 10 && turn < 15){
                     step = 8;
                } else if (turn >= 15 && turn < 20){
                     step = 7;
                } else if (turn >= 20 && turn < 25){
                     step = 6;
                } else if (turn >= 25 && turn < 30){
                     step = 5;
                } else if (turn >= 30 && turn < 35){
                     step = 4;
                } else if (turn >= 35 && turn < 40){
                     step = 3;
                } else if (turn >= 40 && turn < 45){
                     step = 2;
                } else if (turn == 45){
                     step = 1;
                }
				//we use this if to make shift every -n step
                if(engine == tmp1 - step + 2){
                    vec_y--;
                    tmp1 = tmp1 - step;
                }
                tmp_counter++;
                engine--;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){ //the if else block for assigning a value of matrix cell
                    scale[i][j] = 1; //1 if user has choosen "lower the tail"
                } else {
                    scale[i][j] = scale[i][j]; //otherwise the programm wouldn't change the cell if user chose "lift the tail"
                }
            } else if ((forward >= 0) && (turn >= 46 && turn < 90) && (vec_y > (-1 * forward) + counter)) {
                if(turn >= 1 && turn < 5){
                    step = 10;
                } else if (turn >= 85 && turn < 90){
                     step = 9;
                } else if (turn >= 80 && turn < 85){
                     step = 8;
                } else if (turn >= 75 && turn < 80){
                     step = 7;
                } else if (turn >= 70 && turn < 75){
                     step = 6;
                } else if (turn >= 65 && turn < 70){
                     step = 5;
                } else if (turn >= 60 && turn < 65){
                     step = 4;
                } else if (turn >= 50 && turn < 55){
                     step = 3;
                } else if (turn >= 46 && turn < 50){
                     step = 2;
                }
                if(vec_y == -1 * (tmp + step)){
                    engine--;
                    tmp = tmp + step;
                }
                tmp_counter++;
                vec_y--;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
        ////////////////////////////////////////////////////////////////////////////////////////////
        //                                          For || Quarter
        ////////////////////////////////////////////////////////////////////////////////////////////
            } else if ((forward >= 0) && (turn > 90 && turn <= 135) && (vec_y > (-1 * forward) + counter1)){
                if(turn <= 95 && turn > 90){
                    step = 10;
                } else if (turn <= 100 && turn > 95){
                     step = 9;
                } else if (turn <= 105 && turn > 100){
                     step = 8;
                } else if (turn <= 110 && turn > 105){
                     step = 7;
                } else if (turn <= 115 && turn > 110){
                     step = 6;
                } else if (turn <= 120 && turn > 115){
                     step = 5;
                } else if (turn <= 125 && turn > 120){
                     step = 4;
                } else if (turn <= 130 && turn > 125){
                     step = 3;
                } else if (turn <= 134 && turn > 130){
                     step = 2;
                } else if (turn == 135){
                     step = 1;
                }
                if(vec_y == -1 * (tmp + step)){
                    engine++;
                    tmp = tmp + step;
                }
                tmp_counter++;
                vec_y--;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            } else if ((forward >= 0) && (turn >= 136 && turn < 180) && (engine < forward + counter)) {
                if(turn >= 175 && turn < 180){
                    step = 10;
                 } else if (turn >= 170 && turn < 175){
                     step = 9;
                } else if (turn >= 155 && turn < 170){
                     step = 8;
                } else if (turn >= 160 && turn < 165){
                     step = 7;
                } else if (turn >= 155 && turn < 160){
                     step = 6;
                } else if (turn >= 150 && turn < 155){
                     step = 5;
                } else if (turn >= 145 && turn < 150){
                     step = 4;
                } else if (turn >= 140 && turn < 145){
                     step = 3;
                } else if (turn >= 136 && turn < 140){
                     step = 2;
                } 
                if(engine == tmp1 + step + 1){
                    vec_y--;
                    tmp1 = tmp1 + step;
                }
                tmp_counter++;
                engine++;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
        ////////////////////////////////////////////////////////////////////////////////////////////
        //                                          For ||| Quarter
        ////////////////////////////////////////////////////////////////////////////////////////////
            } else if ((forward >= 0) && (turn < 270 && turn >= 225) && (vec_y < forward + counter1)){ 
                if(turn >= 265 && turn < 270){
                    step = 10;
                 } else if (turn >= 260 && turn < 265){
                     step = 9;
                } else if (turn >= 255 && turn < 260){
                     step = 8;
                } else if (turn >= 250 && turn < 255){
                     step = 7;
                } else if (turn >= 245 && turn < 250){
                     step = 6;
                } else if (turn >= 240 && turn < 245){
                     step = 5;
                } else if (turn >= 235 && turn < 240){
                     step = 4;
                } else if (turn >= 230 && turn < 235){
                     step = 3;
                } else if (turn >= 226 && turn < 230){
                     step = 2;
                } else if (turn == 225){
                     step = 1;
                }
                if(vec_y == tmp + step){
                    engine++;
                    tmp = tmp + step;
                }
                tmp_counter++;
                vec_y++;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            } else if ((forward >= 0) && (turn < 225 && turn >= 181) && (vec_y < forward + counter1)){
                if (turn <= 185 && turn > 180){
                    step = 10;
                } else if (turn <= 190 && turn > 185){
                     step = 9;
                 } else if (turn <= 195 && turn > 190){
                     step = 8;
                } else if (turn <= 200 && turn > 195){
                     step = 7;
                } else if (turn <= 205 && turn > 200){
                     step = 6;
                } else if (turn <= 210 && turn > 205){
                     step = 5;
                } else if (turn <= 215 && turn > 210){
                     step = 4;
                } else if (turn <= 220 && turn > 215){
                     step = 3;
                } else if (turn <= 224 && turn > 220){
                     step = 2;
                }
                if(engine == tmp1 + step){
                    vec_y++;
                    tmp1 = tmp1 + step;
                }
                tmp_counter++;
                engine++;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
        ////////////////////////////////////////////////////////////////////////////////////////////
        //                                          For |||| Quarter
        ////////////////////////////////////////////////////////////////////////////////////////////
            } else if ((forward >= 0) && (turn <= 315 && turn >= 271) && (vec_y < forward + counter1)){ 
                if(turn >= 271 && turn < 275){
                    step = 10;
                } else if (turn >= 275 && turn < 280){
                    step = 9;
                } else if (turn >= 280 && turn < 285){
                    step = 8;
                } else if (turn >= 285 && turn < 290){
                    step = 7;
                } else if (turn >= 290 && turn < 295){
                    step = 6;
                } else if (turn >= 295 && turn < 300){
                    step = 5;
                } else if (turn >= 300 && turn < 305){
                    step = 4;
                } else if (turn >= 305 && turn < 310){
                    step = 3;
                } else if (turn >= 310 && turn < 315){
                    step = 2;
                } else if (turn == 315){
                    step = 1;
                }
                if(vec_y == tmp + step){
                    engine--;
                    tmp = tmp + step;
                }
                tmp_counter++;
                vec_y++;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            } else if ((forward >= 0) && (turn > 315 && turn <=  359)){
                if(turn <= 359 && turn > 355){
                    step = 10;
                } else if (turn <= 355 && turn > 350){
                     step = 9;
                 } else if (turn <= 350 && turn > 345){
                     step = 8;
                } else if (turn <= 345 && turn > 340){
                     step = 7;
                } else if (turn <= 340 && turn > 335){
                     step = 6;
                } else if (turn <= 335 && turn > 330){
                     step = 5;
                } else if (turn <= 330 && turn > 325){
                     step = 4;
                } else if (turn <= 325 && turn > 320){
                     step = 3;
                } else if (turn <= 320 && turn > 315){
                     step = 2;
                }
                if(engine == tmp1 - step + 1){
                    vec_y++;
                    tmp1 = tmp1 - step;
                }
                tmp_counter++;
                engine--;
                i = start_y + vec_y;
                j = start_x + engine;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
        ////////////////////////////////////////////////////////////////////////////////////////////
        //                                          For straight lines
        ////////////////////////////////////////////////////////////////////////////////////////////
            } else if ((forward >= 0) && (turn == 180) && (engine < forward + counter)){
                tmp_counter++;
                engine++;
                tmp1++;
                j = start_x + engine;
                i = start_y + vec_y;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            } else if ((forward >= 0) && (turn == 360) && (engine > (-1 * forward) + counter)){
                tmp_counter++;
                engine--;
                tmp1--;
                j = start_x + engine;
                i = start_y + vec_y;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            } else if ((forward >= 0) && (turn == 270) && (vec_y < forward + counter1)){
                tmp_counter++;
                vec_y++;
                j = start_x + engine;
                i = start_y + vec_y;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            } else if ((forward >= 0) && (turn == 90) && (vec_y > (-1 * forward) + counter1)){
                tmp_counter++;
                vec_y--;
                j = start_x + engine;
                i = start_y + vec_y;
                if(lift == 1){
                    scale[i][j] = 1;
                } else {
                    scale[i][j] = scale[i][j];
                }
            }
        }
    output(height, width, scale);
    }
}

void output(int height, int width, int scale[height][width]){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (scale[i][j] == 0) {
                printf(".");
            }
            else {
                printf("*");
            } 
        }
        printf("\n");
    }
}
