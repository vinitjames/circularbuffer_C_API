#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

enum C_Buffer_Status {
					 ERR_BUF_EMPTY,
					 ERR_BUF_FULL,
					 ERR_HANDLE_NULL,
					 SUCC_RESET,
					 
					
					
}; 

typedef enum C_Buffer_Status C_Buffer_Status;

typedef struct CircularBuffer CircularBuffer;

typedef CircularBuffer* CircularBufferHandle;


CircularBufferHandle CircularBufInit(uint8_t* buffer, size_t size);

C_Buffer_Status CircularBufFree(CircularBufferHandle c_buf);

C_Buffer_Status CircularBufReset(CircularBufferHandle c_buf);

C_Buffer_Status CircularBufInsert(CircularBufferHandle c_buf, uint8_t* data);

C_Buffer_Status CircularBufInsert_V2(CircularBufferHandle c_buf, uint8_t* data);

C_Buffer_Status CircularBufGet(CircularBufferHandle c_buf, uint8_t* data);

bool CircularBufEmpty(CircularBufferHandle c_buf);

bool CircularBufFull(CircularBufferHandle c_buf);

size_t CircularBufCapacity(CircularBufferHandle c_buf);

size_t CircularBufSize(CircularBufferHandle c_buf);



#endif /* CIRCULAR_BUFFER_H */
