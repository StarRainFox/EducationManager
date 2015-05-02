
// BuildingDoc.h : CBuildingDoc ��Ľӿ�
//


#pragma once
#include "BuildingSet.h"


class CBuildingDoc : public CDocument
{
protected: // �������л�����
	CBuildingDoc();
	DECLARE_DYNCREATE(CBuildingDoc)

// ����
public:
	CBuildingSet m_BuildingSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CBuildingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
