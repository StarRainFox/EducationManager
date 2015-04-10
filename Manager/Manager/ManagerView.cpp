
// ManagerView.cpp : CManagerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Manager.h"
#endif

#include "ManagerSet.h"
#include "ManagerDoc.h"
#include "ManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerView

IMPLEMENT_DYNCREATE(CManagerView, CRecordView)

BEGIN_MESSAGE_MAP(CManagerView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CManagerView ����/����

CManagerView::CManagerView()
	: CRecordView(CManagerView::IDD)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CManagerView::~CManagerView()
{
}

void CManagerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
}

BOOL CManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CManagerView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ManagerSet;
	CRecordView::OnInitialUpdate();

}


// CManagerView ��ӡ

BOOL CManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CManagerView ���

#ifdef _DEBUG
void CManagerView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CManagerView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CManagerDoc* CManagerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CManagerDoc)));
	return (CManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CManagerView ���ݿ�֧��
CRecordset* CManagerView::OnGetRecordset()
{
	return m_pSet;
}



// CManagerView ��Ϣ�������
