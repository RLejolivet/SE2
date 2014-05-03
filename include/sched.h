#ifndef SCHED_H
#define SCHED_H

#define TASK_INTERRUPTIBLE -1
#define TASK_RUNNING 0
#define TASK_DEAD 1 

struct task_struct 
{
	/*
	 * http://en.wikipedia.org/wiki/Volatile_variable#In_C_and_C.2B.2B
	 */
	volatile long etat ;

	/*
	 * pile user et pile système ?
	 */

	/*
	 * Généalogie
	 */
	struct task_struct* parent ;
	struct list enfants ;

} ;
#endif
