//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(WHEEL_OF_DESTINY)
	PyModule_AddIntConstant(poModule, "WHEEL_OF_DESTINY", true);
#else
	PyModule_AddIntConstant(poModule, "WHEEL_OF_DESTINY", false);
#endif