#include "raylib.h"

int main() {

    const int WINDOW_WIDTH{512};
    const int WINDOW_HEIGHT{380};
    const char *WINDOW_TITLE{"Dapper Dasher"};
    const int TARGET_FPS{60};

    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT,WINDOW_TITLE);

    int velocity{0}; // pixels per sec
    const int gravity{1'000}; //pixels per sec per sec

    bool is_in_air{false};
    const int jump_velocity{-600}; // pixels per sec

    // Nebula Variables

    Texture2D nebula{LoadTexture("/home/ashfaque/CLionProjects/C++/GameProgramming/DapperDasher/textures/12_nebula_spritesheet.png")};

    Rectangle nebula_rectangle;
    nebula_rectangle.width=;
    nebula_rectangle.height=;
    nebula_rectangle.x=;
    nebula_rectangle.y=;



    // Scarfy Variables
    Texture2D scarfy{LoadTexture("/home/ashfaque/CLionProjects/C++/GameProgramming/DapperDasher/textures/scarfy.png")};

    Rectangle scarfy_rectangle;
    scarfy_rectangle.width=scarfy.width/6;
    scarfy_rectangle.height=scarfy.height;
    scarfy_rectangle.x=0;
    scarfy_rectangle.y=0;

    Vector2 scarfy_position;
    scarfy_position.x=WINDOW_WIDTH/2-scarfy_rectangle.width/2;
    scarfy_position.y=WINDOW_HEIGHT-scarfy_rectangle.height;

    int frame{}; // animation frame

    const int number_of_scarfy_sprite_images{6};
    const float update_time{1.0/(number_of_scarfy_sprite_images*2)};
    float running_time{};

    SetTargetFPS(TARGET_FPS); // Doesn't guarantee this value, depends on CPU
    // Delta time -> time since last frame
    // FPS indirectly proportional to Delta time

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(WHITE);

        const float delta_time{GetFrameTime()};

        // ground check
        if(scarfy_position.y >= WINDOW_HEIGHT-scarfy_rectangle.height){
            velocity=0;
            is_in_air= false;
        } else{
            velocity+=gravity*delta_time;
            is_in_air=true;
        }

        if(IsKeyPressed(KEY_SPACE) and !is_in_air){
            velocity+=jump_velocity;
        }

        scarfy_position.y+=velocity*delta_time;

        //update running time

        running_time+=delta_time;

        if(running_time>=update_time) {
            running_time=0;
            //update animation frame
            scarfy_rectangle.x=frame*scarfy_rectangle.width;
            frame++;

            if(frame> number_of_scarfy_sprite_images-1) frame=0;
        }

        DrawTextureRec(scarfy,scarfy_rectangle,scarfy_position,WHITE);



        EndDrawing();
    }

    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();

    return 0;
}
