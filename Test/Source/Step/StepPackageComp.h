#include "StepPackages.h"
#include <string>
#include <cstring>

template<>
struct std::less<step::StepRtnExchangeStatusPackage>
{
	bool operator()(const step::StepRtnExchangeStatusPackage* left, const step::StepRtnExchangeStatusPackage* right) const
	{
		return strcmp(left->RtnExchangeStatus->ExchangeID, right->RtnExchangeStatus->ExchangeID) < 0;
	}
};

template<>
struct std::less<step::StepRtnShortMdPackage>
{
	bool operator()(const step::StepRtnShortMdPackage* left, const step::StepRtnShortMdPackage* right) const
	{
		if (strcmp(left->ShortMd->ExchangeID, right->ShortMd->ExchangeID) < 0)
		{
			return true;
		}
		else if (strcmp(left->ShortMd->ExchangeID, right->ShortMd->ExchangeID) > 0)
		{
			return false;
		}
		return strcmp(left->ShortMd->InstrumentID, right->ShortMd->InstrumentID) < 0;
	}
};


