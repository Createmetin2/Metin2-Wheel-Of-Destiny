//Find
	HEADER_CG_RUNUP_MATRIX_ANSWER               = 201,
	
///Add
#if defined(WHEEL_OF_DESTINY)
	HEADER_CG_WHEEL_DESTINY = 135,
#endif

//Find
typedef struct command_item_pickup
{
	BYTE header;
	DWORD vid;
} TPacketCGItemPickUp;

///Add
#if defined(WHEEL_OF_DESTINY)
typedef struct command_wheel
{
	BYTE	header;
	BYTE 	option;
} TPacketCGWheelDestiny;
#endif