//Find
void CPythonNetworkStream::ToggleGameDebugInfo()
{
	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "ToggleDebugInfo", Py_BuildValue("()"));
}

///Add
#if defined(WHEEL_OF_DESTINY)
bool CPythonNetworkStream::WheelDestiny(const BYTE option)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGWheelDestiny p;
	p.header = HEADER_CG_WHEEL_DESTINY;
	p.option = option;

	if (!Send(sizeof(p), &p)) {
		Tracen("Error WheelDestiny");
		return false;
	}

	return SendSequence();
}
#endif