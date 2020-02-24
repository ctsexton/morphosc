#include <stdio.h>
#include <MorphOSCConfig.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Version %d.%d\n", MorphOSC_VERSION_MAJOR, MorphOSC_VERSION_MINOR);
    printf("Usage: %s --address 127.0.0.1 --port 5050\n", argv[0]);
  }
  return 0;
}
