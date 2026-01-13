/**
 * @file      sys.System.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2026, Sergey Baigudin, Baigudin Software
 */
#ifndef SYS_SYSTEM_HPP_
#define SYS_SYSTEM_HPP_

#include "sys.NonCopyable.hpp"
#include "api.System.hpp"
#include "sys.Scheduler.hpp"
#include "sys.MutexManager.hpp"
#include "sys.SemaphoreManager.hpp"
#include "sys.StreamManager.hpp"
#include "sys.Heap.hpp"

namespace eoos
{
namespace sys
{

/**
 * @class System
 * @brief The operating system.
 */
class System : public NonCopyable<NoAllocator>, public api::System
{
    using Parent = NonCopyable<NoAllocator>;

public:

    /**
     * @copydoc eoos::api::Object::isConstructed()
     */
    bool_t isConstructed() const noexcept override; ///< SCA AUTOSAR-C++14 Defected Rule A10-2-1

    /**
     * @copydoc eoos::api::System::getHeap()
     */
    api::Heap& getHeap() noexcept override;

    /**
     * @copydoc eoos::api::System::getScheduler()
     */
    api::Scheduler& getScheduler() noexcept override;

    /**
     * @copydoc eoos::api::System::getMutexManager()
     */
    api::MutexManager& getMutexManager() noexcept override;

    /**
     * @copydoc eoos::api::System::getSemaphoreManager()
     */
    api::SemaphoreManager& getSemaphoreManager() noexcept override;

    /**
     * @copydoc eoos::api::System::getStreamManager()
     */
    api::StreamManager& getStreamManager() noexcept override;

    /**
     * @brief Runs the EOOS system.
     *
     * @param task The first task run by the system.
     * @return error code or zero.
     */
    static int32_t run(api::Task& task) noexcept;

    /**
     * @brief Returns an only one created instance of the EOOS system.
     *
     * @return The EOOS system instance.
     */
    static api::System& getSystem() noexcept;

private:

    /**
     * @brief Constructor.
     */
    System() noexcept;

    /**
     * @brief Destructor.
     */
    ~System() noexcept override;

    /**
     * @brief Constructs this object.
     *
     * @return True if object has been constructed successfully.
     */
    bool_t construct() noexcept;

    /**
     * @copydoc eoos::Object::Object(Object const&)
     */
    System(System const&) noexcept = delete;

    /**
     * @copydoc eoos::Object::operator=(Object const&)
     */
    System& operator=(System const&) noexcept = delete;

    /**
     * @copydoc eoos::Object::Object(Object&&)
     */
    System(System&&) noexcept = delete;

    /**
     * @copydoc eoos::Object::operator=(Object&&)
     */
    System& operator=(System&&) & noexcept = delete;

    /**
     * @brief The operating system.
     */
    static api::System* eoos_;

    /**
     * @brief The system heap.
     */
    Heap heap_{};

    /**
     * @brief The operating system scheduler.
     */
    Scheduler scheduler_{};

    /**
     * @brief The mutex sub-system manager.
     */
    MutexManager mutexManager_{};

    /**
     * @brief The semaphore sub-system manager.
     */
    SemaphoreManager semaphoreManager_{};

    /**
     * @brief The stream sub-system manager.
     */
    StreamManager streamManager_{};

};

} // namespace sys
} // namespace eoos
#endif // SYS_SYSTEM_HPP_
