#pragma once
#include "afxcmn.h"


// ROOM �Ի���

class ROOM : public CDialogEx
{
	DECLARE_DYNAMIC(ROOM)

public:
	ROOM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ROOM();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()
public:
	
	CDatabase DB;		//�½�һ�����ݿ����
	CRecordset *Record;		//�½�һ����¼��ָ�����
	CListCtrl List;	//�б�ؼ��Ķ���

	//�нӴ����ݿ�õ������ݵı���
	CString RoomID;  //	���ҵı��  ��������
	CString NumberOfSeat;  //	��λ�ĸ���
	CString NumberOfComputer;  //		������ĸ���
	CString NumberOfWhitebash;  //		�װ�ĸ���
	CString NumberOfProject;  //		ͶӰ�ǵĸ���
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();		
	afx_msg void OnBnClickedButton2();

	CString broad;		//�ؼ��ı���
	CString computer;
	CString ID;
	CString project;
	CString seat;
//	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
