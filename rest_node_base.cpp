/*
 * Copyright (c) 2016 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#include "de_web_plugin_private.h"

/*! Constructor.
 */
RestNodeBase::RestNodeBase() :
    m_node(0),
    m_available(false),
    m_read(0),
    m_lastRead(0),
    m_lastAttributeReportBind(0)
{

}

/*! Deconstructor.
 */
RestNodeBase::~RestNodeBase()
{
}

/*! Returns the core node object.
 */
deCONZ::Node *RestNodeBase::node()
{
    return m_node;
}

/*! Sets the core node object.
    \param node the core node
 */
void RestNodeBase::setNode(deCONZ::Node *node)
{
    m_node = node;
}

/*! Returns the modifiable address.
 */
deCONZ::Address &RestNodeBase::address()
{
    return m_addr;
}

/*! Returns the const address.
 */
const deCONZ::Address &RestNodeBase::address() const
{
    return m_addr;
}

/*! Returns true if the node is available.
 */
bool RestNodeBase::isAvailable() const
{
    return m_available;
}

/*! Sets the is available state of the node.
    \param available the available state of the node
 */
void RestNodeBase::setIsAvailable(bool available)
{
    m_available = available;
}

/*! Returns the unique identifier of the node.
 */
const QString &RestNodeBase::id() const
{
    return m_id;
}

/*! Sets the identifier of the node.
    \param id the unique identifier
 */
void RestNodeBase::setId(const QString &id)
{
    m_id = id;
}

/*! Returns the nodes unique Id.
    The MAC address of the device with a unique endpoint id in the form: AA:BB:CC:DD:EE:FF:00:11-XX
 */
const QString &RestNodeBase::uniqueId() const
{
    return m_uid;
}

/*! Sets the sensor unique Id.
    The MAC address of the device with a unique endpoint id in the form: AA:BB:CC:DD:EE:FF:00:11-XX
    \param uid the sensor unique Id
 */
void RestNodeBase::setUniqueId(const QString &uid)
{
    m_uid = uid;
}

/*! Check if some data must be queried from the node.
    \param readFlags or combined bitmap of READ_* values
    \return true if every flag in readFlags is set
*/
bool RestNodeBase::mustRead(uint32_t readFlags)
{
    if ((m_read & readFlags) == readFlags)
    {
        return true;
    }

    return false;
}

/*! Enables all flags given in \p readFlags in the read set.
    \param readFlags or combined bitmap of READ_* values
 */
void RestNodeBase::enableRead(uint32_t readFlags)
{
    m_read |= readFlags;
}

/*! Clears all flags given in \p readFlags in the read set.
    \param readFlags or combined bitmap of READ_* values
 */
void RestNodeBase::clearRead(uint32_t readFlags)
{
    m_read &= ~readFlags;
}

/*! Returns the time than the next auto reading is queued.
 */
const QTime &RestNodeBase::nextReadTime() const
{
    return m_nextReadTime;
}

/*! Sets the time than the next auto reading should be queued.
    \param time the time for reading
 */
void RestNodeBase::setNextReadTime(const QTime &time)
{
    m_nextReadTime = time;
}

/*! Returns the value of the idleTotalCounter than the last reading happend.
 */
int RestNodeBase::lastRead() const
{
    return m_lastRead;
}

/*! Sets the last read counter.
    \param lastRead copy of idleTotalCounter
 */
void RestNodeBase::setLastRead(int lastRead)
{
    m_lastRead = lastRead;
}

/*! Returns the value of the idleTotalCounter than the last attribute report binding was done.
 */
int RestNodeBase::lastAttributeReportBind() const
{
    return m_lastAttributeReportBind;
}

/*! Sets idleTotalCounter of last attribute report binding.
    \param lastBind copy of idleTotalCounter
 */
void RestNodeBase::setLastAttributeReportBind(int lastBind)
{
    m_lastAttributeReportBind = lastBind;
}
