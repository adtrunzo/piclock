#include "display.h"
#define WHITE 0xFFFF
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0


void display_colons(pi_framebuffer_t *fb){
    sense_fb_bitmap_t *bm=fb->bitmap;  

    //first colon
    bm->pixel[2][1]=WHITE;
    bm->pixel[2][2]=WHITE;
    bm->pixel[2][4]=WHITE;
    bm->pixel[2][5]=WHITE;
    bm->pixel[3][1]=WHITE;
    bm->pixel[3][2]=WHITE;
    bm->pixel[3][4]=WHITE;
    bm->pixel[3][5]=WHITE;
    
    //second colon
    bm->pixel[5][1]=WHITE;
    bm->pixel[5][2]=WHITE;
    bm->pixel[5][4]=WHITE;
    bm->pixel[5][5]=WHITE;
    bm->pixel[6][1]=WHITE;
    bm->pixel[6][2]=WHITE;
    bm->pixel[6][4]=WHITE;
    bm->pixel[6][5]=WHITE;
    
   
}

void display_hours(int hours, pi_framebuffer_t *fb){
    sense_fb_bitmap_t *bm=fb->bitmap;
    int x=2;
    int row=0;
    while(x>0){
        int binary=hours%2;
        hours = hours/2;
        x=round(hours);
        if(binary == 1){
            bm->pixel[1][row]=BLUE;
        }
        row = row + 1;

    }
    
}

void display_minutes(int minutes, pi_framebuffer_t *fb){
    sense_fb_bitmap_t *bm=fb->bitmap;
    int y=2;
    int row_min=0;
    while(y>0){
        int binary_minutes=minutes%2;
        minutes = minutes/2;
        y=round(minutes);
        if(binary_minutes == 1){
            bm->pixel[4][row_min]=GREEN;
        }
        row_min = row_min + 1;

    }
   
}

void display_seconds(int seconds, pi_framebuffer_t *fb){
    sense_fb_bitmap_t *bm=fb->bitmap;
    int z=2;
    int row_sec=0;
    while(z>0){
        int binary_seconds=seconds%2;
        seconds = seconds/2;
        z=round(seconds);
        if(binary_seconds == 1){
            bm->pixel[7][row_sec]=RED;
        }
        row_sec = row_sec + 1;
       
    }
   
}
void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *fb){
    sense_fb_bitmap_t *bm=fb->bitmap;
    display_colons(fb);
    display_hours(hours,fb);
    display_minutes(minutes, fb);
    display_seconds(seconds, fb);
    
}
