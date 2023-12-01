#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1000000 // Adjust the size as needed

int main() {
    key_t key = ftok("sender.c", 'R');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);

    FILE *mp4File = fopen("output.mp4", "rb");
    if (!mp4File) {
        perror("Error opening MP4 file");
        exit(EXIT_FAILURE);
    }

    // Read MP4 file content into shared memory
    fread(shm_ptr, 1, SHM_SIZE, mp4File);
    fclose(mp4File);

    shmdt(shm_ptr);

    return 0;
}

