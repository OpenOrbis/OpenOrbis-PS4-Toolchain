#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "mira.h"


void sceSysUtilSendSystemNotificationWithText();
void _Exit();


static void
notify(const char *fmt, ...) {
  va_list args;
  char str[1024];
    
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  sceSysUtilSendSystemNotificationWithText(222, str);
}


static int
waitpid_exit(pid_t pid) {
  int status;
  
  do {
    waitpid(pid, &status, WUNTRACED);
  } while (!WIFEXITED(status) && !WIFSIGNALED(status));

  return WEXITSTATUS(status);
}


int
main(int argc, char **argv) {
  pid_t pid;
  int status;
  
  if(mira_jailbreak()) {
    notify("jailbreak failed");
  } else {
    notify("jailbreak succesful");
  }
  sleep(5);
  
  pid = fork();
  if (pid == 0) {
    notify("pid %d says hello", getpid());
    sleep(5);
    _Exit(123);
    
  } else if (pid < 0) {
    notify("fork: %s\n", strerror(errno));
    
  } else {
    notify("pid %d terminated (%d)", pid, waitpid_exit(pid));
  }
  
  while(1) {
    sleep(1);
  }
  
  return 0;
}

