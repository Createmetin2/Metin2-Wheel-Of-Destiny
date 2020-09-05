///Add
#if defined(WHEEL_OF_DESTINY)
#include "wheel_of_destiny.h"
#endif

//Find
	public:
		bool			ExchangeStart(LPCHARACTER victim);
		void			SetExchange(CExchange * pkExchange);
		CExchange *		GetExchange() const	{ return m_pkExchange;	}

	protected:
		CExchange *		m_pkExchange;
		
///Add
#if defined(WHEEL_OF_DESTINY)
	public:
		void SetWheelDestiny(std::shared_ptr<CWheelDestiny> pt) { pWheelDestiny = std::move(pt); };
		std::shared_ptr<CWheelDestiny> GetWheelDestiny() const { return pWheelDestiny; }
		void SetWheelFreeCount(const int count) { SetQuestFlag("wheel.free", GetWheelFreeCount() + count); }
		int GetWheelFreeCount() const { return GetQuestFlag("wheel.free"); }
		
	private:
		std::shared_ptr<CWheelDestiny> pWheelDestiny = nullptr;
#endif