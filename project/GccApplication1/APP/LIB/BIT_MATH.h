/*
 * BIT_MATH.h
 * Created: 8/27/2021 6:37:35 PM
 *  Author: MOHAMED_HELMY
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

#endif /* BIT_MATH_H_ */