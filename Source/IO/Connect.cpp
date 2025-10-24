#include "Connect.h"

using namespace std;

Buffer<BuffSize>* Connect::GetBuffer()
{
	lock_guard<mutex> guard(BuffersMutex);
	if (Buffers.empty())
		return nullptr;
	auto buffer = Buffers.front();
	Buffers.pop_front();
	return buffer;
}
