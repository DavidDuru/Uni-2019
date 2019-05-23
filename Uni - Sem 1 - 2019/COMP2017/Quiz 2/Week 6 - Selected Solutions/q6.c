#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

volatile int cont = 1;

void sigint_handle(int signum) {
  cont = 0;
}

void sigusr_handle(int signum) {} //Noop but allows you to trigger pause


int main() {

  signal(SIGINT, sigint_handle);
  signal(SIGUSR1, sigusr_handle);


  while(cont) {
    pause();
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t); //statically allocated memory


    printf("%s", asctime(tm_info));
  }
  return 0;
}
