#include <raylib.h>
#include <stdio.h>
#include <sys/utime.h>
#include <stdint.h>
#include <shaun.h>
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

    while (!WindowShouldClose()) then
        BeginDrawing();
        ClearBackground(SKYBLUE);
        EndDrawing();
    end

    CloseWindow();

    peace out;
end
