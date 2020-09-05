//Find
	HEADER_CG_SCRIPT_SELECT_ITEM	= 114,

///Add
#if defined(WHEEL_OF_DESTINY)
	HEADER_CG_WHEEL_DESTINY = 135,
#endif

//Find
typedef struct command_item_pickup
{
	BYTE 	header;
	DWORD	vid;
} TPacketCGItemPickup;

///Add
#if defined(WHEEL_OF_DESTINY)
typedef struct command_wheel
{
	BYTE	header;
	BYTE 	option;
} TPacketCGWheelDestiny;
#endif