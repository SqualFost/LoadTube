#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

int main() {
    bool done = false;
    char input[256] = "";
    size_t tailleInput = 0;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *pwindow = SDL_CreateWindow("Telecharger des musiques", 900, 600, 0);
    SDL_SetWindowPosition(pwindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_Renderer *prenderer = SDL_CreateRenderer(pwindow, NULL);

    if (pwindow == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Impossible de créer la fenêtre: %s\n", SDL_GetError());
        return 1;
    }

    if (prenderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Impossible de créer le rendrer: %s\n", SDL_GetError());
    }

    SDL_StartTextInput(pwindow);
    const SDL_FRect inputBox = {50,50, 300, 40};

    if (TTF_Init() == 0) {
        SDL_Log("Erreur TTF_Init");
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("/System/Library/Fonts/SFNS.ttf", 18);
    if (!font) {
        SDL_Log("Erreur ouverture font");
        return 1;
    }

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    done = true;
                    break;
                case SDL_EVENT_TEXT_INPUT:
                    if (tailleInput + SDL_strlen(event.text.text) < sizeof(input) - 1) {
                        SDL_strlcat(input, event.text.text, sizeof(input));
                        tailleInput = SDL_strlen(input);
                    }
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_BACKSPACE && tailleInput > 0 ) {
                        input[--tailleInput] = '\0';
                    }
                    break;
                default:
                    break;
            }
            SDL_SetRenderDrawColor(prenderer, 30, 30, 30, 255);
            SDL_RenderClear(prenderer);

            SDL_SetRenderDrawColor(prenderer, 255, 255, 255, 255);
            SDL_RenderFillRect(prenderer, &inputBox);

            SDL_SetRenderDrawColor(prenderer, 0, 0, 0, 255);
            SDL_RenderRect(prenderer, &inputBox);

            if (tailleInput > 0) {
                const SDL_Color couleurTexte = {0, 0, 0, 255};
                SDL_Surface *psurface = TTF_RenderText_Blended(font, input, tailleInput, couleurTexte);
                SDL_Texture *ptexture = SDL_CreateTextureFromSurface(prenderer, psurface);

                SDL_FRect dst = {inputBox.x + 5, inputBox.y + 5, psurface->w, psurface->h};
                SDL_RenderTexture(prenderer, ptexture, NULL, &dst);

                SDL_DestroySurface(psurface);
                SDL_DestroyTexture(ptexture);
            }

            SDL_RenderPresent(prenderer);
        }
    }

    TTF_Quit();
    SDL_StopTextInput(pwindow);
    SDL_DestroyRenderer(prenderer);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();

    return 0;
}