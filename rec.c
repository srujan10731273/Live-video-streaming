#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1000000  // Adjust the size as needed

int main() {
    key_t key = ftok("sender.c", 'R');
    int shmid = shmget(key, SHM_SIZE, 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);

    FILE *receivedFile = fopen("received.mp4", "wb");
    if (!receivedFile) {
        perror("Error creating received MP4 file");
        exit(EXIT_FAILURE);
    }

    // Write shared memory content to received MP4 file
    fwrite(shm_ptr, 1, SHM_SIZE, receivedFile);
    fclose(receivedFile);

    shmdt(shm_ptr);

    // Clean up shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

