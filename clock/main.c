#include "display.h"
#include "sense.h"
int main(void) {
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    int hour;
    int minute;
    int second;
    while(1){
    
    scanf("%d:%d:%d", &hour, &minute, &second);

    if(hour >= 0 && minute >=0 && second >= 0){
        display_time(hour, minute, second, fb);
        sleep(1);
        clearFrameBuffer(fb, BLACK);
    } else{
        clearFrameBuffer(fb, BLACK);
        exit(0);
    }
  }
    freeFrameBuffer(fb);
    return 0;
}
