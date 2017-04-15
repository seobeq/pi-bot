// This is my robot control program written in Jan/Feb 2017 by seobeq.
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>
#include <ncurses.h>
void forward();
void backward();
void stop();
void turnleft();
void turnright();
int main(){
wiringPiSetup();
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(14,OUTPUT);
pinMode(30, OUTPUT);
softPwmCreate(22, 0, 100);
softPwmCreate(21, 0, 100);
int ch;
initscr();
cbreak();
keypad(stdscr, TRUE);
noecho();
start_color();
init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
init_color(COLOR_MAGENTA, 100, 0 , 0);
attron(COLOR_PAIR(1));
printw("Hello, I'm PiBot.\n");
printw("Use the arrow keys to move me around.\n");
printw("Press d to see me dance.\n");
printw("Use ctrl c to quit.\n");
attroff(COLOR_PAIR(1));
while(TRUE){
ch = getch();
if(ch == KEY_UP){
forward();
delay(500);
stop();
}
else if(ch == KEY_DOWN){
backward();
delay(500);
stop();
}
else  if(ch == KEY_LEFT){
turnleft();
delay(100);
stop();
}
else if(ch == KEY_RIGHT){
turnright();
delay(100);
stop();
}
else if (ch == 'd'){
turnleft();
delay(1000);
turnright();
delay(1000);
turnright();
delay(1000);
turnleft();
delay(1000);
forward();
delay(1000);
backward();
delay(1000);
backward();
delay(1000);
forward();
delay(1000);
stop();
}
refresh();
}
//getch();
endwin();
}
void forward(){
softPwmWrite(21,80);
softPwmWrite(22,80);
digitalWrite(12,LOW);//Left
digitalWrite(13,HIGH);//
digitalWrite(14,LOW);//Right
digitalWrite(30,HIGH);//
}
void backward(){
softPwmWrite(21,80);
softPwmWrite(22,80);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
digitalWrite(14,HIGH);
digitalWrite(30,LOW);
}
void stop(){
digitalWrite(12,LOW);
digitalWrite(13,LOW);
digitalWrite(14,LOW);
digitalWrite(30,LOW);
}
void turnright(){
softPwmWrite(21,80);
softPwmWrite(22,80);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
digitalWrite(14,LOW);
digitalWrite(30,HIGH);
}
void turnleft(){
softPwmWrite(21,80);
softPwmWrite(22,80);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
digitalWrite(14,HIGH);
digitalWrite(30,LOW);
}
