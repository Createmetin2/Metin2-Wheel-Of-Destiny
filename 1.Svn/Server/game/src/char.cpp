//Find in: bool CHARACTER::IsHack(bool bSendMsg, bool bCheckShopOwner, int limittime)
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())
			
///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(WHEEL_OF_DESTINY)
			|| GetWheelDestiny()
#endif
			)
			
//Find
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())
			
///Change
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
#if defined(WHEEL_OF_DESTINY)
			|| GetWheelDestiny()
#endif	
			)