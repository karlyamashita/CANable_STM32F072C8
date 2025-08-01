#ifndef USB_BUFFER_H
#define USB_BUFFER_H




#define ID_AND_SIZE_LENGTH 4 // (uint16_t id) (uint16_t size)
#define USB_DATA_SIZE (256 - ID_AND_SIZE_LENGTH) //256 - id - size

typedef union
{
	struct
	{
		uint8_t data[USB_DATA_SIZE + ID_AND_SIZE_LENGTH];
	}Byte;
	struct
	{
		uint32_t id:8;
		uint32_t :16; // reserved
		uint32_t size:8;
		uint8_t data[USB_DATA_SIZE];
	}Status;
}USB_Data_t;

typedef struct
{
	struct
	{
		USB_Data_t *queue;
		USB_Data_t *msgToParse;
		uint32_t queueSize;
		RING_BUFF_STRUCT ptr;
	}rx;
	struct
	{
		USB_Data_t *queue;
		uint32_t queueSize;
		RING_BUFF_STRUCT ptr;
	}tx;
}USB_MsgStruct;



int USB_SendMessage(USB_MsgStruct *msg);
void USB_AddTxBuffer(USB_MsgStruct *msg, USB_Data_t *data);
void USB_AddRxBuffer(USB_MsgStruct *msg, uint8_t *data, uint32_t size);
uint8_t USB_DataAvailable(USB_MsgStruct *msg);

#endif // USB_BUFFER_H
