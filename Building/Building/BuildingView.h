
// BuildingView.h : CBuildingView ��Ľӿ�
//

#pragma once

class CBuildingSet;

class CBuildingView : public CRecordView
{
protected: // �������л�����
	CBuildingView();
	DECLARE_DYNCREATE(CBuildingView)

public:
	enum{ IDD = IDD_BUILDING_FORM };
	CBuildingSet* m_pSet;

// ����
public:
	CBuildingDoc* GetDocument() const;

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
	virtual ~CBuildingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // BuildingView.cpp �еĵ��԰汾
inline CBuildingDoc* CBuildingView::GetDocument() const
   { return reinterpret_cast<CBuildingDoc*>(m_pDocument); }
#endif

