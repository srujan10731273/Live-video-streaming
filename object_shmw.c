#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

void fun1() {
int shmid = shmget((key_t)11111, SHM_SIZE,
                     IPC_CREAT | 0666); // Create a shared memory segment

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  char *shm_ptr = (char *)shmat(shmid, NULL, 0); // Attach the shared memory segment

  if (shm_ptr == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  printf("Enter a binary number: ");
  char binaryInput[SHM_SIZE];
  fgets(binaryInput, SHM_SIZE, stdin);
  // binaryInput[strcspn(binaryInput, "\n")] = '\0'; // Remove newline character
  // if present

  strcpy(shm_ptr, binaryInput); // Copy binary input to shared memory

  printf("Binary number stored in shared memory: %s\n", shm_ptr);
}

void fun2() {

  int shmid = shmget((key_t)12333, SHM_SIZE,
                     IPC_CREAT | 0666); // Create a shared memory segment

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  char *shm_ptr = (char *)shmat(shmid, NULL, 0); // Attach the shared memory segment

  if (shm_ptr == (char *)-1) {
    perror("shmat");
    exit(1);
  }
  printf("Enter a binary number: ");
  char binaryInput[SHM_SIZE];
  fgets(binaryInput, SHM_SIZE, stdin);
  // binaryInput[strcspn(binaryInput, "\n")] = '\0'; // Remove newline character
  // if present

  strcpy(shm_ptr, binaryInput); // Copy binary input to shared memory

  printf("Binary number stored in shared memory: %s\n", shm_ptr);
}

void fun3() {

  int shmid = shmget((key_t)12331, SHM_SIZE,
                     IPC_CREAT | 0666); // Create a shared memory segment

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  char *shm_ptr = (char *)shmat(shmid, NULL, 0); // Attach the shared memory segment

  if (shm_ptr == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  printf("Enter a binary number: ");
  char binaryInput[SHM_SIZE];
  fgets(binaryInput, SHM_SIZE, stdin);
  // binaryInput[strcspn(binaryInput, "\n")] = '\0'; // Remove newline character
  // if present

  strcpy(shm_ptr, binaryInput); // Copy binary input to shared memory

  printf("Binary number stored in shared memory: %s\n", shm_ptr);
}

int main() {

  

  fun1();
  fun2();
  fun3();

  return 0;
}
