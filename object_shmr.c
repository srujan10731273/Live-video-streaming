#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<semaphore.h>

#define SHM_SIZE 1024


void det1() {
int shmid = shmget((key_t)11111, SHM_SIZE,IPC_CREAT | 0666); // Create a shared memory segment

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  char *shm_ptr = (char *)shmat(shmid, NULL, 0); // Attach the shared memory segment

  if (shm_ptr == (char *)-1) {
    perror("shmat");
    exit(1);
  }
  int c = 0;
  printf("\nBinary number recevied in shared memory: %s\n", shm_ptr);
  for (int i = 0; i < 1024; i++) {
    if (shm_ptr[i] == '1') {
      c++;
    }
    if (c >= 1) {
      printf("object detected\n");
      break;
    } else {
      printf("object not detected\n");
      break;
    }
  }
  
}

void det2() {
  int shmid = shmget((key_t)12333, SHM_SIZE,IPC_CREAT | 0666); // Create a shared memory segment

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  char *shm_ptr = (char *)shmat(shmid, NULL, 0); // Attach the shared memory segment

  if (shm_ptr == (char *)-1) {
    perror("shmat");
    exit(1);
  }
  int c = 0;
  printf("\nBinary number recevied in shared memory: %s\n", shm_ptr);
  for (int i = 0; i < 1024; i++) {
    if (shm_ptr[i] == '1') {
      c++;
    }
    if (c >= 1) {
      printf("object detected\n");
      break;
    } else {
      printf("object not detected\n");
      break;
    }
  }
  
}

void det3() {
int shmid = shmget((key_t)12331, SHM_SIZE,IPC_CREAT | 0666); // Create a shared memory segment

  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  char *shm_ptr = (char *)shmat(shmid, NULL, 0); // Attach the shared memory segment

  if (shm_ptr == (char *)-1) {
    perror("shmat");
    exit(1);
  }
  
  int c = 0;
  printf("\nBinary number recevied in shared memory: %s\n", shm_ptr);
  for (int i = 0; i < 1024; i++) {
    if (shm_ptr[i] == '1') {
      c++;
    }
    if (c >= 1) {
      printf("object detected\n");
      break;
    } else {
      printf("object not detected\n");
      break;
    }
  }
  
}

int main() {
  
  

  det1();
  det2();
  det3();
  return 0;
}
