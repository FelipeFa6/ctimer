/* See LICENSE file for copyright and license details.
 *
 * ctimer is a basic timer that is able to output through
 * stdout. The main purspose of this is to achieve extensibility.
 *
 * Usage:
 * $ ctimer -s 20 -M "'Hello World' 'Other Line'" | xargs herbe
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

#include "util.h"

int main(int argc, char **argv){
  static int delay  = 1; // In seconds
  static int hour     = 0;
  static int min      = 0;
  static int sec      = 0;
  static int notifyOn = 0; // False
  static int displayTime  = 0; // False

  char command[100] = "notify-send ";
  char *msg = "Default Message";
  
  // Argument options section
  int c;
  int index_opt = 0;
  const char short_opt[12] = "hH:m:s:M:nd";
  const struct option long_opt[] = 
	{
    {	"hours",        required_argument,  0,  'H' },
    {	"minutes",      required_argument,  0,  'm' },
    {	"seconds",      required_argument,  0,  's' },
    {	"message",      required_argument,  0,  'M' },

    /*Flags*/
    {	"help",         no_argument,        0,  'h' },
    {	"notify-send",	no_argument,				0,	'n' },
    {	"display",      no_argument,        0,  'd' },
    {	0,              0,                  0,   0  },
	};

	// arguments
  while((c = getopt_long(argc, argv, short_opt, long_opt, &index_opt)) !=EOF )
  {
    switch(c)
    {
      case '?':
      case ':':
      case 'h':
      default:
        fprintf (stderr, "Usage: %s [-h help] [-H hours] [-m minutes] [-s seconds] [-M 'message to be sent']\n", argv[0]);
        printf ( "\n");
        printf ( "  Flags:\n");
        printf ( "  [--notify-send    redirect 'notify-send']\n");
        printf ( "  [--display-time   displays the time in console]\n");
        exit (EXIT_FAILURE);

      case 'H': // Hour
        hour = atoi(optarg);
        break;
            
      case 'm': // Minute
        min = atoi(optarg);
        break;

      case 's': // Seconds
        sec = atoi(optarg);
        break;

      case 'M': // Message
        msg = optarg;
        break;

      case 'n': // send to notify-send
        notifyOn = 1; // send to notify-send
        break;

      case 'd': // display-time
        displayTime = 1; // Display timer in CLI
        break;
    }
  }

	// Pass the countdown function
  ctdwn(hour, min, sec, delay, displayTime);

	// Output the message
  if(notifyOn){
    strcat(command, msg);
    system(command);
  }

  printf("\n");
  printf("%s\n", msg);
  exit(EXIT_SUCCESS);
}
