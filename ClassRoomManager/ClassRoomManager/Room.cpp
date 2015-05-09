// Room.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "ClassRoomManagerSet.h"
#include "Room.h"
#include "afxdialogex.h"


// Room �Ի���

IMPLEMENT_DYNAMIC(Room, CDialogEx)

Room::Room(CWnd* pParent /*=NULL*/)
	: CDialogEx(Room::IDD, pParent)
	, broad(0)
	, computer(0)
	, ID(0)
	, project(0)
	, seat(0)
{

}

Room::~Room()
{
}

void Room::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
	DDX_Text(pDX, IDC_EDIT_broad, broad);
	DDX_Text(pDX, IDC_EDIT_computer, computer);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_project, project);
	DDX_Text(pDX, IDC_EDIT_seat, seat);
}


BEGIN_MESSAGE_MAP(Room, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_contect, &Room::OnBnClickedButtoncontect)
	ON_BN_CLICKED(IDC_BUTTON_insert, &Room::OnBnClickedButtoninsert)
	ON_BN_CLICKED(IDC_BUTTON_delete, &Room::OnBnClickedButtondelete)
END_MESSAGE_MAP()


// Room ��Ϣ��������


BOOL Room::OnInitDialog()				//��ʼ�����麯��
{
	CDialogEx::OnInitDialog();
	//���ڱ������г�ʼ����ֵ
	RoomID = "";
	NumberOfSeat = "";
	NumberOfComputer = "";
	NumberOfWhitebash = "";
	NumberOfProject = "";
	//���ڿؼ��ĳ�ʼ��
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("RoomID"), LVCFMT_CENTER, 80, 0);
	List.InsertColumn(1, _T("NumberOfSeat"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(2, _T("NumberOfComputer"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(3, _T("NumberOfWhitebash"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(4, _T("NumberOfProject"), LVCFMT_CENTER, 160, 0);
	//�����ݿ�������ӣ����Ҵ򿪱����ǵļ�¼����Ϊ��̬�ģ�
	CString DSNname = _T("DSN=BuildingManager");
	Record = new CClassRoomManagerSet(&DB);
	if (DB.OpenEx(DSNname, 0)){
		if (Record->Open(CRecordset::dynaset, _T("select * from detailofroom"), CRecordset::none)){
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


void Room::OnBnClickedButtoncontect()
{
	UpdateData();			//�ӿؼ��������ݵ�����

	int index = 0;			//����һ���б��ؼ���������Ǳ���
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
		LV_ITEM lvitem;		// �����еı���
		index = List.GetItemCount();//��ȡ��ǰ����
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
		//�������ݣ�����ѭ��ʱ������ݻ���ʹ��
		RoomID = "";
		NumberOfSeat = "";
		NumberOfComputer = "";
		NumberOfWhitebash = "";
		NumberOfProject = "";
	}

	UpdateData(false);				//�������ݵ��ؼ�
}


void Room::OnBnClickedButtoninsert()		//���밴ť����Ӧ����
{
	UpdateData();

	Record->MoveLast();		//�ö�̬��¼��ָ���һ����¼
	Record->AddNew();		//����һ���µļ�¼
	Record->m_RoomID = ID;			//Ϊ�¼�¼�ı�����ֵ
	Record->m_NumberOfComputer = computer;		
	Record->m_NumberOfSeat = seat;
	Record->m_NumberOfWhitebash = broad;
	Record->m_NumberOfProject = project;
	Record->Update();		//ˢ�¼�¼
	Record->Requery();		
	List.DeleteAllItems();			//ɾ���б��ؼ��ڵ�������
	OnBnClickedButtoncontect();		//���°����ݴӱ��õ��б�

	UpdateData(false);
}


void Room::OnBnClickedButtondelete()
{
	UpdateData();

	long Row;
	POSITION pos = List.GetFirstSelectedItemPosition();
	while (pos){
		Row = List.GetNextSelectedItem(pos);			//��ȡ��ǰ�����������
	}
	Record->MoveFirst();			//���ȵ����¼������
	for (int i = 1; i <= Row; i++){			//һֱ�ƶ���������Ӧ��λ��
		Record->MoveNext();
	}
	Record->Delete();			//ɾ����¼  
	Record->Requery();			
	List.DeleteAllItems();		//ɾ��������
	OnBnClickedButtoncontect();			//������ȡ����

	UpdateData(false);
}