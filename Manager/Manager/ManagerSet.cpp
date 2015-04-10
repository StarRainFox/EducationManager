
// ManagerSet.cpp : CManagerSet ���ʵ��
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerSet ʵ��

// ���������� 2015��4��10��, 10:28

IMPLEMENT_DYNAMIC(CManagerSet, CRecordset)

CManagerSet::CManagerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_DetailOfBuilding7RoomID = 0;
	m_DetailOfBuilding7NumberOfSeat = 0;
	m_DetailOfBuilding7NumberOfComputer = 0;
	m_DetailOfBuilding7NumberOfWhitebash = 0;
	m_DetailOfBuilding7NumberOfProject = 0;
	
	m_DetailOfComputer7203ComputerID = L"";
	m_DetailOfComputer7203SoftwareName = L"";
	m_DetailOfComputer7203DamageStatus = FALSE;
	m_DetailOfComputer7203DamageRemark = L"";
	m_DetailOfComputer7203FixLog = L"";
	m_DetailOfComputer7203BlongOfRoomID = 0;
	m_nFields = 16;
	m_nDefaultType = dynaset;
}
#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CManagerSet::GetDefaultConnect()
{
	return _T("DSN=manager;DBQ=DATABASE\\BuildingManager.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CManagerSet::GetDefaultSQL()
{
	return _T("[DetailOfBuilding7],[DetailOfComputer7203]");
}

void CManagerSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[DetailOfBuilding7].[RoomID]"), m_DetailOfBuilding7RoomID);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfSeat]"), m_DetailOfBuilding7NumberOfSeat);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfComputer]"), m_DetailOfBuilding7NumberOfComputer);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfWhitebash]"), m_DetailOfBuilding7NumberOfWhitebash);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfProject]"), m_DetailOfBuilding7NumberOfProject);
	
	RFX_Text(pFX, _T("[DetailOfComputer7203].[ComputerID]"), m_DetailOfComputer7203ComputerID);
	RFX_Text(pFX, _T("[DetailOfComputer7203].[SoftwareName]"), m_DetailOfComputer7203SoftwareName);
	RFX_Bool(pFX, _T("[DetailOfComputer7203].[DamageStatus]"), m_DetailOfComputer7203DamageStatus);
	RFX_Text(pFX, _T("[DetailOfComputer7203].[DamageRemark]"), m_DetailOfComputer7203DamageRemark);
	RFX_Text(pFX, _T("[DetailOfComputer7203].[FixLog]"), m_DetailOfComputer7203FixLog);
	RFX_Long(pFX, _T("[DetailOfComputer7203].[BlongOfRoomID]"), m_DetailOfComputer7203BlongOfRoomID);

}
/////////////////////////////////////////////////////////////////////////////
// CManagerSet ���

#ifdef _DEBUG
void CManagerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CManagerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

