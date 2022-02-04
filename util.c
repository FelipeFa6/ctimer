/* See LICENSE file for copyright and license details.*/

#include <unistd.h>
#include <stdio.h>
#include "util.h"

void ctdwn(int hour, int min, int sec, int delay, int displayTime){
    while(1){
    sec--;
    if(sec < 0){
      min--;
      sec = 59;
    }

    if(min < 0){
      hour--;
      min = 59;
    }
    
    if(hour < 0 || min < 0 || sec < 0){
      break;
    }

    if(displayTime){
    	printf("\r%02d:%02d:%02d ", hour, min, sec);
    	fflush(stdout);
    }
    sleep(delay);
  }
}
