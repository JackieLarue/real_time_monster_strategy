#include "main.h"

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)

#define WINDOW_TITLE "Pocket Move Prototype"

int main(int argc, char* argv[]) {
    int flags = FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE;
    SetConfigFlags(flags);
    InitAudioDevice();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    if (SearchAndSetResourceDir("assets") == false) {
        printf("Can't find resource directory.");
    }

    ecs_world_t* world = ecs_init_w_args(argc, argv);
    ecs_atfini(world, cleanup_flecs, NULL);

    import_modules(world);

    return ecs_app_run(world, &(ecs_app_desc_t){
        .enable_rest = true,
        .enable_stats = true,
    });
}
