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

    Texture2D scarfy{LoadTexture("/home/ashfaque/CLionProjects/C++/GameProgramming/DapperDasher/textures/scarfy.png")};

    Rectangle scarfy_rectangle;
    scarfy_rectangle.width=scarfy.width/6;
    scarfy_rectangle.height=scarfy.height;
    scarfy_rectangle.x=0;
    scarfy_rectangle.y=0;

    Vector2 scarfy_position;
    scarfy_position.x=WINDOW_WIDTH/2-scarfy_rectangle.width/2;
    scarfy_position.y=WINDOW_HEIGHT-scarfy_rectangle.height;

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

        //DrawRectangle(WINDOW_WIDTH/2,pos_y,rectangle_width,rectangle_height, BLUE);
        DrawTextureRec(scarfy,scarfy_rectangle,scarfy_position,WHITE);



        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();

    return 0;
}
