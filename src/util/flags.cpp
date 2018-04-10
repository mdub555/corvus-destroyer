#include "util/flags.h"
#include <getopt.h>
#include <cstdlib>

void print_usage() {
}

FlagOptions parse_flags(int argc, char** argv) {
   FlagOptions flags;

   // Command-line flags accepted by this program.
   static struct option flag_options[] = {
      {"godmode", no_argument, 0, 'g'},
      {"debug",   no_argument, 0, 'd'},
      {"help",    no_argument, 0, 'h'},
      {0,         0,           0,  0 }
   };

   int option_index;
   char flag_char;

   // Parse the flags entered by the user
   while (true) {
      flag_char = getopt_long(argc, argv, "-gdh", flag_options, &option_index);

      // Detect the end of the options
      if (flag_char == -1) break;

      switch (flag_char) {
      case 'g':
         flags.godmode = true;
         break;

      case 'd':
         flags.debug = true;
         break;

      case 'h':
         print_usage();
         exit(EXIT_SUCCESS);
         break;

      default:
         break;
      }
   }

   return flags;
}
