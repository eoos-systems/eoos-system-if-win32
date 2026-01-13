/**
 * @file      sys.System.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2026, Sergey Baigudin, Baigudin Software
 */
#include "sys.System.hpp"

namespace eoos
{
namespace sys
{

api::System* System::eoos_{ NULLPTR };

System::System() noexcept
    : NonCopyable<NoAllocator>()
    , api::System() {
    bool_t const isConstructed{ construct() };
    setConstructed( isConstructed );
}

System::~System() noexcept
{
    eoos_ = NULLPTR;
}

bool_t System::isConstructed() const noexcept
{
    return Parent::isConstructed();
}

api::Heap& System::getHeap() noexcept
{
    return heap_; ///< SCA AUTOSAR-C++14 Justified Rule A9-3-1
}

api::Scheduler& System::getScheduler() noexcept
{
    return scheduler_; ///< SCA AUTOSAR-C++14 Justified Rule A9-3-1
}

api::MutexManager& System::getMutexManager() noexcept
{
    return mutexManager_; ///< SCA AUTOSAR-C++14 Justified Rule A9-3-1
}

api::SemaphoreManager& System::getSemaphoreManager() noexcept
{
    return semaphoreManager_; ///< SCA AUTOSAR-C++14 Justified Rule A9-3-1
}

api::StreamManager& System::getStreamManager() noexcept
{
    return streamManager_; ///< SCA AUTOSAR-C++14 Justified Rule A9-3-1
}

int32_t System::run(api::Task& task) noexcept
{
    int32_t error{ -1 };
    System eoos;
    if( eoos.isConstructed() )
    {
        task.start();
        error = 0;
    }
    return error;
}

api::System& System::getSystem() noexcept
{
    if(eoos_ == NULLPTR)
    {   ///< UT Justified Branch: Startup dependency
        ::ExitProcess(-1);
    }
    return *eoos_;
}

bool_t System::construct() noexcept
{
    bool_t res{ false };
    if( ( isConstructed() )
     && ( eoos_ == NULLPTR )
     && ( heap_.isConstructed() )
     && ( scheduler_.isConstructed() )
     && ( mutexManager_.isConstructed() )
     && ( semaphoreManager_.isConstructed() )
     && ( streamManager_.isConstructed() ) )
    {
        eoos_ = this;
        res = true;
    }
    return res;
}

} // namespace sys
} // namespace eoos
