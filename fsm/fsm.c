/**
 * @file fsm.c
 * @author Pluto Wang (wmpluto@gmail.com)
 * @brief Tiny FSM framework
 * @version 0.1
 * @date 2020-04-20
 *
 * @copyright Copyright (c) 2020
 *
 */
#include "fsm.h"

/**
 * @brief
 *
 * @param fsm
 * @param table
 * @param init_state
 * @param transition_num
 */
void fsm_init(fsm_t* fsm, fsm_state_table_t* table, uint8_t init_state, uint8_t transition_num)
{
    if (!fsm)
        return;

    fsm->fsm_table = table;
    fsm->state = init_state;
    fsm->transition_num = transition_num;
}

/**
 * @brief
 *
 * @param fsm
 * @param event
 */
int8_t fsm_event_handler(fsm_t* fsm, uint8_t event)
{
    fsm_state_table_t *table = fsm->fsm_table;
    void (*action)() = NULL;
    uint8_t crt_state;
    uint8_t i;

    crt_state = fsm->state;

    for (i = 0; i < fsm->transition_num; i++) {
        if (event == table[i].event && crt_state == table[i].crt_state) {
            action = table[i].action_fun;
            action();
            fsm->state = table[i].nxt_state;
            return 0;
        }
    }

    return -1;
}
