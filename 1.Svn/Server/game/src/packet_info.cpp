//Find
		Set(HEADER_CG_ITEM_PICKUP, sizeof(TPacketCGItemPickup), "ItemPickup", true);
	
///Add
#if defined(WHEEL_OF_DESTINY)
	Set(HEADER_CG_WHEEL_DESTINY, sizeof(TPacketCGWheelDestiny), "WheelDestiny", true);
#endif