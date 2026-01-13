/**
 * @file      sys.Call.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2026, Sergey Baigudin, Baigudin Software
 */
#ifndef SYS_CALL_HPP_
#define SYS_CALL_HPP_

#include "api.System.hpp"
#include "api.Task.hpp"

namespace eoos
{
namespace sys
{

/**
 * @class Call
 * @brief System calls of the operating system.
 */
class Call
{

public:

    /**
     * @brief Returns the EOOS system interface.
     *
     * @return The system interface.
     */
    static api::System& get() noexcept;

    /**
     * @brief Runs the EOOS system.
     *
     * @param task The first task run by the system.
     * @return error code or zero.
     */
    static int32_t run(api::Task& task) noexcept;

};

} // namespace sys
} // namespace eoos
#endif // SYS_CALL_HPP_
