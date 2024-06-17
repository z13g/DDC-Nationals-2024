#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void segfault_handler(int signal_number) {
  FILE *file = fopen("flag.txt", "r");
  char flag[28];
  fread(flag, sizeof(char), sizeof(char) * 28, file);
  printf("FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG %s\n", flag);
  exit(EXIT_FAILURE);
}

int main() {
  signal(SIGSEGV, segfault_handler);

  printf("mr konkurrent, vaer hilset.\n");
  printf("hvis du faar mig til at segfault...... saa falder der braende ned\n");
  printf("hvis altsaa braende = flag :)");
  fflush(stdout);
  char buf[223];
  char *big_buf = (char *)malloc(10000 * sizeof(char));
  char *sentinel = buf + 223;
  *sentinel = 'z';
  fgets(big_buf, 10000, stdin);

  if (strlen(big_buf) > 223) {
    printf("... nej - det er helt FORKERT! :(");
  }
  if (strlen(big_buf) <= 223) {
    printf("hvad er en sentinel overhovedet? det lyder sejt\n");
    for (int i = 0; i <= strlen(big_buf); i++) {
      buf[i] = big_buf[i];
    }
  }
  if (*sentinel != 'z')
    raise(SIGSEGV);
}
