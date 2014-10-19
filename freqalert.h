#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#include <math.h>
#include <malloc.h>
#include <portaudio.h>
#include <time.h>
#include <fftw3.h>

#define MAX_N_ALERTS 99
#define FF_SAMPLE 4096


typedef struct {

  int freq_duration;
  int alert_volume_level;
  int triggered_count;
  int flood_seconds;
  int flood_count;

  time_t triggered_time;

  double freq_low;
  double freq_high;

  char *alert_event_cmd;        /*Command to execute on Alert*/

} alert_t ;

typedef struct {
  int sample_rate;
  int channels;
  int volume_level;          /* threshold for sound-detection*/
  int volume_triggers;          /* how many times the signal should be above the trigger level*/

  int device_number;
  int show_help;
  int show_info;
  int verbosity;
  int        n_alerts;
  int        run_in_background;     /* wether to run in the background or not*/
  fftw_plan  ff_plan;
  fftw_complex *ff_in;
  fftw_complex *ff_out;
  int   bin_max;
  int   bin_min;
  float bin_size;
  int   buf_items;
  int   frames_per_buffer;
  
  char *configfile;             /* configurationfile*/

  alert_t   alert_info[MAX_N_ALERTS];

}  config_parms_t;


