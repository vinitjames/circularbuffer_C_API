#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circular_buffer.h"
#define BUFFER_SIZE 10

int main(int argc, char *argv[])
{
	uint8_t * buffer  = malloc(BUFFER_SIZE * sizeof(char));
	printf("Testing Circular Buffer with size %d\n", BUFFER_SIZE);
	CircularBufferHandle c_buf = CircularBufInit(buffer, BUFFER_SIZE);
	printf("Created Circular Buffer");
	assert(CircularBufEmpty(c_buf));
	uint8_t a[] ={1,34,20,23,21};
	assert(CircularBufInsert(c_buf, a) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+1) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+2) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+3) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+4) == SUCC_BUF_INS);
	
	



    return 0;
}
