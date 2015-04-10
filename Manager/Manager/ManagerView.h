
// ManagerView.h : CManagerView 类的接口
//

#pragma once

class CManagerSet;

class CManagerView : public CRecordView
{
protected: // 仅从序列化创建
	CManagerView();
	DECLARE_DYNCREATE(CManagerView)

public:
	enum{ IDD = IDD_MANAGER_FORM };
	CManagerSet* m_pSet;

// 特性
public:
	CManagerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ManagerView.cpp 中的调试版本
inline CManagerDoc* CManagerView::GetDocument() const
   { return reinterpret_cast<CManagerDoc*>(m_pDocument); }
#endif

