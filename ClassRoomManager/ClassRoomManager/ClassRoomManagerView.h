
// ClassRoomManagerView.h : CClassRoomManagerView ��Ľӿ�
//

#pragma once

class CClassRoomManagerSet;

class CClassRoomManagerView : public CRecordView
{
protected: // �������л�����
	CClassRoomManagerView();
	DECLARE_DYNCREATE(CClassRoomManagerView)

public:
	enum{ IDD = IDD_CLASSROOMMANAGER_FORM };
	CClassRoomManagerSet* m_pSet;

// ����
public:
	CClassRoomManagerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CClassRoomManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ClassRoomManagerView.cpp �еĵ��԰汾
inline CClassRoomManagerDoc* CClassRoomManagerView::GetDocument() const
   { return reinterpret_cast<CClassRoomManagerDoc*>(m_pDocument); }
#endif

