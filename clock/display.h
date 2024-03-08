#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "sense.h"
#define BLACK 0x0000

void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *fb);

void display_colons(pi_framebuffer_t *fb);

void display_hours(int hours, pi_framebuffer_t *fb);

void display_minutes(int minutes, pi_framebuffer_t *fb);

void display_seconds(int seconds, pi_framebuffer_t *fb);
