#include "stdafx.h"
#include "wheel_of_destiny.h"
#include "char.h"

#if defined(WHEEL_OF_DESTINY)

static constexpr auto WheelPrice = 1000000; // 1M
static constexpr auto WheelItemMax = 16;

//vnum, count(max 255), chance(max 255)
static constexpr std::tuple<DWORD, std::uint8_t, std::uint8_t> m_Data[WheelItemMax] =
{	
	{ 11209, 1, 0 }, { 11219, 1, 0 }, { 11229, 1, 0 }, { 11239, 1, 0 },
	{ 11249, 1, 0 }, { 11259, 1, 0 }, { 11269, 1, 0 }, { 11279, 1, 0 },
	{ 11289, 1, 0 }, { 11299, 1, 0 }, { 19, 1, 100 }, { 279, 1, 0 },
	{ 299, 1, 0 }, { 29, 1, 0 }, { 39, 1, 0 }, { 49, 1, 0 },
};

CWheelDestiny::CWheelDestiny(LPCHARACTER m_ch)
	: ch(m_ch), gift_vnum(0), gift_count(1), turn_count(0)
{
	for (auto i = 0; i < WheelItemMax; i++)
		ch->ChatPacket(CHAT_TYPE_COMMAND, "BINARY_WHEEL_ICON %lu %d %d", std::get<0>(m_Data[i]), std::get<1>(m_Data[i]), i);
	ch->ChatPacket(CHAT_TYPE_COMMAND, "BINARY_WHEEL_OPEN %d %d", WheelPrice, ch->GetWheelFreeCount());
}

CWheelDestiny::~CWheelDestiny() {
	if (GetGiftVnum())
		sys_log(0, "<CWheelDestiny> player(%s) didn't get his gift(vnum: %lu(%d.x))!!", ch->GetName(), GetGiftVnum(), GetGiftCount());
}

template <typename T> std::string NumberToMoneyString(T val)
{
	constexpr int comma = 3;
	auto str = std::to_string(val);
	auto pos = static_cast<int>(str.length()) - comma;
	
	while (pos > 0) {
		str.insert(pos, ".");
		pos -= comma;
	}
	
	return str;
}

void CWheelDestiny::TurnWheel()
{
	if (GetGiftVnum()) {
		ch->ChatPacket(CHAT_TYPE_INFO, "Wait motherfucker!");
		return;
	}

	const auto WheelFreeCount = ch->GetWheelFreeCount();
	
	if (WheelFreeCount < 1 && ch->GetGold() < WheelPrice) {
		ch->ChatPacket(CHAT_TYPE_INFO, "You need %s yang for <Turning Wheel>", NumberToMoneyString(WheelPrice).c_str());
		return;
	}

	auto Rand = PickAGift();
	if (Rand == -1) {
		sys_err("CWheelDestiny::TurnWheel() Error Pick Gift (%s)", ch->GetName());
		return;
	}

	if (WheelFreeCount > 0) {
		ch->SetWheelFreeCount(-1);
		ch->ChatPacket(CHAT_TYPE_INFO, "FREE");
	}
	else
		ch->PointChange(POINT_GOLD, -WheelPrice);
	
	//vnum, count, spin count, pos
	ch->ChatPacket(CHAT_TYPE_COMMAND, "BINARY_WHEEL_TURN %lu %d %d %d", GetGiftVnum(), GetGiftCount(), number(1, 8), Rand);

	turn_count++;
}

std::uint8_t CWheelDestiny::GetChance() const
{
#undef max
	const auto TurnCount = GetTurnCount();
	if (TurnCount >= 10 && TurnCount < 25)
		return 25;
	if (TurnCount >= 25 && TurnCount < 40)
		return 50;
	if (TurnCount >= 40)
		return std::numeric_limits<std::uint8_t>::max(); // 255
	return 0;
}

int CWheelDestiny::PickAGift()
{
	const auto Chance = GetChance();

	while (true) {
		const auto rand_pos = number(0, WheelItemMax - 1);
		const auto& [item, count, m_chance] = m_Data[rand_pos];

		if (Chance >= m_chance) {
			SetGift(item, count);
			return rand_pos;
		}
	}
	return -1; // error
}

void CWheelDestiny::SetGift(const DWORD vnum, const std::uint8_t count)
{
	gift_vnum = vnum;
	gift_count = count;
}

void CWheelDestiny::GiveMyFuckingGift()
{
	const auto GiftVnum = GetGiftVnum();

	if (GiftVnum) {
		ch->AutoGiveItem(GiftVnum, GetGiftCount());
		SetGift(0, 1); // reset
	}
	else
		sys_err("Dude, where is the gift_vnum? <player: %s>", ch->GetName());
}

DWORD CWheelDestiny::GetGiftVnum() const
{
	return gift_vnum;
}

std::uint8_t CWheelDestiny::GetGiftCount() const
{
	return gift_count; 
}

std::uint16_t CWheelDestiny::GetTurnCount() const
{ 
	return turn_count; 
}
#endif
