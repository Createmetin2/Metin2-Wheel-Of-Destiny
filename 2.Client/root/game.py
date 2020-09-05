#Add
if app.WHEEL_OF_DESTINY:
	import uiWheel
	
#Find in def __init__(self, stream):
		self.playerGauge = None
		
#Add
		if app.WHEEL_OF_DESTINY:
			self.WheelDestiny  = None
			
#Find
		self.playerGauge = uiPlayerGauge.PlayerGauge(self)
		self.playerGauge.Hide()
		
#Add
		if app.WHEEL_OF_DESTINY:
			self.WheelDestiny = uiWheel.WheelOfDestiny()
			
#Find in def Close(self):
		self.guildNameBoard = None
		
#Add
		if app.WHEEL_OF_DESTINY:
			self.WheelDestiny = None
	
#Find
		onPressKeyDict[app.DIK_F4]	= lambda : self.__PressQuickSlot(7)
		
#Add
		if app.WHEEL_OF_DESTINY:
			onPressKeyDict[app.DIK_F5]	= lambda : net.WheelPacket(0)
			
#Find
		self.serverCommander=stringCommander.Analyzer()
		for serverCommandItem in serverCommandList.items():
			self.serverCommander.SAFE_RegisterCallBack(
				serverCommandItem[0], serverCommandItem[1]
			)
			
#Add Above(!)
		if app.WHEEL_OF_DESTINY:
			serverCommandList["BINARY_WHEEL_OPEN"] = self.BINARY_WHEEL_OPEN
			serverCommandList["BINARY_WHEEL_CLOSE"] = self.BINARY_WHEEL_CLOSE
			serverCommandList["BINARY_WHEEL_TURN"] = self.BINARY_WHEEL_TURN
			serverCommandList["BINARY_WHEEL_ICON"] = self.BINARY_WHEEL_ICON
			
#Find
	def PartyHealReady(self):
		self.interface.PartyHealReady()
		
#Add
	if app.WHEEL_OF_DESTINY:
		def BINARY_WHEEL_OPEN(self, price, free):
			if self.WheelDestiny:
				self.WheelDestiny.Open(price, free)
		def BINARY_WHEEL_CLOSE(self):
			if self.WheelDestiny:
				self.WheelDestiny.Close()
		def BINARY_WHEEL_TURN(self, item, count, spin, number):
			if self.WheelDestiny.IsShow():
				self.WheelDestiny.TurnWheel(item, count, spin, number)				
		def BINARY_WHEEL_ICON(self, item, count, number):
			if self.WheelDestiny:
				self.WheelDestiny.SetIcons(item, count, number)