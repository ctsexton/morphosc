#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <network.h>
#include <MorphOSCConfig.h>
#include <tinyosc.h>
#include <geometry.h>

static const char* CONTACT_STATE_STRING[] = { "CONTACT_INVALID","CONTACT_START", "CONTACT_MOVE", "CONTACT_END" };
static bool enter_pressed = false;

void * waitForEnter() {
    getchar();
    enter_pressed = true;
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Version %d.%d\n", MorphOSC_VERSION_MAJOR, MorphOSC_VERSION_MINOR);
    printf("Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  char * address = argv[1];
  int port = atoi(argv[2]);
  int sockfd = setup_network(address, port);

  char oscbuffer[1024];
  int len;

  len = tosc_writeMessage(
      oscbuffer, sizeof(oscbuffer),
      "/num_contacts",
      "i",
      9);
  send(sockfd, oscbuffer, len, 0);

  return 0;
}
