//Find
PyObject* netSendItemPickUpPacket(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(WHEEL_OF_DESTINY)
PyObject* netWheelPacket(PyObject* poSelf, PyObject* poArgs)
{
	int option;
	if (!PyTuple_GetInteger(poArgs, 0, &option))
		return Py_BuildException();

	CPythonNetworkStream::Instance().WheelDestiny(option);
	return Py_BuildNone();
}
#endif

//Find
		{ "SendItemPickUpPacket",				netSendItemPickUpPacket,				METH_VARARGS },
		
///Add
#if defined(WHEEL_OF_DESTINY)
		{ "WheelPacket",						netWheelPacket,							METH_VARARGS },
#endif