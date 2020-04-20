#include "fsm.h"
#include "windows.h"
#include <stdio.h>

enum {
    ON,
    OFF
} s;

enum {
    START = 's',
    HALT = 'h',
    TRIGGER = 't'
} e;

void start_act()
{
    printf("Switch to ON!\n");
}

void halt_act()
{
    printf("Switch to OFF!\n");
}

void trigger_act()
{
    printf("Stay in ON\n");
}

int main()
{
    fsm_t sm;
    fsm_state_table_t t[] = {
        { START,   OFF, start_act,   ON },
        { HALT,    ON,  halt_act,    OFF },
        { TRIGGER, ON,  trigger_act, ON },
    };

    fsm_init(&sm, t, ON, 3);

    char c = '1';
    while (c = getchar()) {
        if (c == '\n')
            continue;
        if (!fsm_event_handler(&sm, c))
            printf("processed %c\n", c);
        Sleep(1);
    }

    return 0;
}
