struct FlagOptions {
   bool godmode = false;
   bool debug = false;
};

/**
 * print the usage for this program when the user asks for it
 */
void print_usage();

/**
 * Parse the command line arguments
 */
FlagOptions parse_flags(int argc, char** argv);
