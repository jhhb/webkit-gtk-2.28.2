/*
 * Copyright (C) 2018 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "config.h"
#include "BlobEvent.h"

#if ENABLE(MEDIA_STREAM)

#include "Blob.h"
#include <wtf/IsoMallocInlines.h>

namespace WebCore {

WTF_MAKE_ISO_ALLOCATED_IMPL(BlobEvent);

Ref<BlobEvent> BlobEvent::create(const AtomString& type, Init&& init, IsTrusted isTrusted)
{
    return adoptRef(*new BlobEvent(type, WTFMove(init), isTrusted));
}

Ref<BlobEvent> BlobEvent::create(const AtomString& type, CanBubble canBubble, IsCancelable isCancelable, Ref<Blob>&& data)
{
    return adoptRef(*new BlobEvent(type, canBubble, isCancelable, WTFMove(data)));
}

BlobEvent::BlobEvent(const AtomString& type, Init&& init, IsTrusted isTrusted)
    : Event(type, init, isTrusted)
    , m_blob(init.data.releaseNonNull())
{
}

BlobEvent::BlobEvent(const AtomString& type, CanBubble canBubble, IsCancelable isCancelable, Ref<Blob>&& data)
    : Event(type, canBubble, isCancelable)
    , m_blob(WTFMove(data))
{
}
    
EventInterface BlobEvent::eventInterface() const
{
    return BlobEventInterfaceType;
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM)
