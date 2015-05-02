
// BuildingSet.cpp : CBuildingSet ���ʵ��
//

#include "stdafx.h"
#include "Building.h"
#include "BuildingSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBuildingSet ʵ��

// ���������� 2015��4�� ������, 16:48

IMPLEMENT_DYNAMIC(CBuildingSet, CRecordset)

CBuildingSet::CBuildingSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_RoomID = 0;
	m_NumberOfSeat = 0;
	m_NumberOfComputer = 0;
	m_NumberOfWhitebash = 0;
	m_NumberOfProject = 0;
	/*
	m_ComputerID=0;
	m_SoftwareName=0;
	m_DamageStatus=0;
	m_DamageRemark=0;
	m_FixLog=0;
	m_BlongOfRoomID=0;
	*/
	m_nFields = 5;
	m_nDefaultType = dynaset;

}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CBuildingSet::GetDefaultConnect()
{
	return _T("DSN=BuildingManager;DBQ=C:\\Users\\Administrator\\Documents\\Access\\DataBase\\BuildingManager.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;PWD=admin;UID=admin;");
}

CString CBuildingSet::GetDefaultSQL()
{
	return _T("[DetailOfRoom7]");
	//,[DetailOfComputer7203]
}

void CBuildingSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[RoomID]"), m_RoomID);
	RFX_Long(pFX, _T("[NumberOfSeat]"), m_NumberOfSeat);
	RFX_Long(pFX, _T("[NumberOfComputer]"), m_NumberOfComputer);
	RFX_Long(pFX, _T("[NumberOfWhitebash]"), m_NumberOfWhitebash);
	RFX_Long(pFX, _T("[NumberOfProject]"), m_NumberOfProject);
	/*
	RFX_Long(pFX, _T("[ComputerID]"), m_ComputerID);
	RFX_Long(pFX, _T("[SoftwareName]"), m_SoftwareName);
	RFX_Long(pFX, _T("[DamageStatus]"), m_DamageStatus);
	RFX_Long(pFX, _T("[DamageRemark]"), m_DamageRemark);
	RFX_Long(pFX, _T("[FixLog]"), m_FixLog);
	RFX_Long(pFX, _T("[BlongOfRoomID]"), m_BlongOfRoomID);
	*/
}
/////////////////////////////////////////////////////////////////////////////
// CBuildingSet ���

#ifdef _DEBUG
void CBuildingSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBuildingSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

