#include <raylib.h>

#include <stdio.h>
#include <shaun.h>
#include <vector.h>
#include <useless.h>

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

    printf("4 + 6 = %d\n", add(4, 6));

    what mynum = 4;

    printf("what is %d\n", mynum);

    printf("fasti is %d\n", fasti);

    union test test_union = {"Hello"};
    union test test_union2 = {56};

    printf("test_union has value %s\n", test_union.field1);
    printf("test_union2 has value %d\n", test_union2.field2);

    auto string hello = "world";
    printf("hello %s\n", hello);

    register int age = 21;
    printf("my age is %d\n", age);

    static int count = 3;
    printf("The count is %d\n", count);

    char name[50];
    fgets(name, sizeof(name), stdin);

    printf("You entered: %s\n", name);
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
