#pragma once
#include "afxcmn.h"
#include "ClassRoomManagerSet.h"

// Room �Ի���

class Room : public CDialogEx
{
	DECLARE_DYNAMIC(Room)

public:
	Room(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Room();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtoncontect();
	afx_msg void OnBnClickedButtoninsert();
	afx_msg void OnBnClickedButtondelete();
	CListCtrl List;
	long broad;
	long computer;
	long ID;
	long project;
	long seat;
	CString RoomID;
	CString NumberOfSeat;
	CString NumberOfComputer;
	CString NumberOfWhitebash;
	CString NumberOfProject;
	CDatabase DB;
	CClassRoomManagerSet *Record;			//��̬������
};
