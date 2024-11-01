/*
About this program:
- This program counts words.
- The specific words that will be counted are passed in as command-line
  arguments.
- The program reads words (one word per line) from standard input until EOF or
  an input line starting with a dot '.'
- The program prints out a summary of the number of times each word has
  appeared.
- Various command-line options alter the behavior of the program.

E.g., count the number of times 'cat', 'nap' or 'dog' appears.
> ./main cat nap dog
Given input:
 cat
 .
Expected output:
 Looking for 3 words
 Result:
 cat:1
 nap:0
 dog:0
*/

// Wilhemn Subala 20484131
// Partner: Sebastian Flores 20535108

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smp0_tests.h"

/* B2 */
#define LENGTH(s) (sizeof(s) / sizeof(*s))

/* Structures */
/* These are like classes, the name of this structure is WordCountEntry 
it can be instantiated like this
WordCountEntry nameOfStructureInstance;
*/

//FILE *fout = NULL;

typedef struct {
  char *word;
  int counter;
} WordCountEntry;

/* Complete C4 and in this function
      strtok() can be used to split a line into individual tokens.
       For the separator characters we use whitespace (space and
       tab), as well as the newline character '\n'.  We could also
       trim the buffer to get rid of the newline, instead. 
       strtok returns NULL when no more tokens are available. 
       Google strtok line to learn more about how to use it */

int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0; 
  char buffer[30];
  char *delimit = "  \n"; //checks for space and /n to separate each word
  char *token;

  while (fgets(buffer, 30, stdin)) {

    token = strtok(buffer, delimit);
    while(token != NULL){
      if (*token == '.'){
        break;  // checks a "." as the first entry of the line
      }
      
      /* Compare against each entry. */
      int i = 0;
      while (i < entry_count) {
        /* B1: Google the meaning of the returned values of strcmp */
        if (!strcmp(entries[i].word, token))
          entries[i].counter++;
        i++;
      }
      line_count++;
      token = strtok(NULL, delimit);
    }

    if(token == NULL){
      continue; // separates each entry if more than 1 is used in the same line
    }else if(*token == '.'){
      break; // checks within the same line "."
    }

  }
  // Returns the number of lines processed.
  return line_count;
}

/* Complete B5: introduce a temporary variable i and use it to access every index in entries */
void print_result(WordCountEntry entries[], int entry_count)
{
    /* C1: send output to the right stream, use fprintf */
    fprintf(stdout, "Result:\n");

    /* fix this*/
    for(int i = 0; i < entry_count; i++){
      fprintf(stdout, "%s:%d\n", entries[i].word, entries[i].counter);

    }

}


void printHelp(const char *name)
{
    /* C1: send output to the right stream, use fprintf */
    /* C2: add instructions for the extra option -f */
    fprintf(stderr, "usage: %s [-h] <word1> ... <wordN>\n", name);
    fprintf(stderr, "usage: %s [-f] switch output file -fFILENAME\n", name);
}


int main(int argc, char **argv)
{
  const char *prog_name = *argv;

  /* C3: make entries a pointer instead of an array */
  //WordCountEntry entries[5];
  WordCountEntry *entries; // dynamic array instead of a static array with only 5 elements

  int entryCount = 0;

  /* C1: create a variable to store the output stream to use, stdout by default 
        Hint: use the FILE data type and understand the stdout and stderr output streams*/
  // FILE *output = ?? // Complete this stream variable definition (Note: this will not be a file)

  FILE *fout = NULL;
  
  /* Entry point for the testrunner program */
  if (argc > 1 && !strcmp(argv[1], "-test")) {
    run_smp0_tests(argc - 1, argv + 1);
    return EXIT_SUCCESS;
  }

  /* C3: allocate (potentially) a little more memory than strictly
       necessary, thus avoiding extensive modifications to the code below. Hint: use malloc */
  entries = (WordCountEntry*)malloc(argc*sizeof(WordCountEntry));

 /* B4: ignore the program name in argv */

  //int len;
  //char *FILENAME = NULL; 
  argv++;
  while (*(argv) != NULL) {
   
    if (**(argv) == '-') {

      switch ((*(argv))[1]) {
        /* C2: -fFILENAME switch: open FILENAME and set it as the output
             stream */
        
        case 'f':

          //len = strlen(*argv) - 2; //len - 2 (-f)
          //FILENAME = (char*)malloc(len*sizeof(char)); 
          //strncpy(FILENAME, *argv + 2, len);

          fout = freopen(*argv + 2, "w", stdout); // opens file for writting using the stdout output stream

          if(fout == NULL){
            fprintf(stderr, "Error opening file"); // if you cant open the file will exit
            fclose(fout);
            return EXIT_FAILURE;
          }
          argv++;
          //free(FILENAME);
          continue;

        /* B3: fix the logical flow error in the switch*/
        case 'h':
          printHelp(prog_name);
          
        return EXIT_FAILURE;

        default:
          /* C1: send output to the right stream, use fprintf */
          fprintf(stderr, "%s: Invalid option %s. Use -h for help.\n",
                 prog_name, *(argv));
      }
    } else {
      /* C3: the LENGTH macro will not work anymore, since entries will be a pointer, not an array */
      if (entryCount < argc) {
        entries[entryCount].word = *(argv);
        entries[entryCount++].counter = 0;
      }
    }
    argv++;
  }
  if (entryCount == 0) {

    /* C1: send output to the right stream, use fprintf */
    fprintf(stderr, "%s: Please supply at least one word. Use -h for help.\n",
           prog_name);
    return EXIT_FAILURE;
  }

  /* C1: send output to the right stream */
  if (entryCount == 1) {
    fprintf(stdout, "Looking for a single word\n");
  } else {
    fprintf(stdout, "Looking for %d words\n", entryCount);
  }

  /* You may modify the parameter list of any of these functions */
  process_stream(entries, entryCount);
  print_result(entries, entryCount);

  // MANDATORY! FREE MEMORY, CLOSE FILES, STREAMS, etc.

  if(fout != NULL){ // closed output file
    fclose(fout);
  }
  free(entries); // frees memory from entries
  fclose(stderr); // closes output stream stdout/stderr
  fclose(stdout);

  return EXIT_SUCCESS;
}
