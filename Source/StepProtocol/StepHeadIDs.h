#pragma once

namespace step
{
	class StepHeadIDs
	{
	public:
		static constexpr unsigned int PackageID = 0x0001;
		static constexpr unsigned int BodyLen = 0x0002;
		static constexpr unsigned int MessageChain = 0x0003;
		static constexpr unsigned int MsgSeqNum = 0x0004;
		static constexpr unsigned int CheckSum = 0x0005;
		static constexpr unsigned int FieldStart = 0x0006;
		static constexpr unsigned int FieldEnd = 0x0007;
	};
}