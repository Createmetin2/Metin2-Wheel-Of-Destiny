//Find
		case HEADER_CG_ITEM_PICKUP:
			if (!ch->IsObserverMode())
				ItemPickup(ch, c_pData);
			break;
			
///Add
#if defined(WHEEL_OF_DESTINY)
		case HEADER_CG_WHEEL_DESTINY:
			if (!ch->IsObserverMode())
				WheelDestiny(ch, c_pData);
			break;
#endif

//Find
void CInputMain::ItemPickup(LPCHARACTER ch, const char * data)
{
	...
}

///Add
#if defined(WHEEL_OF_DESTINY)
void CInputMain::WheelDestiny(LPCHARACTER ch, const char* data)
{
	if (!ch)
		return;

	const auto pinfo = reinterpret_cast<const TPacketCGWheelDestiny*>(data);
	enum { OPEN, CLOSE, TURN, GIVE };

	switch (pinfo->option) {
	case OPEN:
		if (!ch->GetWheelDestiny())
			ch->SetWheelDestiny(std::make_shared<CWheelDestiny>(ch));
		break;
	case CLOSE:
		if (ch->GetWheelDestiny()) {
			if (ch->GetWheelDestiny()->GetGiftVnum())
				ch->ChatPacket(CHAT_TYPE_INFO, "Wait motherfucker!");
			else
			{
				ch->SetWheelDestiny(nullptr);
				ch->ChatPacket(CHAT_TYPE_COMMAND, "BINARY_WHEEL_CLOSE");
			}
		}
		break;
	case TURN:
		if (ch->GetWheelDestiny())
			ch->GetWheelDestiny()->TurnWheel();
		break;
	case GIVE:
		if (ch->GetWheelDestiny())
			ch->GetWheelDestiny()->GiveMyFuckingGift();
		break;
	default:
		sys_err("CInputMain::WheelDestiny : Unknown option %d : %s", pinfo->option, ch->GetName());
		break;
	}
}
#endif