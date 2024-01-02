

#ifndef LED_MODULE_H_
#define LED_MODULE_H_

#define	LED_ON	1
#define LED_OFF	0
typedef enum {S0, S1, S2, S3, S4, S5} state_t;

void init_State(void);
void state_Machine_Update(void);

void LED_Ctrl_Init(void);
void LED_Ctrl(int state);

#endif /* LED_MODULE_H_ */
