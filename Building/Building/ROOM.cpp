// ROOM.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Building.h"
#include "BuildingSet.h"
#include "ROOM.h"
#include "afxdialogex.h"


// ROOM �Ի���

IMPLEMENT_DYNAMIC(ROOM, CDialogEx)

ROOM::ROOM(CWnd* pParent /*=NULL*/)
	: CDialogEx(ROOM::IDD, pParent)
{			//�ؼ��ĳ�ʼ����Ҫд�������������󱻴���ʱ�����ڻ�û�д�������̸�ؼ���
}

ROOM::~ROOM()
{
}

void ROOM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
}

BEGIN_MESSAGE_MAP(ROOM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ROOM::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ROOM::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ROOM::OnBnClickedButton3)
END_MESSAGE_MAP()

// ROOM ��Ϣ��������

BOOL ROOM::OnInitDialog()				//��д�Ĵ��ڳ�ʼ�����������������дһЩ�ؼ��ĳ�ʼ��
{
	CDialogEx::OnInitDialog();
	int index;
	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	//���ڿؼ��ĳ�ʼ��
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("RoomID"), LVCFMT_CENTER, 60, 0);
	List.InsertColumn(1, _T("NumberOfSeat"), LVCFMT_CENTER, 100, 0);
	List.InsertColumn(2, _T("NumberOfComputer"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(3, _T("NumberOfWhitebash"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(4, _T("NumberOfProject"), LVCFMT_CENTER, 140, 0);
	//������ʼ��
	RoomID = "";
	NumberOfSeat = "";
	NumberOfComputer = "";
	NumberOfWhitebash = "";
	NumberOfProject = "";
	//���ݿ����ӳ�ʼ��
	CString DSNname = _T("DSN=BuildingManager");
	Record = new CRecordset(&DB);
	if (DB.OpenEx(DSNname, 0)){
		if (Record->Open(CRecordset::dynaset, _T("select * from detailofroom7"), CRecordset::none)){
			MessageBox(_T("�ɹ��������ݿ⽨������"));
		}
		else{
			MessageBox(_T("û�м�������"));
		}
	}
	else{
		MessageBox(_T("���ݿ�����ʧ��"));
	}
	

	


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void ROOM::OnBnClickedButton1()
{
	UpdateData();			//�ӿؼ��������ݵ�����
	
	int index;			//����һ���б��ؼ���������Ǳ���
	//�Ӽ�¼���������ݵ����ر���
	Record->MoveFirst();				//ȷ����¼��ָ���һ����¼

	for (index = 0; !(Record->IsEOF()); index++){			//����ѭ����  ����¼�������ݵ�ʱ��isEOF����Ϊ0��������ǰ����ϣ����Ա�֤ѭ��
		Record->GetFieldValue((short)0, RoomID);			//�Ӽ�¼����ȡ���ݵ�����
		Record->GetFieldValue((short)1, NumberOfSeat);
		Record->GetFieldValue((short)2, NumberOfComputer);
		Record->GetFieldValue((short)3, NumberOfWhitebash);
		Record->GetFieldValue((short)4, NumberOfProject);
		Record->MoveNext();							//��¼���ƶ�����һ��
		//������
		index = List.GetItemCount();//�Ա�����г�ʼ��
		LV_ITEM lvitem;
		lvitem.iItem = index;
		lvitem.mask = LVFIF_TEXT;
		lvitem.iSubItem = 0;
		lvitem.pszText = (LPWSTR)(char *)(LPCTSTR)RoomID;
		//����һ��
		List.InsertItem(&lvitem);				//����һ�У�
		List.SetItemText(index, 0, RoomID);				//���������ĸ����ϣ��������
		List.SetItemText(index, 1, NumberOfSeat);
		List.SetItemText(index, 2, NumberOfComputer);
		List.SetItemText(index, 3, NumberOfWhitebash);
		List.SetItemText(index, 4, NumberOfProject);
	}

	UpdateData(false);				//�������ݵ��ؼ�
}

void ROOM::OnBnClickedButton2()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
}


void ROOM::OnBnClickedButton3()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
}