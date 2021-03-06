/* Copyright (C) 2006 - 2014 Jan Kundrát <jkt@flaska.net>

   This file is part of the Trojita Qt IMAP e-mail client,
   http://trojita.flaska.net/

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License or (at your option) version 3 or any later version
   accepted by the membership of KDE e.V. (or its successor approved
   by the membership of KDE e.V.), which shall act as a proxy
   defined in Section 14 of version 3 of the license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <functional>
#include "Cache.h"

namespace Imap {
namespace Mailbox {

AbstractCache::~AbstractCache()
{
}

void AbstractCache::setErrorHandler(const std::function<void(const QString &)> &handler)
{
    m_errorHandler = handler;
}

AbstractCache::MessageDataBundle::MessageDataBundle(
        const uint uid, const Message::Envelope &envelope, const QDateTime &internalDate, const quint64 size,
        const QByteArray &serializedBodyStructure, const QList<QByteArray> &hdrReferences,
        const QList<QUrl> &hdrListPost, const bool hdrListPostNo)
    : uid(uid)
    , envelope(envelope)
    , internalDate(internalDate)
    , size(size)
    , serializedBodyStructure(serializedBodyStructure)
    , hdrReferences(hdrReferences)
    , hdrListPost(hdrListPost)
    , hdrListPostNo(hdrListPostNo)
{
}

AbstractCache::MessageDataBundle::MessageDataBundle()
    : uid(0)
    , size(0)
    , hdrListPostNo(false)
{
}

}
}
