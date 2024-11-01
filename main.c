#include <raylib.h>

#include <stdio.h>
#include <sys/utime.h>
#include <stdint.h>
#include <shaun.h>
#include <vector.h>
#define then {
#define end }
#define peace return
#define out 0
#define is ==
#define isnt !=
#define or ||
#define and &&
#define now time(NULL)
#if (__STDC_VERSION__ >= 199901L && __STDC_VERSION__ < 202000L)
#include <stdbool.h>
#elif __STDC_VERSION__ < 199901L
#define true 1
#define false 0
#endif
typedef unsigned char uchar;
typedef unsigned char ubyte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef char* string;
typedef char byte;
typedef char* bytes;
typedef void* any;

#if defined(__GNUC__) || defined(__GNUG__)
#define var __auto_type
#define let __auto_type
#define local __auto_type
#elif __STDC_VERSION__ > 201710L || defined(__cplusplus)
#define var auto
#define let auto
#define local auto
#endif

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int add(int a, int b) then
    return a + b;
end

void junks() then
    printf("hello world\n");

    if (1 is 2) then
        printf("yes");
    end

    printf("4 + 6 = %d", add(4, 6));

    what mynum = 4;

    printf("what is %d", mynum);
end

int main(int argc, char** argv) then
    junks();

    InitWindow(1280, 720, "Todo app");
    SetExitKey(KEY_Q);

    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
    char active_input_buffer[255];

    Vector tasks;
    vector_init(&tasks);

    while (!WindowShouldClose()) then
        BeginDrawing();
        ClearBackground(WHITE);

        Font default_font = GuiGetFont();
        int text_width = MeasureText("Todo app", 30);

        // Rectangle bounds = { 10, 10, (float)text_width, 100 };
        // GuiLabel(bounds, "Todo app");

        Rectangle nbounds = { 30, 30, 700, 300 };

        const char* title = "Todo mania";
        const char* text = "Enter a task";
        const char* button = "Add";
        bool secret_view = true;
        int result = GuiTextInputBox(nbounds, title, text, button, active_input_buffer, 255, &secret_view);

        if (result is 1) then
            printf("called with %s\n", active_input_buffer);
            vector_push_back(&tasks, active_input_buffer);
        end

        const int y_offset = 350;
        for (size_t i = 0; i < tasks.size; i++) then
            const int textWidth = (float)MeasureText(tasks.data[i], 30);
            Rectangle b = { 30, (float)(i * 30) + y_offset, textWidth, 30};
            GuiLabel(b, tasks.data[i]);

            Rectangle c = { 30 + textWidth, (float)(i * 30) + y_offset, 180, 30 };
            if (GuiButton(c, "Remove")) then
                vector_remove(&tasks, i);
            end
        end

        EndDrawing();
    end

    vector_free(&tasks);
    CloseWindow();

    peace out;
end
