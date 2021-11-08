/*
 * dbg.h
 *
 *  Created on: Nov 7, 2021
 *      Author: domin
 */

#ifndef INC_DBG_H_
#define INC_DBG_H_

#ifdef DEBUG
#define ensInit() if(!_initialized) { volatile int x = 0; volatile int z = 1 / x; UNUSED(z); }
#else
#define ensInit() ;
#endif


#endif /* INC_DBG_H_ */
