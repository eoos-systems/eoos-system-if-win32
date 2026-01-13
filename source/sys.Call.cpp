/**
 * @file      sys.Call.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2026, Sergey Baigudin, Baigudin Software
 */
#include "sys.Call.hpp"
#include "sys.System.hpp"

namespace eoos
{
namespace sys
{

api::System& Call::get() noexcept
{
    return System::getSystem();
}

int32_t Call::run(api::Task& task) noexcept
{
    return System::run(task);
}

} // namespace sys
} // namespace eoos
