#pragma once

#include <utility>
#include <vector>

enum class ERROR_CODE;

using ResultCode = std::pair<int, ERROR_CODE>;

namespace assertWrapper
{
ResultCode getFinalResultCode(std::vector<ERROR_CODE> inCodes);
}

