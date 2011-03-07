#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "flags.h"


using namespace std;




int main(int argc, char ** argv) {
  if (argc == 1) {
    printf("Usage: %s exit_code [extra args]\n", argv[0]);
    return 1;
  }

  FLAGS.define_bool("debug", 'd', false, "Display debugging info.");
  FLAGS.define_bool("help", 'h', false, "Display help for this binary.");
  FLAGS.define_bool("get-session", 's', false, "Get the current shell history session ID, inserting one if missing.");
  FLAGS.define_bool("version", 'v', false, "Display the version number and quit.");
  FLAGS.parse(argc, argv);

  if (FLAGS.get_bool("get-session")) {
    int session_id = 0;
    // TODO: set the current session ID
    // TODO: if no session_id exists, insert one.
    cout << session_id << endl;
    return 0;
  }
  // TODO: find the history file
  // TODO: if it doesn't exist, create it
  // TODO: if it can't be created, barf and exit
  // TODO: 
  return atoi(argv[1]);
}