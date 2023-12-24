#ifndef FRAME_H
#define FRAME_H

#include <stdlib.h>
#include "list.h"

/// @brief 
/// @param frames 
/// @return 
int alloc_freme(List *frames);

/// @brief 
/// @param frames 
/// @param frame_number 
/// @return 
int free_frame(List *frames, int frame_number);

#endif