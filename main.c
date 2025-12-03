#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

int loadHighScore() {
    FILE *file = fopen("highscore.txt", "r");
    if (!file) return 0;

    int hs = 0;
    fscanf(file, "%d", &hs);
    fclose(file);
    return hs;
}

void saveHighScore(int score) {
    FILE *file = fopen("highscore.txt", "w");
    if (!file) return;

    fprintf(file, "%d", score);
    fclose(file);
}

int main() {
    srand(time(0));

    // Play background music (looping)
    PlaySound("background.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    int x = 1;
    int step = 0;
    int obstaclePos = rand() % 3;
    int frameCounter = 0;
    int score = 0;
    int highScore = loadHighScore();

    while (1) {

        // INPUT
        for (int i = 0; i < 3; i++) {
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (x > 0) {
                    x--;
                    Beep(600, 40);  // movement sound
                    Sleep(50);
                    while (GetAsyncKeyState(VK_LEFT) & 0x8000) Sleep(10);
                }
            }

            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (x < 2) {
                    x++;
                    Beep(600, 40);  // movement sound
                    Sleep(50);
                    while (GetAsyncKeyState(VK_RIGHT) & 0x8000) Sleep(10);
                }
            }
            Sleep(10);
        }

        // CLEAR SCREEN
        system("cls");

        printf("Use LEFT/RIGHT to move | Score: %d | High Score: %d\n", score, highScore);

        for (int i = 0; i < 9; i++) {
            if (i == step) {
                if (obstaclePos == 0) printf("| X        |\n");
                else if (obstaclePos == 1) printf("|     X    |\n");
                else printf("|        X |\n");
            } else {
                printf("|          |\n");
            }
        }

        // PLAYER
        if (x == 0) printf("| O        |\n");
        else if (x == 1) printf("|     O    |\n");
        else printf("|        O |\n");

        // COLLISION
        if (step == 8 && x == obstaclePos) {
            Beep(200, 300);   // collision sound
            Beep(150, 200);

            printf("\nGAME OVER!!! Final Score: %d\n", score);

            // HIGH SCORE UPDATE
            if (score > highScore) {
                printf("NEW HIGH SCORE!\n");
                saveHighScore(score);
            }

            Sleep(2500);
            break;
        }

        Sleep(60);
        frameCounter++;

        if (frameCounter >= 2) {
            step++;
            frameCounter = 0;
        }

        // Reach bottom
        if (step > 8) {
            step = 0;
            obstaclePos = rand() % 3;
            score++;

            Beep(900, 100);  // score-up sound
        }
    }

    // Stop background audio
    PlaySound(NULL, 0, 0);

    return 0;
}            step = 0;
            obstaclePos = rand() % 3; // new lane
        }
    }

    return 0;
}
