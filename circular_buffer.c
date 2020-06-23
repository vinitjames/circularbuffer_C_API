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
	return SUCC_BUF_RESET;
}

C_Buffer_Status CircularBufFree(CircularBufferHandle c_buf){
	if(c_buf == NULL)
		return ERR_HANDLE_NULL;
	free(c_buf);
	return SUCC_BUF_FREE;
}

bool CircularBufferFull(CircularBufferHandle c_buf){
	return c_buf->full;
}

bool CircularBufEmpty(CircularBufferHandle c_buf){
	return (!c_buf->full)&&(c_buf->tail==c_buf->head);
}

size_t CircularBufCapacity(CircularBufferHandle c_buf){
	return c_buf->max;
}

size_t CircularBufSize(CircularBufferHandle c_buf){
	if(c_buf->full)
		return c_buf->max;
	if(c_buf->head >= c_buf->tail)
		return c_buf->head-c_buf->tail;
	return c_buf->max + c_buf->head - c_buf->tail;
}

static void _advancepointer(CircularBufferHandle c_buf){
	if(c_buf->full)
		c_buf->tail = (c_buf->tail+1)%c_buf->max;
	c_buf->head = (c_buf->head+1)%c_buf->max;
	c_buf->full = (c_buf->head == c_buf->tail);
} 

static void _recedepointer(CircularBufferHandle c_buf){
	c_buf->full = false;
	c_buf->tail = (c_buf->tail+1)%c_buf->max;
	
} 

C_Buffer_Status CircularBufInsert(CircularBufferHandle c_buf, uint8_t* data){
	if(c_buf == NULL)
		return ERR_HANDLE_NULL;
	if (data == NULL)
		return ERR_DATA_NULL;
	c_buf->buffer[c_buf->head] = *data;
	_advancepointer(c_buf);
	return SUCC_BUF_INS;
}

C_Buffer_Status CircularBufInsert_V2(CircularBufferHandle c_buf, uint8_t* data){
	if(c_buf == NULL)
		return ERR_HANDLE_NULL;
	if (data == NULL)
		return ERR_DATA_NULL;
	if(c_buf->full)
		return ERR_BUF_FULL;
	c_buf->buffer[c_buf->head] = *data;
	_advancepointer(c_buf);
	return SUCC_BUF_INS;
}

C_Buffer_Status CircularBufGet(CircularBufferHandle c_buf, uint8_t* data){
	if(c_buf == NULL)
		return ERR_HANDLE_NULL;
	if (data == NULL)
		return ERR_DATA_NULL;
	if(CircularBufEmpty(c_buf))
		return ERR_BUF_EMPTY;
	*data = c_buf->buffer[c_buf->tail];
	_recedepointer(c_buf);
	return SUCC_BUF_INS;
}


