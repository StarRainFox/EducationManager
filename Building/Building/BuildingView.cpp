
// BuildingView.cpp : CBuildingView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Building.h"
#endif

#include "BuildingSet.h"
#include "BuildingDoc.h"
#include "BuildingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBuildingView

IMPLEMENT_DYNCREATE(CBuildingView, CRecordView)

BEGIN_MESSAGE_MAP(CBuildingView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CBuildingView ����/����

CBuildingView::CBuildingView()
	: CRecordView(CBuildingView::IDD)
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CBuildingView::~CBuildingView()
{
}

void CBuildingView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
}

BOOL CBuildingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CBuildingView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_BuildingSet;
	CRecordView::OnInitialUpdate();

}


// CBuildingView ��ӡ

BOOL CBuildingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBuildingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CBuildingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CBuildingView ���

#ifdef _DEBUG
void CBuildingView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CBuildingView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CBuildingDoc* CBuildingView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBuildingDoc)));
	return (CBuildingDoc*)m_pDocument;
}
#endif //_DEBUG


// CBuildingView ���ݿ�֧��
CRecordset* CBuildingView::OnGetRecordset()
{
	return m_pSet;
}



// CBuildingView ��Ϣ�������
