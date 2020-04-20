/**
 * @file fsm.h
 * @author Pluto Wang (wmpluto@gmail.com)
 * @brief Header file of tiny FSM framework
 * @version 0.1
 * @date 2020-04-20
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef _FSM_H
#define _FSM_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief fsm_state_table
 *
 */
typedef struct
{
    uint8_t event;
    uint8_t crt_state;
    void (*action_fun)();
    uint8_t nxt_state;
} fsm_state_table_t;

/**
 * @brief fsm_t
 *
 */
typedef struct
{
    uint8_t state;
    uint8_t transition_num;
    fsm_state_table_t* fsm_table;
} fsm_t;

void fsm_init(fsm_t* fsm, fsm_state_table_t* table, uint8_t init_state, uint8_t transition_num);
int8_t fsm_event_handler(fsm_t* fsm, uint8_t event);

#endif
