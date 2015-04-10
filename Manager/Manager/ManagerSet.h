
// ManagerSet.h: CManagerSet ��Ľӿ�
//


#pragma once

// ���������� 2015��4��10��, 10:28

class CManagerSet : public CRecordset
{
public:
	CManagerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CManagerSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_DetailOfBuilding7RoomID;	//���ҵı��
	long	m_DetailOfBuilding7NumberOfSeat;	//��λ�ĸ���
	long	m_DetailOfBuilding7NumberOfComputer;	//������ĸ���
	long	m_DetailOfBuilding7NumberOfWhitebash;	//�װ�ĸ���
	long	m_DetailOfBuilding7NumberOfProject;	//ͶӰ�ǵĸ���
	
	CStringW	m_DetailOfComputer7203ComputerID;	//������ı�ţ���Ϊ�п��ܻ�ʹ����ĸ��������Ϊ���ı�
	CStringW	m_DetailOfComputer7203SoftwareName;	//������ϰ�װ���������Ϊ���кܶ������������Ϊ���ı�
	BOOL	m_DetailOfComputer7203DamageStatus;	//������Ƿ������״̬
	CStringW	m_DetailOfComputer7203DamageRemark;	//���ԭ��
	CStringW	m_DetailOfComputer7203FixLog;	//ά�޼�¼
	long	m_DetailOfComputer7203BlongOfRoomID;	//�������ҵı��

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

