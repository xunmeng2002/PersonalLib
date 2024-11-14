#include "XtpPackages.h"
#include <string>
#include <cstring>



template<>
struct std::less<xtp::XtpRtnExchangeStatusPackage>
{
	bool operator()(const xtp::XtpRtnExchangeStatusPackage* left, const xtp::XtpRtnExchangeStatusPackage* right) const
	{
		return strcmp(left->Field.ExchangeID, right->Field.ExchangeID) < 0;
	}
};

template<>
struct std::less<xtp::XtpRtnInstrumentPackage>
{
	bool operator()(const xtp::XtpRtnInstrumentPackage* left, const xtp::XtpRtnInstrumentPackage* right) const
	{
		if (strcmp(left->Field.ExchangeID, right->Field.ExchangeID) < 0)
		{
			return true;
		}
		else if (strcmp(left->Field.ExchangeID, right->Field.ExchangeID) > 0)
		{
			return false;
		}
		return strcmp(left->Field.InstrumentID, right->Field.InstrumentID) < 0;
	}
};

template<>
struct std::less<xtp::XtpRtnShortMDPackage>
{
	bool operator()(const xtp::XtpRtnShortMDPackage* left, const xtp::XtpRtnShortMDPackage* right) const
	{
		if (strcmp(left->Field.ExchangeID, right->Field.ExchangeID) < 0)
		{
			return true;
		}
		else if (strcmp(left->Field.ExchangeID, right->Field.ExchangeID) > 0)
		{
			return false;
		}
		return strcmp(left->Field.InstrumentID, right->Field.InstrumentID) < 0;
	}
};
