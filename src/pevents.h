/*
Copyright (C) 2011 - 2018 by NeoSmart Technologies <http://neosmart.net/>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#if defined(_WIN32) && !defined(CreateEvent)
#error Must include Windows.h prior to including pevents.h!
#endif
#ifndef WAIT_TIMEOUT
#include <errno.h>
#define WAIT_TIMEOUT ETIMEDOUT
#endif

#include <stdint.h>

// TODO: https://stackoverflow.com/questions/2744181/how-to-call-c-function-from-c

namespace neosmart {
    // Type declarations
    struct neosmart_event_t_;
    typedef neosmart_event_t_ *neosmart_event_t;

    // Constant declarations
    const uint64_t WAIT_INFINITE = ~((uint64_t)0);

    // Function declarations
    neosmart_event_t CreateEvent(bool manualReset = false, bool initialState = false);
    int DestroyEvent(neosmart_event_t event);
    int WaitForEvent(neosmart_event_t event, uint64_t milliseconds = WAIT_INFINITE);
    int SetEvent(neosmart_event_t event);
    int ResetEvent(neosmart_event_t event);
#ifdef WFMO
    int WaitForMultipleEvents(neosmart_event_t *events, int count, bool waitAll,
                              uint64_t milliseconds);
    int WaitForMultipleEvents(neosmart_event_t *events, int count, bool waitAll,
                              uint64_t milliseconds, int &index);
#endif
#ifdef PULSE
    int PulseEvent(neosmart_event_t event);
#endif
} // namespace neosmart
