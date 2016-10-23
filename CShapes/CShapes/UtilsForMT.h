#pragma once

#include <utility>
#include <vector>

enum class RETURN_CODE;


namespace assertWrapper
{
RETURN_CODE getFinalResultCode(std::vector<RETURN_CODE> inCodes);
}

