
// BuildingSet.h: CBuildingSet ��Ľӿ�
//


#pragma once

// ���������� 2015��4�� ������, 16:48

class CBuildingSet : public CRecordset
{
public:
	CBuildingSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBuildingSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_RoomID;	//���ҵı��
	long	m_NumberOfSeat;	//��λ�ĸ���
	long	m_NumberOfComputer;	//������ĸ���
	long	m_NumberOfWhitebash;	//�װ�ĸ���
	long	m_NumberOfProject;	//ͶӰ�ǵĸ���

	/*
	long m_ComputerID;		//���Ա��
	long m_SoftwareName;		//�豸�ϰ�װ�������
	long m_DamageStatus;		//���״̬
	long m_DamageRemark;		//���ԭ��
	long m_FixLog;			//ά�޼�¼
	long m_BlongOfRoomID;		//��������
	*/

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

