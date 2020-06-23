#include "circular_buffer.h"
#include <stdlib.h>
struct CircularBuffer {
	uint8_t* buffer;
	size_t head;
	size_t tail;
	size_t max;
	bool full;
};

CircularBufferHandle CircularBufInit(uint8_t* buffer, size_t size){
	if ((buffer == NULL)||(size == 0)){
		return NULL;
	}
	
	CircularBufferHandle c_buf = (CircularBuffer*) malloc(sizeof(CircularBuffer));

	if (c_buf == NULL){
		return NULL;
	}

	c_buf->buffer = buffer;
	CircularBufReset(c_buf);
	c_buf->full = false;

	return c_buf;
};

C_Buffer_Status CircularBufReset(CircularBufferHandle c_buf){
	if(c_buf == NULL)
		return ERR_HANDLE_NULL;
	c_buf->head = 0;
	c_buf->tail = 0;
	c_buf->full = false;
	return SUCC_RESET;
}
