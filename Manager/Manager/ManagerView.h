
// ManagerView.h : CManagerView ��Ľӿ�
//

#pragma once

class CManagerSet;

class CManagerView : public CRecordView
{
protected: // �������л�����
	CManagerView();
	DECLARE_DYNCREATE(CManagerView)

public:
	enum{ IDD = IDD_MANAGER_FORM };
	CManagerSet* m_pSet;

// ����
public:
	CManagerDoc* GetDocument() const;

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
	virtual ~CManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ManagerView.cpp �еĵ��԰汾
inline CManagerDoc* CManagerView::GetDocument() const
   { return reinterpret_cast<CManagerDoc*>(m_pDocument); }
#endif

