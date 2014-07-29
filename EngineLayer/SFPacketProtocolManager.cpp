#include "stdafx.h"
#include "SFPacketProtocolManager.h"

SFPacketProtocolManager::SFPacketProtocolManager(bool bMultiPacketProtocol)
: m_bMultiPacketProtocol(bMultiPacketProtocol)
{
}

SFPacketProtocolManager::~SFPacketProtocolManager()
{
	for (auto& iter : m_mapPacketProtocol)
	{
		IPacketProtocol* pProtocol = iter.second;
		delete pProtocol;
	}

	m_mapPacketProtocol.clear();
}

bool SFPacketProtocolManager::AddPacketProtocol(int packetProtocolId, IPacketProtocol* pProtocol)
{
	if (m_bMultiPacketProtocol == false && m_mapPacketProtocol.size() >= 1)
		return false;

	m_mapPacketProtocol.insert(std::make_pair(packetProtocolId, pProtocol));
	return true;
}

bool SFPacketProtocolManager::AddListenerInfo(int listenerId, int packetProtocolId)
{
	_ListenerInfo info;
	info.listenerId = listenerId;
	info.packetProtocolId = packetProtocolId;

	m_listListenerInfo.push_back(info);

	return true;
}

bool SFPacketProtocolManager::AddConnectorInfo(_ConnectorInfo* pInfo)
{
	m_listConnectorInfo.push_back(*pInfo);

	return true;
}

bool SFPacketProtocolManager::SetConnectorPacketProtocol(int connectorId, int packetProtocolId)
{
	for (auto& iter : m_listConnectorInfo)
	{
		if (iter.connectorId == connectorId)
		{
			iter.packetProtocolId = packetProtocolId;
			return true;
		}
	}

	return false;
}

bool SFPacketProtocolManager::SetConnectorState(int connectorId, bool connected)
{
	for (auto& iter : m_listConnectorInfo)
	{
		_ConnectorInfo& info = iter;

		if (info.connectorId == connectorId)
		{
			info.connected = connected;
			return true;
		}
	}

	return false;
}
