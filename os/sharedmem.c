#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
  int shmid;
  char *shmaddr;
  key_t key = 1234;

  // create a shared memory segment
  if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // attach to the shared memory segment
  if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // write a message to the shared memory segment
  sprintf(shmaddr, "Hello, world!");

  // detach from the shared memory segment
  if (shmdt(shmaddr) == -1) {
    perror("shmdt");
    exit(1);
  }

  // re-attach to the shared memory segment
  if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // read the message from the shared memory segment
  printf("Message read from shared memory: %s\n", shmaddr);

  // detach from the shared memory segment again
  if (shmdt(shmaddr) == -1) {
    perror("shmdt");
    exit(1);
  }

  // remove the shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}
/*This program creates a shared memory segment using shmget(), attaches to the segment using shmat(), writes a message to the segment using sprintf(), detaches from the segment using shmdt(), re-attaches to the segment using shmat(), reads the message from the segment using printf(), detaches from the segment again using shmdt(), and finally removes the shared memory segment using shmctl().

Note that the key value 1234 used to create the shared memory segment must be the same in both the sender and receiver processes in order for them to communicate through the shared memory segment. Additionally, the sender and receiver processes must be run separately (e.g. in different terminal windows) in order for the IPC to occur.*/
