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
	, broad(_T(""))
	, computer(_T(""))
	, ID(_T(""))
	, project(_T(""))
	, seat(_T(""))
{			//�ؼ��ĳ�ʼ����Ҫд�������������󱻴���ʱ�����ڻ�û�д�������̸�ؼ���
	//������ʼ��
	RoomID = "";
	NumberOfSeat = "";
	NumberOfComputer = "";
	NumberOfWhitebash = "";
	NumberOfProject = "";
}

ROOM::~ROOM()
{
}

void ROOM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
	DDX_Text(pDX, IDC_EDIT_broad, broad);
	DDX_Text(pDX, IDC_EDIT_computer, computer);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_project, project);
	DDX_Text(pDX, IDC_EDIT_seat, seat);
}

BEGIN_MESSAGE_MAP(ROOM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ROOM::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ROOM::OnBnClickedButton2)

	ON_NOTIFY(NM_CLICK, IDC_LIST1, &ROOM::OnClickList1)
END_MESSAGE_MAP()

// ROOM ��Ϣ�������

BOOL ROOM::OnInitDialog()				//��д�Ĵ��ڳ�ʼ�����������������дһЩ�ؼ��ĳ�ʼ��
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ڿؼ��ĳ�ʼ��
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("RoomID"), LVCFMT_CENTER, 60, 0);
	List.InsertColumn(1, _T("NumberOfSeat"), LVCFMT_CENTER, 100, 0);
	List.InsertColumn(2, _T("NumberOfComputer"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(3, _T("NumberOfWhitebash"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(4, _T("NumberOfProject"), LVCFMT_CENTER, 140, 0);
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
	
	int index;			//����һ���б�ؼ���������Ǳ���
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
		//��������
		RoomID = "";
		NumberOfSeat = "";
		NumberOfComputer = "";
		NumberOfWhitebash = "";
		NumberOfProject = "";
	}

	UpdateData(false);				//�������ݵ��ؼ�
}

void ROOM::OnBnClickedButton2()
{
	UpdateData();
	



	Record->Requery();

	UpdateData(false);
}
/*
CString exec=_T("INSERT INTO ");
CString tablename;
tablename=Record->GetTableName();
exec = exec + tablename + _T(" VALUE(\'") + ID + _T("\',\'") + seat + _T("\',\'") + computer + _T("\',\'") + broad + _T("\',\'") + project + _T("\')");
//	MessageBox(exec);
//	DB.ExecuteSQL(exec);
DB.ExecuteSQL(_T(" insert into [DetailOfRoom7] VALUE( ) "));

*/





void ROOM::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	//��ȡ�������
	POSITION pos = List.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("��û��ѡ���κ�item"));
	}
	else{
		while (pos)
		{
			int line = List.GetNextSelectedItem(pos);
		}
	}

	


	*pResult = 0;
	UpdateData(false);
}
