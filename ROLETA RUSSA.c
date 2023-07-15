#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>


void openBrowserTab(const char* url);

int main (void) {
    setlocale(LC_ALL, "pt_BR.utf8");

    int roletaRussa;
    const char* url = "https://betteranime.net/anime/legendado/umineko-no-naku-koro-ni/episodio-01";

    srand(time(NULL));
    int randomNumber = rand() % 7 + 1;

    do {
        printf ("Digite um numero de 1 a 7:  ");
        scanf ("%d", &roletaRussa);
    } while (roletaRussa < 1 || roletaRussa >= 7);

    if (roletaRussa == randomNumber) {
        openBrowserTab(url);

        while (1) {
            printf ("VAI TER QUE ASSISTIR UMINEKO!!!\n");
        }
    }

    else {
        printf ("Desta vez voce se safou...\n");
        system("PAUSE");
        return 0;
    }
}

void openBrowserTab(const char* url) {
    #ifdef _WIN32
        // Windows
        char command[256];
        sprintf(command, "start %s", url);
        system(command);
    #elif __APPLE__
        // macOS
        char command[256];
        sprintf(command, "open %s", url);
        system(command);
    #elif __linux__
        // Linux
        char command[256];
        sprintf(command, "xdg-open %s", url);
        system(command);
    #else
        // Unsupported operating system
        printf("Dá pra abrir não parceiro :(\n");
    #endif
}
