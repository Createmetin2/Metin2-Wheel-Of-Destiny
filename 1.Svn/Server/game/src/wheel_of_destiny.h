#pragma once

/*
* Created by blackdragonx61
* Date:05.09.2020
*/

#if defined(WHEEL_OF_DESTINY)
class CWheelDestiny
{
public:
	CWheelDestiny(LPCHARACTER ch);
	~CWheelDestiny();
	void TurnWheel();
	void GiveMyFuckingGift();
	DWORD GetGiftVnum() const;

private:
	void SetGift(const DWORD vnum, const std::uint8_t count);
	int PickAGift();

	std::uint8_t GetGiftCount() const;
	std::uint16_t GetTurnCount() const;
	std::uint8_t GetChance() const;

	LPCHARACTER ch;
	DWORD gift_vnum;
	std::uint8_t gift_count;
	std::uint16_t turn_count;
};
#endif
