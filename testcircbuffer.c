#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circular_buffer.h"
#define BUFFER_LENGTH 5
#define DATA_TYPE int

int main(int argc, char *argv[])
{
	DATA_TYPE* buffer  = (int*)malloc(BUFFER_LENGTH * sizeof(DATA_TYPE));
	printf("Testing Circular Buffer with length%d\n", BUFFER_LENGTH);
	CircularBufferHandle c_buf = CircularBufInit(buffer, BUFFER_LENGTH*sizeof(DATA_TYPE), sizeof(DATA_TYPE));
	printf("Created Circular Buffer");
	assert(CircularBufEmpty(c_buf));
	DATA_TYPE a[] ={1,34,20,23,21,22};
	assert(CircularBufInsert(c_buf, a, sizeof(DATA_TYPE)) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+1, sizeof(DATA_TYPE)) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+2, sizeof(DATA_TYPE)) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+3, sizeof(DATA_TYPE)) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+4, sizeof(DATA_TYPE)) == SUCC_BUF_INS);
	assert(CircularBufInsert(c_buf, a+5, sizeof(DATA_TYPE)) == SUCC_BUF_INS);
	DATA_TYPE data;
	while(!CircularBufEmpty(c_buf)){
		CircularBufGet(c_buf, &data, sizeof(DATA_TYPE));
		printf("Data popped for Circular Buffer %d \n", data);
	}
	
    return 0;
}
